/*
 * Button.c
 *
 *  Created on: Nov 19, 2020
 *      Author: dangv
 */
#include "Button.h"

TS_BUTTON_Data   vrts_BUTTON_OnOff;
TS_BUTTON_Data   vrts_BUTTON_Sence1;
TS_BUTTON_Data   vrts_BUTTON_Sence2;
TS_BUTTON_Data   vrts_BUTTON_Sence3;
TS_BUTTON_Data   vrts_BUTTON_Sence4;
TS_BUTTON_Data   vrts_BUTTON_Sence5;
//uint8_t       Time_outex;

void BUTTON_Scan(Button Button_Check)
{
	// check Button ON/OFF
	if((Button_Check == Button_OnOff) || (Button_Check == Button_All))
	{
		BUTTON_Scan_Bt_OnOff();
	}
	// check Button Sence1
	if((Button_Check == Button_Sence1) || (Button_Check == Button_All))
	{
		BUTTON_Scan_Bt_Sence1();
	}
	// check Button Sence2
	if((Button_Check == Button_Sence2) || (Button_Check == Button_All))
	{
		BUTTON_Scan_Bt_Sence2( );
	}
	// check Button Sence3
	if((Button_Check == Button_Sence3) || (Button_Check == Button_All))
	{
		BUTTON_Scan_Bt_Sence3();
	}

	// check Button Sence4
	if((Button_Check == Button_Sence4) || (Button_Check == Button_All))
	{
		BUTTON_Scan_Bt_Sence4();
	}

	// check Button Sence5
	if((Button_Check == Button_Sence5) || (Button_Check == Button_All))
	{
		BUTTON_Scan_Bt_Sence5();
	}
}
void BUTTON_Scan_Bt_OnOff(void)
{
    if(!STT_BT_0)
    {
        if(vrts_BUTTON_OnOff.vruc_Count <= BUTTON_COUNTSWITCH)
        {
        	vrts_BUTTON_OnOff.vruc_Count++;
        }
        if(vrts_BUTTON_OnOff.vruc_Count == BUTTON_COUNTSWITCH)
        {
        	vrts_BUTTON_OnOff.vruc_Flag = 1;
//        	uart_CSend("Line62\n");
//        	if(Time_outex <= TIMEOUT_COUNTSWITCH)
//        	{
//        		vrts_BUTTON_OnOff.vruc_Flag = 2;
//        	}
//        	else vrts_BUTTON_OnOff.vruc_Flag = 1;
        	//Time_outex=0;
        }

    }
    else
    {

//		uart_CSend("Line76\n");
//    	if(test<=100) test++;
//		char UART_TempSend[128];
//		sprintf(UART_TempSend,"BT.timeou: %d, BBt_Flag: %d, Vruc_Count: %d\n", Time_outex,vrts_BUTTON_OnOff.vruc_Flag, test);
//		uart_CSend(UART_TempSend);
//    	if((Time_outex) >= 81)
//    	{
//
//    		if(vrts_BUTTON_OnOff.vruc_Flag == 1)
//    		{
//    			//uart_CSend("Line82\n");
//    			vrts_BUTTON_OnOff.vruc_Flag = 3;
//    		}
//    		Time_outex ++;
//    	}
//    //	Time_outex ++;
//    	if(Time_outex <= 90)
//    	{
//
//    		Time_outex ++;
//    	}
    	vrts_BUTTON_OnOff.vruc_Count = 0;
    }
}

void BUTTON_Scan_Bt_Sence1(void){
    if(!STT_BT_1)
    {
        if(vrts_BUTTON_Sence1.vruc_Count <= BUTTON_COUNTSWITCH)
        {
        	vrts_BUTTON_Sence1.vruc_Count++;
        }
        if(vrts_BUTTON_Sence1.vruc_Count == BUTTON_COUNTSWITCH)
        {
        	vrts_BUTTON_Sence1.vruc_Flag = 1;
        }
    }
    else
    {
    	vrts_BUTTON_Sence1.vruc_Count = 0;
    }
}

void BUTTON_Scan_Bt_Sence2(void){
    if(!STT_BT_2)
    {
        if(vrts_BUTTON_Sence2.vruc_Count <= BUTTON_COUNTSWITCH)
        {
        	vrts_BUTTON_Sence2.vruc_Count++;
        }
        if(vrts_BUTTON_Sence2.vruc_Count == BUTTON_COUNTSWITCH)
        {
        	vrts_BUTTON_Sence2.vruc_Flag = 1;
        }
    }
    else
    {
    	vrts_BUTTON_Sence2.vruc_Count = 0;
    }
}

void BUTTON_Scan_Bt_Sence3(void){
    if(!STT_BT_3)
    {
        if(vrts_BUTTON_Sence3.vruc_Count <= BUTTON_COUNTSWITCH)
        {
        	vrts_BUTTON_Sence3.vruc_Count++;
        }
        if(vrts_BUTTON_Sence3.vruc_Count == BUTTON_COUNTSWITCH)
        {
        	vrts_BUTTON_Sence3.vruc_Flag = 1;
        }
    }
    else
    {
    	vrts_BUTTON_Sence3.vruc_Count = 0;
    }
}

void BUTTON_Scan_Bt_Sence4(void){
    if(!STT_BT_4)
    {
        if(vrts_BUTTON_Sence4.vruc_Count <= BUTTON_COUNTSWITCH)
        {
        	vrts_BUTTON_Sence4.vruc_Count++;
        }
        if(vrts_BUTTON_Sence4.vruc_Count == BUTTON_COUNTSWITCH)
        {
        	vrts_BUTTON_Sence4.vruc_Flag = 1;
        }
    }
    else
    {
    	vrts_BUTTON_Sence4.vruc_Count = 0;
    }
}

void BUTTON_Scan_Bt_Sence5(void){
    if(!STT_BT_5)
    {
        if(vrts_BUTTON_Sence5.vruc_Count <= BUTTON_COUNTSWITCH)
        {
        	vrts_BUTTON_Sence5.vruc_Count++;
        }
        if(vrts_BUTTON_Sence5.vruc_Count == BUTTON_COUNTSWITCH)
        {
        	vrts_BUTTON_Sence5.vruc_Flag = 1;
        }
    }
    else
    {
    	vrts_BUTTON_Sence5.vruc_Count = 0;
    }
}


void Fn_BUTTON_ScanInTimer (void){
//    Fn_BUTTON_ScanButton1();
//    Fn_BUTTON_ScanButton2();
//    Fn_BUTTON_ScanButton3();
//    Fn_BUTTON_ScanButton4();
}
void Button_Test()
{

}
