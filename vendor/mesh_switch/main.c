/********************************************************************************************************
 * @file     main.c 
 *
 * @brief    for TLSR chips
 *
 * @author	 telink
 * @date     Sep. 30, 2010
 *
 * @par      Copyright (c) 2010, Telink Semiconductor (Shanghai) Co., Ltd.
 *           All rights reserved.
 *           
 *			 The information contained herein is confidential and proprietary property of Telink 
 * 		     Semiconductor (Shanghai) Co., Ltd. and is available under the terms 
 *			 of Commercial License Agreement between Telink Semiconductor (Shanghai) 
 *			 Co., Ltd. and the licensee in separate contract or the terms described here-in. 
 *           This heading MUST NOT be removed from this file.
 *
 * 			 Licensees are granted free, non-transferable use of the information in this 
 *			 file under Mutual Non-Disclosure Agreement. NO WARRENTY of ANY KIND is provided. 
 *           
 *******************************************************************************************************/
#include "proj/tl_common.h"
#include "proj/mcu/watchdog_i.h"
#include "vendor/common/user_config.h"
#include "proj_lib/rf_drv.h"
#include "proj_lib/pm.h"
#include "proj_lib/ble/blt_config.h"
#include "proj_lib/ble/ll/ll.h"
#include "proj_lib/sig_mesh/app_mesh.h"

#include "RD_Remote/RD_Remote.h"
#include "Button/Button.h"
#include "RD_Mess_Data/RD_Mess_Data.h"
#include "RD_Flash/RD_Flash.h"
extern void user_init();
extern void main_loop ();
uint16_t timecheck_ADC=0;
uint16_t time_sleep=0;

void Test_Main();

void Test_Loop();

#if (HCI_ACCESS==HCI_USE_UART)
#include "proj/drivers/uart.h"
extern my_fifo_t hci_rx_fifo;

u16 uart_tx_irq=0, uart_rx_irq=0;

_attribute_ram_code_ void irq_uart_handle()
{
	unsigned char irqS = reg_dma_rx_rdy0;
	if(irqS & FLD_DMA_CHN_UART_RX)	//rx
	{
		uart_rx_irq++;
		reg_dma_rx_rdy0 = FLD_DMA_CHN_UART_RX;
		u8* w = hci_rx_fifo.p + (hci_rx_fifo.wptr & (hci_rx_fifo.num-1)) * hci_rx_fifo.size;
		if(w[0]!=0)
		{
			my_fifo_next(&hci_rx_fifo);
			u8* p = hci_rx_fifo.p + (hci_rx_fifo.wptr & (hci_rx_fifo.num-1)) * hci_rx_fifo.size;
			reg_dma0_addr = (u16)((u32)p);
		}
	}

	if(irqS & FLD_DMA_CHN_UART_TX)	//tx
	{
		uart_tx_irq++;
		reg_dma_rx_rdy0 = FLD_DMA_CHN_UART_TX;
	}
}
#endif

_attribute_ram_code_ void irq_handler(void)
{
	#if DUAL_MODE_ADAPT_EN
	if(rf_mode == RF_MODE_ZIGBEE){
		irq_zigbee_sdk_handler();
	}else
	#endif
	{
		irq_blt_sdk_handler ();  //ble irq proc
	}

#if (HCI_ACCESS==HCI_USE_UART)
	irq_uart_handle();
#endif
}

