/*
 * RD_Remote.c
 *
 *  Created on: Nov 19, 2020
 *      Author: dangv
 */

#include "RD_Remote.h"
uint8_t count_Sence1;
uint16_t Time2Sleep;

void RD_Remote_Init(void){
	gpio_setup_up_down_resistor(LED_R,PM_PIN_PULLUP_1M);
	gpio_set_func(LED_R,AS_GPIO);
	gpio_set_input_en(LED_R, 0);
	gpio_set_output_en(LED_R,1);
	gpio_write(LED_R,0);
	rf_link_light_event_callback(LGT_CMD_SWITCH_POWERON);
	//LED 2
	gpio_setup_up_down_resistor(LED_B,PM_PIN_PULLUP_1M);
	gpio_set_func(LED_B,AS_GPIO);
	gpio_set_input_en(LED_B,0);
	gpio_set_output_en(LED_B,1);
	gpio_write(LED_B,0);
	//button config
	gpio_set_func(btnOnOff  ,AS_GPIO);	gpio_set_output_en(btnOnOff,  0);	gpio_set_input_en(btnOnOff  ,1); gpio_setup_up_down_resistor(btnOnOff, PM_PIN_PULLUP_1M);
	gpio_set_func(btnScene1 ,AS_GPIO);	gpio_set_output_en(btnScene1, 0);	gpio_set_input_en(btnScene1 ,1); gpio_setup_up_down_resistor(btnScene1, PM_PIN_PULLUP_1M);
	gpio_set_func(btnScene2 ,AS_GPIO);	gpio_set_output_en(btnScene2, 0);	gpio_set_input_en(btnScene2 ,1); gpio_setup_up_down_resistor(btnScene2, PM_PIN_PULLUP_1M);
	gpio_set_func(btnScene3 ,AS_GPIO);	gpio_set_output_en(btnScene3, 0);	gpio_set_input_en(btnScene3 ,1); gpio_setup_up_down_resistor(btnScene3, PM_PIN_PULLUP_1M);
	gpio_set_func(btnScene4 ,AS_GPIO);	gpio_set_output_en(btnScene4, 0);	gpio_set_input_en(btnScene4 ,1); gpio_setup_up_down_resistor(btnScene4, PM_PIN_PULLUP_1M);
	gpio_set_func(btnScene5 ,AS_GPIO);	gpio_set_output_en(btnScene5, 0);	gpio_set_input_en(btnScene5 ,1); gpio_setup_up_down_resistor(btnScene5, PM_PIN_PULLUP_1M);

	//rc_mag.kb_pressed = 1;
	//button_ProvFlag = 0;
}
void RD_Remote_Led_Check_Unprov()
{
	// RD_EDIT Set Provision
		if(get_provision_state() == STATE_DEV_UNPROV)
		{
			if(!rc_mag.adv_send_enable)
			{
				RD_Remote_Led(TYPE_LED_BLINK_RED, LED_EVENT_FLASH_4HZ_2T);
			}
		}

}
void RD_Remote_Sleep()
{
	int sleep_mode = DEEPSLEEP_MODE;
	usb_dp_pullup_en (0);
	cpu_sleep_wakeup(sleep_mode, PM_WAKEUP_PAD, 0);
}
void RD_Remote_Check_And_Sleep(uint16_t time_goto_sleep)
{
	if(get_provision_state() == STATE_DEV_UNPROV)
	{
		time_goto_sleep = 3000;
		//RD_Remote_Led(TYPE_LED_BLINK_BLUE, LED_EVENT_FLASH_4HZ_3T);
	}
	else if(get_provision_state() == STATE_DEV_PROVING)
	{

		Time2Sleep =0;
		RD_Remote_Led(TYPE_LED_BLINK_BLUE, LED_EVENT_FLASH_4HZ_3T);
	}
	if((vrts_BUTTON_OnOff.vruc_Flag) | (vrts_BUTTON_Sence1.vruc_Flag) | (vrts_BUTTON_Sence2.vruc_Flag) \
			| (vrts_BUTTON_Sence3.vruc_Flag)| (vrts_BUTTON_Sence4.vruc_Flag)| (vrts_BUTTON_Sence5.vruc_Flag))
	{
		Time2Sleep =0;
	}
	else
	{
		Time2Sleep++;
	}

	if(Time2Sleep>= time_goto_sleep)
	{

		uart_CSend("goto Sleep\n");
		sleep_ms(1);
		RD_Remote_Sleep();
	}
}
void RD_Remote_SendButtonID2GW(u8 Button, u8 modePress, u16 Sence)
{
	RD_Config_Data_Remote(Button, modePress, Sence);
	RD_Messenger_TempSend = (unsigned char *)(&RD_Config_Data);
	RD_Messenger_SendNode2Gateway(RD_Messenger_TempSend,8);
	RD_Remote_Print_Mess();
}
void RD_Remote_Print_Mess()
{
	static char UART_TempSend[128];
	sprintf(UART_TempSend,"RD_Config_Data: %2x %2x %2x %2x %2x %2x %2x %2x \n",  RD_Config_Data.Header[0], RD_Config_Data.Header[1], 	\
			RD_Config_Data.BID, RD_Config_Data.ModeID, RD_Config_Data.SenceID[0], RD_Config_Data.SenceID[1],\
			RD_Config_Data.Future[0], RD_Config_Data.Future[0] );
	uart_CSend(UART_TempSend);
}
void RD_Remote_Rp_BT(TypeButton Button_Rp )
{
	uint16_t checkSenceID;
	if( (Button_Rp == Button_OnOff) || (Button_Rp == Button_All) )
	{
		// nut an ok
		switch (vrts_BUTTON_OnOff.vruc_Flag)
		{
			case One_Press:
				uart_CSend("Button_OK:On\n");
				// kiem tra nut da luu canh chua
				  checkSenceID = RD_Flash_Get_Sence_ID(Button_OnOff, One_Press);
				  checkSenceID = 0x0002;
				if(checkSenceID == 0x0000) // neu co canh luu thi gui Sence
				{
					RD_Remote_SendButtonID2GW(Button_OnOff, vrts_BUTTON_OnOff.vruc_Flag, 0x0000);
				}
				else    					// neu chua co canh luu thi gui ButtonID
				{
					// ham gui canh
					access_cmd_scene_recall(0xffff, 0, checkSenceID, CMD_NO_ACK, 3);
					uart_CSend("Send SENCE_ID By ButttonOn/Off One Press: \n");
				}
				vrts_BUTTON_OnOff.vruc_Flag = Null_Press;
				break;
			case Double_Press:
				uart_CSend("Button_OK:double\n");
				// kiem tra nut da luu canh chua
				  checkSenceID = RD_Flash_Get_Sence_ID(Button_OnOff, Double_Press);
				  checkSenceID = 0x0003;
				if(checkSenceID == 0x0000) // neu co canh luu thi gui Sence
				{
					RD_Remote_SendButtonID2GW(Button_OnOff, vrts_BUTTON_OnOff.vruc_Flag, 0x0000);
				}
				else    					// neu chua co canh luu thi gui ButtonID
				{
					access_cmd_scene_recall(0xffff, 0, checkSenceID, CMD_NO_ACK, 3);
					uart_CSend("Send SENCE_ID By ButttonOn/Off Double_Press  : \n");
					// ham gui canh
				}
				vrts_BUTTON_OnOff.vruc_Flag =Null_Press;
				break;
			case Hold_Press:
				//uart_CSend("Button_OK:Hould\n");


	//			while( !STT_BT_5)
	//			{}

			//	vrts_BUTTON_OnOff.vruc_Flag =Null_Press;
				break;
			default:
				break;
		}
	}
	// Nut 1
	if( (Button_Rp == Button_Sence1) || (Button_Rp == Button_All) )
		{
			// nut an ok
			switch (vrts_BUTTON_Sence1.vruc_Flag)
			{
				case One_Press:
					// kiem tra nut da luu canh chua
					  checkSenceID = RD_Flash_Get_Sence_ID(Button_Sence1, One_Press);

					if(checkSenceID == 0x0000) // neu co canh luu thi gui Sence
					{
						RD_Remote_SendButtonID2GW(Button_Sence1, vrts_BUTTON_Sence1.vruc_Flag, 0x0000);
					}
					else    					// neu chua co canh luu thi gui ButtonID
					{
						// ham gui canh
						access_cmd_scene_recall(0xffff, 0, checkSenceID, CMD_NO_ACK, 3);
						uart_CSend("Send SENCE_ID By ButttonSecce1 One_Press  : \n");
					}

					vrts_BUTTON_Sence1.vruc_Flag = Null_Press;
					break;
				case Double_Press:
					uart_CSend("Button_Sence_1:double\n");
					// kiem tra nut da luu canh chua
					  checkSenceID = RD_Flash_Get_Sence_ID(Button_Sence1, Double_Press);

					if(checkSenceID == 0x0000) // neu co canh luu thi gui Sence
					{
						RD_Remote_SendButtonID2GW(Button_Sence1, vrts_BUTTON_Sence1.vruc_Flag, 0x0000);
					}
					else    					// neu chua co canh luu thi gui ButtonID
					{
						// ham gui canh
						access_cmd_scene_recall(0xffff, 0, checkSenceID, CMD_NO_ACK, 3);
						uart_CSend("Send SENCE_ID By ButttonSecce1 Double_Press  : \n");
					}

					vrts_BUTTON_Sence1.vruc_Flag =Null_Press;
					break;
				case Hold_Press:
					uart_CSend("Button_Sence_1:Hould\n");

					vrts_BUTTON_Sence1.vruc_Flag =Null_Press;
					break;
				default:
					break;
			}
		}
	// Button 2
	if( (Button_Rp == Button_Sence2) || (Button_Rp == Button_All) )
		{
			// nut an ok
			switch (vrts_BUTTON_Sence2.vruc_Flag)
			{
				case One_Press:
					uart_CSend("Button_Sence_2:On\n");
					// kiem tra nut da luu canh chua
					  checkSenceID = RD_Flash_Get_Sence_ID(Button_Sence2, One_Press);

					if(checkSenceID == 0x0000) // neu co canh luu thi gui Sence
					{
						RD_Remote_SendButtonID2GW(Button_Sence2, vrts_BUTTON_Sence2.vruc_Flag, 0x0000);
					}
					else    					// neu chua co canh luu thi gui ButtonID
					{
						// ham gui canh
						access_cmd_scene_recall(0xffff, 0, checkSenceID, CMD_NO_ACK, 3);
						uart_CSend("Send SENCE_ID By ButttonSecce2 One_Press  : \n");
					}
					vrts_BUTTON_Sence2.vruc_Flag = Null_Press;
					break;
				case Double_Press:
					uart_CSend("Button_Sence_2:double\n");
					// kiem tra nut da luu canh chua
					  checkSenceID = RD_Flash_Get_Sence_ID(Button_Sence2, Double_Press);

					if(checkSenceID == 0x0000) // neu co canh luu thi gui Sence
					{
						RD_Remote_SendButtonID2GW(Button_Sence2, vrts_BUTTON_Sence2.vruc_Flag, 0x0000);
					}
					else    					// neu chua co canh luu thi gui ButtonID
					{
						// ham gui canh
						access_cmd_scene_recall(0xffff, 0, checkSenceID, CMD_NO_ACK, 3);
						uart_CSend("Send SENCE_ID By ButttonSecce2 Double_Press  : \n");
					}
					if(!STT_BT_3)
					{
						RD_Remote_Led(TYPE_LED_BLINK_RED, LED_EVENT_FLASH_4HZ_3T);
						RD_Flash_CleanSenceFlash();
						sleep_ms(1000);
						factory_reset();
						start_reboot();
					}
					vrts_BUTTON_Sence2.vruc_Flag =Null_Press;
					break;
				case Hold_Press:
					uart_CSend("Button_Sence_2:Hold\n");


					vrts_BUTTON_Sence2.vruc_Flag =Null_Press;
					break;
				default:
					break;
			}
		}

	// Button 3
	if( (Button_Rp == Button_Sence3) || (Button_Rp == Button_All) )
		{
			// nut an ok
			switch (vrts_BUTTON_Sence3.vruc_Flag)
			{
				case One_Press:
					uart_CSend("Button_Sence_3:On\n");
					// kiem tra nut da luu canh chua
					  checkSenceID = RD_Flash_Get_Sence_ID(Button_Sence3, One_Press);

					if(checkSenceID == 0x0000) // neu co canh luu thi gui Sence
					{
						RD_Remote_SendButtonID2GW(Button_Sence3, vrts_BUTTON_Sence3.vruc_Flag, 0x0000);
					}
					else    					// neu chua co canh luu thi gui ButtonID
					{
						// ham gui canh
						access_cmd_scene_recall(0xffff, 0, checkSenceID, CMD_NO_ACK, 3);
						uart_CSend("Send SENCE_ID By ButttonSecce3 One_Press  : \n");
					}
					vrts_BUTTON_Sence3.vruc_Flag = Null_Press;
					break;
				case Double_Press:
					uart_CSend("Button_Sence_3:double\n");
					// kiem tra nut da luu canh chua
					  checkSenceID = RD_Flash_Get_Sence_ID(Button_Sence3, Double_Press);

					if(checkSenceID == 0x0000) // neu co canh luu thi gui Sence
					{
						RD_Remote_SendButtonID2GW(Button_Sence3, vrts_BUTTON_Sence3.vruc_Flag, 0x0000);
					}
					else    					// neu chua co canh luu thi gui ButtonID
					{
						// ham gui canh
						access_cmd_scene_recall(0xffff, 0, checkSenceID, CMD_NO_ACK, 3);
						uart_CSend("Send SENCE_ID By ButttonSecce3 Double_Press  : \n");
					}

					vrts_BUTTON_Sence3.vruc_Flag =Null_Press;
					break;
				case Hold_Press:
					uart_CSend("Button_Sence_3:Hold\n");

 					vrts_BUTTON_Sence3.vruc_Flag =Null_Press;
					break;
				default:
					break;
			}
		}

	// Button 4
	if( (Button_Rp == Button_Sence4) || (Button_Rp == Button_All) )
		{
			// nut an ok
			switch (vrts_BUTTON_Sence4.vruc_Flag)
			{
				case One_Press:
					uart_CSend("Button_Sence_4:On\n");
					// kiem tra nut da luu canh chua
					uint16_t checkSenceID = RD_Flash_Get_Sence_ID(Button_Sence4, One_Press);
					if(checkSenceID == 0x0000) // neu co canh luu thi gui Sence
					{
						RD_Remote_SendButtonID2GW(Button_Sence4, vrts_BUTTON_Sence4.vruc_Flag, 0x0000);
					}
					else    					// neu chua co canh luu thi gui ButtonID
					{
						// ham gui canh
						access_cmd_scene_recall(0xffff, 0, checkSenceID, CMD_NO_ACK, 3);
						uart_CSend("Send SENCE_ID By ButttonSecce4 One_Press  : \n");
					}

					vrts_BUTTON_Sence4.vruc_Flag = Null_Press;
					break;
				case Double_Press:
					uart_CSend("Button_Sence_4:double\n");
					// kiem tra nut da luu canh chua
					  checkSenceID = RD_Flash_Get_Sence_ID(Button_Sence4, Double_Press);
					if(checkSenceID == 0x0000) // neu co canh luu thi gui Sence
					{
						RD_Remote_SendButtonID2GW(Button_Sence4, vrts_BUTTON_Sence4.vruc_Flag, 0x0000);
					}
					else    					// neu chua co canh luu thi gui ButtonID
					{
						// ham gui canh
						access_cmd_scene_recall(0xffff, 0, checkSenceID, CMD_NO_ACK, 3);
						uart_CSend("Send SENCE_ID By ButttonSecce4 Double_Press  : \n");
					}

					vrts_BUTTON_Sence4.vruc_Flag =Null_Press;
					break;
				case Hold_Press:
					uart_CSend("Button_Sence_4:Hould\n");

					vrts_BUTTON_Sence4.vruc_Flag =Null_Press;
					break;
				default:
					break;
			}
		}

	// Button 5
	if( (Button_Rp == Button_Sence5) || (Button_Rp == Button_All) )
		{
			// nut an ok
			switch (vrts_BUTTON_Sence5.vruc_Flag)
			{
				case One_Press:
					uart_CSend("Button_Sence_5:On\n");
					// kiem tra nut da luu canh chua
					uint16_t checkSenceID = RD_Flash_Get_Sence_ID(Button_Sence5, One_Press);
					if(checkSenceID == 0x0000) // neu co canh luu thi gui Sence
					{
						RD_Remote_SendButtonID2GW(Button_Sence5, vrts_BUTTON_Sence5.vruc_Flag, 0x0000);
					}
					else    					// neu chua co canh luu thi gui ButtonID
					{
						// ham gui canh
						access_cmd_scene_recall(0xffff, 0, checkSenceID, CMD_NO_ACK, 2);
						uart_CSend("Send SENCE_ID By ButttonSecce5 One_Press  : \n");
					}

					vrts_BUTTON_Sence5.vruc_Flag = Null_Press;
					break;
				case Double_Press:
					uart_CSend("Button_Sence_5:double\n");
					// kiem tra nut da luu canh chua
					  checkSenceID = RD_Flash_Get_Sence_ID(Button_Sence5, Double_Press);
					if(checkSenceID == 0x0000) // neu co canh luu thi gui Sence
					{
						RD_Remote_SendButtonID2GW(Button_Sence5, vrts_BUTTON_Sence5.vruc_Flag, 0x0000);
					}
					else    					// neu chua co canh luu thi gui ButtonID
					{
						// ham gui canh
						//RD_EDIT: Sence Recall from Flash
						access_cmd_scene_recall(0xffff, 0, checkSenceID, CMD_NO_ACK, 2);
						uart_CSend("Send SENCE_ID By ButttonSecce5 Double_Press  : \n");
					}

					vrts_BUTTON_Sence5.vruc_Flag =Null_Press;
					break;
				case Hold_Press:
					uart_CSend("Button_Sence_5:Hould\n");
					RD_Remote_Led_Check_Unprov();
					vrts_BUTTON_Sence5.vruc_Flag =Null_Press;
					break;
				default:
					break;
			}
		}


}
void RD_Remote_Led(u8 type_led, u32 led_even)
{
	// tye
	type_Led_Blink = type_led;
	cfg_led_event(led_even);
}
void RD_Remote_ADC_Init()
{
	adc_init();
	adc_vbat_init(ADC_BATT_PIN);
	//adc_base_init(ADC_BATT_PIN);
	adc_power_on_sar_adc(1);
}

