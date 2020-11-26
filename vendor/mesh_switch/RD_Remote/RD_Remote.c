/*
 * RD_Remote.c
 *
 *  Created on: Nov 19, 2020
 *      Author: dangv
 */

#include "RD_Remote.h"
uint8_t count_Sence1;

void RD_Remote_Init(void){
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
	gpio_set_func(btnOnOff  ,AS_GPIO);	gpio_set_output_en(btnOnOff,  0);	gpio_set_input_en(btnOnOff  ,1); gpio_setup_up_down_resistor(btnOnOff, PM_PIN_PULLUP_1M);
	gpio_set_func(btnScene1 ,AS_GPIO);	gpio_set_output_en(btnScene1, 0);	gpio_set_input_en(btnScene1 ,1); gpio_setup_up_down_resistor(btnScene1, PM_PIN_PULLUP_1M);
	gpio_set_func(btnScene2 ,AS_GPIO);	gpio_set_output_en(btnScene2, 0);	gpio_set_input_en(btnScene2 ,1); gpio_setup_up_down_resistor(btnScene2, PM_PIN_PULLUP_1M);
	gpio_set_func(btnScene3 ,AS_GPIO);	gpio_set_output_en(btnScene3, 0);	gpio_set_input_en(btnScene3 ,1); gpio_setup_up_down_resistor(btnScene3, PM_PIN_PULLUP_1M);
	gpio_set_func(btnScene4 ,AS_GPIO);	gpio_set_output_en(btnScene4, 0);	gpio_set_input_en(btnScene4 ,1); gpio_setup_up_down_resistor(btnScene4, PM_PIN_PULLUP_1M);
	gpio_set_func(btnScene5 ,AS_GPIO);	gpio_set_output_en(btnScene5, 0);	gpio_set_input_en(btnScene5 ,1); gpio_setup_up_down_resistor(btnScene5, PM_PIN_PULLUP_1M);

	//rc_mag.kb_pressed = 1;
	//button_ProvFlag = 0;
}
/*
void Remote_Rp_BT_All(void)
{
 	if(vrts_BUTTON_OnOff.vruc_Flag == One_Press)
	{
		uart_CSend("Button_OK:On\n");
		vrts_BUTTON_OnOff.vruc_Flag = Null_Press;
	}
	if(vrts_BUTTON_OnOff.vruc_Flag == Double_Press)
	{
		uart_CSend("Button_OK:double\n");
		vrts_BUTTON_OnOff.vruc_Flag =Null_Press;
	}*/