FLASH_ADDRESS_DEFINE;
#if(MCU_CORE_TYPE == MCU_CORE_8269)
int main (void) {
	FLASH_ADDRESS_CONFIG;
	cpu_wakeup_init();

	clock_init();
	set_tick_per_us(CLOCK_SYS_CLOCK_HZ/1000000);

	gpio_init();

	rf_drv_init(CRYSTAL_TYPE);

	user_init ();

    irq_enable();

	while (1) {
#if (MODULE_WATCHDOG_ENABLE)
		wd_clear(); //clear watch dog
#endif
		main_loop ();
	}
}
#elif((MCU_CORE_TYPE == MCU_CORE_8258) || (MCU_CORE_TYPE == MCU_CORE_8278))
_attribute_ram_code_ int main (void)    //must run in ramcode
{
	FLASH_ADDRESS_CONFIG;
	blc_pm_select_internal_32k_crystal();
#if(MCU_CORE_TYPE == MCU_CORE_8258)
	cpu_wakeup_init();
#elif(MCU_CORE_TYPE == MCU_CORE_8278)
	cpu_wakeup_init(LDO_MODE,EXTERNAL_XTAL_24M);
#endif

	int deepRetWakeUp = pm_is_MCU_deepRetentionWakeup();  //MCU deep retention wakeUp

	rf_drv_init(RF_MODE_BLE_1M);

	gpio_init( !deepRetWakeUp );  //analog resistance will keep available in deepSleep mode, so no need initialize again

#if (CLOCK_SYS_CLOCK_HZ == 16000000)
	clock_init(SYS_CLK_16M_Crystal);
#elif (CLOCK_SYS_CLOCK_HZ == 24000000)
	clock_init(SYS_CLK_24M_Crystal);
#elif (CLOCK_SYS_CLOCK_HZ == 32000000)
	clock_init(SYS_CLK_32M_Crystal);
#elif (CLOCK_SYS_CLOCK_HZ == 48000000)
	clock_init(SYS_CLK_48M_Crystal);
#endif


#if	(PM_DEEPSLEEP_RETENTION_ENABLE)
		if( pm_is_MCU_deepRetentionWakeup() ){
			user_init_deepRetn ();
		}
		else
#endif
	{
		user_init();
	}


    irq_enable();
	#if (MESH_USER_DEFINE_MODE == MESH_IRONMAN_MENLO_ENABLE)
	LOG_USER_MSG_INFO(0, 0,"[mesh] Start from SIG Mesh", 0);
	#endif
	RD_Button_ConfigWakeup();
	 RD_Remote_Init();
	 RD_Remote_ADC_Init();
	uart_CSend("Wakeup:\n");
	Test_Main();
	while (1) {
#if (MODULE_WATCHDOG_ENABLE)
		wd_clear(); //clear watch dog
#endif
		main_loop ();
//		flash_read_page(FLASH_ADDR, 4096,Buff_Flash);


		sleep_ms(1);

		BUTTON_Scan(Button_All);
		RD_Remote_Check_And_Sleep(1000);
		RD_Remote_Rp_BT(Button_All);

		Test_Loop();
	}
}

void Test_Main()
{
	gpio_write(LED_R,1);
	gpio_write(LED_B,1);
/*   for(int i=0; i<FLASH_BUFF_LEN; i++)
   {
	   Buff_Flash_Write[i]=0xff;
   }
   Buff_Flash_Write[2] = 0x32;
   Buff_Flash_Write[3] = 0x32;
   Buff_Flash_Write[4] = 0x43;
   	flash_erase_sector(FLASH_ADDR);
	flash_write_page(FLASH_ADDR, FLASH_BUFF_LEN,Buff_Flash_Write );
	flash_read_page(FLASH_ADDR, FLASH_BUFF_LEN,Buff_Flash_Read);
	uart_CSend("0x");
	int u=0;
	for(int i =0; i < FLASH_BUFF_LEN;i++){
		if(Buff_Flash_Read[i] != 255){
			uart_CSend("dellok");
			 u++;
		}
	}
	if(u ==0) uart_CSend("okvaicalon");*/
	//uart_CSend((char *) Buff_Flash);
//	uint8_t data[2]={0x12, 0x55};
//	Save_Change_SenceID_2_Flash(Button_OnOff, One_Press,data );
//	Buff_Flash_Read[0] = 0x14;
//	Buff_Flash_Read[1] = 0x33;
//  	RD_Flash_Get_Sence_ID(Button_OnOff, One_Press);

	  RD_Flash_Init();
//  access_cmd_scene_recall(0xffff, u32 rsp_max, 0x0002, 0, transition_par_t *trs_par)
//	Get_Sence_ID(Button_OnOff, 0x01);
}
void Test_Loop()
{
	timecheck_ADC ++;
	if(timecheck_ADC>=1000)
	{

		//cfg_led_event(LED_EVENT_FLASH_4HZ_3T);
		RD_Remote_Led(TYPE_LED_BLINK_BLUE, LED_EVENT_FLASH_4HZ_3T);
		RD_Remote_Check_And_Sleep(TIME_TO_SLEEP);
		timecheck_ADC=0;
		uint16_t adc_bat = adc_sample_and_get_result();
		//mesh_cmd_sig_g_battery_get()
		static char UART_TempSend[128];
		sprintf(UART_TempSend,"ADC_Data: %d   \n",adc_bat  );
		uart_CSend(UART_TempSend);
	}
}
#endif
