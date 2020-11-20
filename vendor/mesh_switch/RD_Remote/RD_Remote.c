/*
 * RD_Remote.c
 *
 *  Created on: Nov 19, 2020
 *      Author: dangv
 */

#include "RD_Remote.h"
uint8_t count_Sence1;
void RD_Button_ConfigWakeup(){
	gpio_set_wakeup (WAKEUP_PIN, 0, 1);
	gpio_core_wakeup_enable_all (1);
	cpu_set_gpio_wakeup (WAKEUP_PIN, 0, 1);
}
void RD_Button_Init(void){
	gpio_setup_up_down_resistor(LED_R,PM_PIN_PULLUP_1M);
	gpio_set_func(LED_R,AS_GPIO);
	gpio_set_output_en(LED_R,1);
	gpio_write(LED_R,1);
	rf_link_light_event_callback(LGT_CMD_SWITCH_POWERON);
	//LED 2
	gpio_setup_up_down_resistor(LED_B,PM_PIN_PULLUP_1M);
	gpio_set_func(LED_B,AS_GPIO);
	gpio_set_output_en(LED_B,1);
	gpio_write(LED_B,1);
	//button config
	gpio_set_func(btnOnOff ,AS_GPIO);	gpio_set_output_en(btnOnOff, 0);	gpio_set_input_en(btnOnOff ,1); gpio_setup_up_down_resistor(btnOnOff, PM_PIN_PULLUP_1M);
	gpio_set_func(btnScene1 ,AS_GPIO);	gpio_set_output_en(btnScene1, 0);	gpio_set_input_en(btnScene1 ,1); gpio_setup_up_down_resistor(btnScene1, PM_PIN_PULLUP_1M);
	gpio_set_func(btnScene2 ,AS_GPIO);	gpio_set_output_en(btnScene2, 0);	gpio_set_input_en(btnScene2 ,1); gpio_setup_up_down_resistor(btnScene2, PM_PIN_PULLUP_1M);
	gpio_set_func(btnScene3 ,AS_GPIO);	gpio_set_output_en(btnScene3, 0);	gpio_set_input_en(btnScene3 ,1); gpio_setup_up_down_resistor(btnScene3, PM_PIN_PULLUP_1M);
	gpio_set_func(btnScene4 ,AS_GPIO);	gpio_set_output_en(btnScene4, 0);	gpio_set_input_en(btnScene4 ,1); gpio_setup_up_down_resistor(btnScene4, PM_PIN_PULLUP_1M);
	gpio_set_func(btnScene5 ,AS_GPIO);	gpio_set_output_en(btnScene5, 0);	gpio_set_input_en(btnScene5 ,1); gpio_setup_up_down_resistor(btnScene5, PM_PIN_PULLUP_1M);

	//rc_mag.kb_pressed = 1;
	//button_ProvFlag = 0;
}

void Remote_Rp_BT(void)
{
	if(vrts_BUTTON_OnOff.vruc_Flag == 1)
	{
		uart_CSend("Button_OK:On\n");
		vrts_BUTTON_OnOff.vruc_Flag =0;
	}

	if(vrts_BUTTON_OnOff.vruc_Flag == 2)
	{
		uart_CSend("Button_OK:double\n");
		vrts_BUTTON_OnOff.vruc_Flag =0;
	}
	if(vrts_BUTTON_Sence1.vruc_Flag == 1)
	{
//		count_Sence1= count_Sence1+2;
//		char UART_TempSend[128];
//		sprintf(UART_TempSend,"BT.Sence: %d \n", count_Sence1 );
//		uart_CSend(UART_TempSend);
		uart_CSend("Button_Sence1:On\n");
		vrts_BUTTON_Sence1.vruc_Flag =0;
	}

	if(vrts_BUTTON_Sence2.vruc_Flag == 1)
	{
//		char UART_TempSend[128];
//		sprintf(UART_TempSend,"BT.Sence: %d \n", count_Sence1 );
//		uart_CSend(UART_TempSend);
		uart_CSend("Button_Sence2:On\n");
		vrts_BUTTON_Sence2.vruc_Flag =0;
	}

	if(vrts_BUTTON_Sence3.vruc_Flag == 1)
	{
		uart_CSend("Button_Sence3:On\n");
		vrts_BUTTON_Sence3.vruc_Flag =0;
	}

	if(vrts_BUTTON_Sence4.vruc_Flag == 1)
	{
		uart_CSend("Button_Sence4:On\n");
		vrts_BUTTON_Sence4.vruc_Flag =0;
	}

	if(vrts_BUTTON_Sence5.vruc_Flag == 1)
	{
		uart_CSend("Button_Sence5:On\n");
		vrts_BUTTON_Sence5.vruc_Flag =0;
	}
}