/*
	static char UART_TempSend[128];
	// nut an ok
	switch (vrts_BUTTON_OnOff.vruc_Flag) {
		case One_Press:
			uart_CSend("Button_OK:On\n");
			// truyen ban tin
			RD_Config_Data_Remote(Button_OnOff, vrts_BUTTON_OnOff.vruc_Flag, 0x0115);
			RD_Messenger_TempSend = (unsigned char *)(&RD_Config_Data);
			RD_Messenger_SendNode2Gateway(RD_Messenger_TempSend,8);
			sprintf(UART_TempSend,"RD_Config_Data: %2x %2x %2x %2x %2x %2x %2x %2x \n",  RD_Config_Data.Header[0], RD_Config_Data.Header[1], 	\
					RD_Config_Data.BID, RD_Config_Data.ModeID, RD_Config_Data.SenceID[0], RD_Config_Data.SenceID[1],\
					RD_Config_Data.Future[0], RD_Config_Data.Future[0] );
			uart_CSend(UART_TempSend);

			vrts_BUTTON_OnOff.vruc_Flag = Null_Press;
			break;
		case Double_Press:
			uart_CSend("Button_OK:double\n");
			RD_Config_Data_Remote(Button_OnOff, vrts_BUTTON_OnOff.vruc_Flag, 0x0115);
			RD_Messenger_TempSend = (unsigned char *)(&RD_Config_Data);
			RD_Messenger_SendNode2Gateway(RD_Messenger_TempSend,8);
			//uart_CSend(&RD_Config_Data);
			sprintf(UART_TempSend,"RD_Config_Data: %2x %2x %2x %2x %2x %2x %2x %2x \n",  RD_Config_Data.Header[0], RD_Config_Data.Header[1], 	\
					RD_Config_Data.BID, RD_Config_Data.ModeID, RD_Config_Data.SenceID[0], RD_Config_Data.SenceID[1],\
					RD_Config_Data.Future[0], RD_Config_Data.Future[0] );
			uart_CSend(UART_TempSend);
			vrts_BUTTON_OnOff.vruc_Flag =Null_Press;
			break;
		case Hold_Press:
			uart_CSend("Button_OK:Hould\n");
			RD_Config_Data_Remote(Button_OnOff, vrts_BUTTON_OnOff.vruc_Flag, 0x0115);
			RD_Messenger_TempSend = (unsigned char *)(&RD_Config_Data);
			RD_Messenger_SendNode2Gateway(RD_Messenger_TempSend,8);
		//	uart_CSend(&RD_Config_Data);
			sprintf(UART_TempSend,"RD_Config_Data: %2x %2x %2x %2x %2x %2x %2x %2x \n",  RD_Config_Data.Header[0], RD_Config_Data.Header[1], 	\
					RD_Config_Data.BID, RD_Config_Data.ModeID, RD_Config_Data.SenceID[0], RD_Config_Data.SenceID[1],\
					RD_Config_Data.Future[0], RD_Config_Data.Future[0] );
			uart_CSend(UART_TempSend);

//			while( !STT_BT_5)
//			{}

			vrts_BUTTON_OnOff.vruc_Flag =Null_Press;
			break;
		default:
			break;
	}


	if(vrts_BUTTON_Sence1.vruc_Flag == 1)
	{
//		count_Sence1= count_Sence1+2;
//		char UART_TempSend[128];
// 		sprintf(UART_TempSend,"BT.Sence: %d \n", count_Sence1 );
//		uart_CSend(UART_TempSend);
		uart_CSend("Button_Sence1:On\n");

		RD_Config_Data_Remote(Button_Sence1, vrts_BUTTON_Sence1.vruc_Flag, 0x02);
		RD_Messenger_TempSend = (unsigned char *)(&RD_Config_Data);
		RD_Messenger_SendNode2Gateway(RD_Messenger_TempSend,8);
		sprintf(UART_TempSend,"RD_Config_Data_BT 1: %2x %2x %2x %2x %2x %2x %2x %2x \n",  RD_Config_Data.Header[0], RD_Config_Data.Header[1], 	\
				RD_Config_Data.BID, RD_Config_Data.ModeID, RD_Config_Data.SenceID[0], RD_Config_Data.SenceID[1],\
				RD_Config_Data.Future[0], RD_Config_Data.Future[0] );
		uart_CSend(UART_TempSend);

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
		if(!rc_mag.adv_send_enable){
			uart_CSend("Button_Sence5:Provison \n");
							rf_link_light_event_callback(LGT_CMD_SWITCH_PROVISION);
							rc_mag.adv_send_enable =1;
							rc_mag.adv_send_tick = clock_time();
							rc_mag.adv_timeout_def_ms = 60;//60s
		}
		vrts_BUTTON_Sence5.vruc_Flag =0;
	}
}
*/
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
	if( (Button_Rp == Button_OnOff) || (Button_Rp == Button_All) )
	{
		// nut an ok
		switch (vrts_BUTTON_OnOff.vruc_Flag)
		{
			case One_Press:
				uart_CSend("Button_OK:On\n");
				// truyen ban tin
				RD_Config_Data_Remote(Button_OnOff, vrts_BUTTON_OnOff.vruc_Flag, 0x0115);
				RD_Messenger_TempSend = (unsigned char *)(&RD_Config_Data);
				RD_Messenger_SendNode2Gateway(RD_Messenger_TempSend,8);

				RD_Remote_Print_Mess();

				vrts_BUTTON_OnOff.vruc_Flag = Null_Press;
				break;
			case Double_Press:
				uart_CSend("Button_OK:double\n");
				RD_Config_Data_Remote(Button_OnOff, vrts_BUTTON_OnOff.vruc_Flag, 0x0115);
				RD_Messenger_TempSend = (unsigned char *)(&RD_Config_Data);
				RD_Messenger_SendNode2Gateway(RD_Messenger_TempSend,8);
				//uart_CSend(&RD_Config_Data);
				RD_Remote_Print_Mess();

				vrts_BUTTON_OnOff.vruc_Flag =Null_Press;
				break;
			case Hold_Press:
				uart_CSend("Button_OK:Hould\n");
				RD_Config_Data_Remote(Button_OnOff, vrts_BUTTON_OnOff.vruc_Flag, 0x0115);
				RD_Messenger_TempSend = (unsigned char *)(&RD_Config_Data);
				RD_Messenger_SendNode2Gateway(RD_Messenger_TempSend,8);
			//	uart_CSend(&RD_Config_Data);
				RD_Remote_Print_Mess();

	//			while( !STT_BT_5)
	//			{}

				vrts_BUTTON_OnOff.vruc_Flag =Null_Press;
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
					uart_CSend("Button_Sence_1:On\n");
					// truyen ban tin
					RD_Config_Data_Remote(Button_Sence1, vrts_BUTTON_Sence1.vruc_Flag, 0x0115);
					RD_Messenger_TempSend = (unsigned char *)(&RD_Config_Data);
					RD_Messenger_SendNode2Gateway(RD_Messenger_TempSend,8);

					RD_Remote_Print_Mess();

					vrts_BUTTON_Sence1.vruc_Flag = Null_Press;
					break;
				case Double_Press:
					uart_CSend("Button_Sence_1:double\n");
					RD_Config_Data_Remote(Button_Sence1, vrts_BUTTON_Sence1.vruc_Flag, 0x0115);
					RD_Messenger_TempSend = (unsigned char *)(&RD_Config_Data);
					RD_Messenger_SendNode2Gateway(RD_Messenger_TempSend,8);
					//uart_CSend(&RD_Config_Data);
					RD_Remote_Print_Mess();

					vrts_BUTTON_Sence1.vruc_Flag =Null_Press;
					break;
				case Hold_Press:
					uart_CSend("Button_Sence_1:Hould\n");
					RD_Config_Data_Remote(Button_Sence1, vrts_BUTTON_Sence1.vruc_Flag, 0x0115);
					RD_Messenger_TempSend = (unsigned char *)(&RD_Config_Data);
					RD_Messenger_SendNode2Gateway(RD_Messenger_TempSend,8);
				//	uart_CSend(&RD_Config_Data);
					RD_Remote_Print_Mess();

		//			while( !STT_BT_5)
		//			{}

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
					// truyen ban tin
					RD_Config_Data_Remote(Button_Sence2, vrts_BUTTON_Sence2.vruc_Flag, 0x0115);
					RD_Messenger_TempSend = (unsigned char *)(&RD_Config_Data);
					RD_Messenger_SendNode2Gateway(RD_Messenger_TempSend,8);

					RD_Remote_Print_Mess();

					vrts_BUTTON_Sence2.vruc_Flag = Null_Press;
					break;
				case Double_Press:
					uart_CSend("Button_Sence_2:double\n");
					RD_Config_Data_Remote(Button_OnOff, vrts_BUTTON_Sence2.vruc_Flag, 0x0115);
					RD_Messenger_TempSend = (unsigned char *)(&RD_Config_Data);
					RD_Messenger_SendNode2Gateway(RD_Messenger_TempSend,8);
					//uart_CSend(&RD_Config_Data);
					RD_Remote_Print_Mess();

					vrts_BUTTON_Sence2.vruc_Flag =Null_Press;
					break;
				case Hold_Press:
					uart_CSend("Button_Sence_2:Hould\n");
					RD_Config_Data_Remote(Button_OnOff, vrts_BUTTON_Sence2.vruc_Flag, 0x0115);
					RD_Messenger_TempSend = (unsigned char *)(&RD_Config_Data);
					RD_Messenger_SendNode2Gateway(RD_Messenger_TempSend,8);
				//	uart_CSend(&RD_Config_Data);
					RD_Remote_Print_Mess();

		//			while( !STT_BT_5)
		//			{}

					vrts_BUTTON_Sence1.vruc_Flag =Null_Press;
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
					// truyen ban tin
					RD_Config_Data_Remote(Button_Sence3, vrts_BUTTON_Sence3.vruc_Flag, 0x0115);
					RD_Messenger_TempSend = (unsigned char *)(&RD_Config_Data);
					RD_Messenger_SendNode2Gateway(RD_Messenger_TempSend,8);

					RD_Remote_Print_Mess();

					vrts_BUTTON_Sence3.vruc_Flag = Null_Press;
					break;
				case Double_Press:
					uart_CSend("Button_Sence_3:double\n");
					RD_Config_Data_Remote(Button_OnOff, vrts_BUTTON_Sence3.vruc_Flag, 0x0115);
					RD_Messenger_TempSend = (unsigned char *)(&RD_Config_Data);
					RD_Messenger_SendNode2Gateway(RD_Messenger_TempSend,8);
					//uart_CSend(&RD_Config_Data);
					RD_Remote_Print_Mess();

					vrts_BUTTON_Sence3.vruc_Flag =Null_Press;
					break;
				case Hold_Press:
					uart_CSend("Button_Sence_3:Hould\n");
					RD_Config_Data_Remote(Button_OnOff, vrts_BUTTON_Sence3.vruc_Flag, 0x0115);
					RD_Messenger_TempSend = (unsigned char *)(&RD_Config_Data);
					RD_Messenger_SendNode2Gateway(RD_Messenger_TempSend,8);
				//	uart_CSend(&RD_Config_Data);
					RD_Remote_Print_Mess();

		//			while( !STT_BT_5)
		//			{}

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
					// truyen ban tin
					RD_Config_Data_Remote(Button_Sence4, vrts_BUTTON_Sence4.vruc_Flag, 0x0115);
					RD_Messenger_TempSend = (unsigned char *)(&RD_Config_Data);
					RD_Messenger_SendNode2Gateway(RD_Messenger_TempSend,8);

					RD_Remote_Print_Mess();

					vrts_BUTTON_Sence4.vruc_Flag = Null_Press;
					break;
				case Double_Press:
					uart_CSend("Button_Sence_4:double\n");
					RD_Config_Data_Remote(Button_OnOff, vrts_BUTTON_Sence4.vruc_Flag, 0x0115);
					RD_Messenger_TempSend = (unsigned char *)(&RD_Config_Data);
					RD_Messenger_SendNode2Gateway(RD_Messenger_TempSend,8);
					//uart_CSend(&RD_Config_Data);
					RD_Remote_Print_Mess();

					vrts_BUTTON_Sence4.vruc_Flag =Null_Press;
					break;
				case Hold_Press:
					uart_CSend("Button_Sence_4:Hould\n");
					RD_Config_Data_Remote(Button_OnOff, vrts_BUTTON_Sence4.vruc_Flag, 0x0115);
					RD_Messenger_TempSend = (unsigned char *)(&RD_Config_Data);
					RD_Messenger_SendNode2Gateway(RD_Messenger_TempSend,8);
				//	uart_CSend(&RD_Config_Data);
					RD_Remote_Print_Mess();

		//			while( !STT_BT_5)
		//			{}

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
					// truyen ban tin
					RD_Config_Data_Remote(Button_Sence5, vrts_BUTTON_Sence5.vruc_Flag, 0x0115);
					RD_Messenger_TempSend = (unsigned char *)(&RD_Config_Data);
					RD_Messenger_SendNode2Gateway(RD_Messenger_TempSend,8);

					RD_Remote_Print_Mess();

					vrts_BUTTON_Sence5.vruc_Flag = Null_Press;
					break;
				case Double_Press:
					uart_CSend("Button_Sence_5:double\n");
					RD_Config_Data_Remote(Button_OnOff, vrts_BUTTON_Sence5.vruc_Flag, 0x0115);
					RD_Messenger_TempSend = (unsigned char *)(&RD_Config_Data);
					RD_Messenger_SendNode2Gateway(RD_Messenger_TempSend,8);
					//uart_CSend(&RD_Config_Data);
					RD_Remote_Print_Mess();

					vrts_BUTTON_Sence5.vruc_Flag =Null_Press;
					break;
				case Hold_Press:
					uart_CSend("Button_Sence_5:Hould\n");
					RD_Config_Data_Remote(Button_OnOff, vrts_BUTTON_Sence5.vruc_Flag, 0x0115);
					RD_Messenger_TempSend = (unsigned char *)(&RD_Config_Data);
					RD_Messenger_SendNode2Gateway(RD_Messenger_TempSend,8);
				//	uart_CSend(&RD_Config_Data);
					RD_Remote_Print_Mess();

		//			while( !STT_BT_5)
		//			{}

					vrts_BUTTON_Sence5.vruc_Flag =Null_Press;
					break;
				default:
					break;
			}
		}


}
