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
uint8_t flagHoldButton = 0;
void RD_Button_ConfigWakeup(){
	gpio_set_wakeup (WAKEUP_PIN, 0, 1);
	gpio_core_wakeup_enable_all (1);
	cpu_set_gpio_wakeup (WAKEUP_PIN, 0, 1);
}

void BUTTON_Scan(TypeButton Button_Check)
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
     if(!STT_BT_0)														// phat hien an nut
    {
        if(vrts_BUTTON_OnOff.vruc_Count <= BUTTON_COUNTSWITCHMAX)
        {
        	vrts_BUTTON_OnOff.vruc_Count++;
        }
        // tg an nut = BUTTON_COUNTSWITCH
        if(vrts_BUTTON_OnOff.vruc_Count == BUTTON_COUNTSWITCH)			// tin hieu an nut sau khi chong rung xong
        {
        	if(vrts_BUTTON_OnOff.vruc_Flag == One_Press_Check)			// da an ngay trc do 1 lan
        	{
        		vrts_BUTTON_OnOff.vruc_Flag = Double_Press_Check;		// tam tinh an double
        	}
        	else
        	{
        		vrts_BUTTON_OnOff.vruc_Flag = One_Press_Check;			// tam tinh an lan 1
        	}
        	vrts_BUTTON_OnOff.Time_out =0;
        }

        // tg an nut == BUTTON_COUNTSWITCHMAX
        if(vrts_BUTTON_OnOff.vruc_Count == BUTTON_COUNTSWITCHMAX)
        {
        	vrts_BUTTON_OnOff.vruc_Flag = Hold_Press;                   // an giu
        	flagHoldButton =1;
        	vrts_BUTTON_OnOff.Time_out =0;
        }
    }
    else
    {
    	if(vrts_BUTTON_OnOff.vruc_Flag != Null_Press)					//  trong qua trinh an nut
    	{
    	vrts_BUTTON_OnOff.Time_out++;									// tang time out
    	}

    	if(vrts_BUTTON_OnOff.Time_out >200)								// gan gia tri cho nut
    	{
    		if(vrts_BUTTON_OnOff.vruc_Flag == One_Press_Check)
    		{
    			vrts_BUTTON_OnOff.vruc_Flag = One_Press;				// an 1 lan
    		}
    		if(vrts_BUTTON_OnOff.vruc_Flag == Double_Press_Check)
    		{
    			vrts_BUTTON_OnOff.vruc_Flag =Double_Press;				// an double
    		}
    		vrts_BUTTON_OnOff.Time_out =201;
    	}
    	vrts_BUTTON_OnOff.vruc_Count = 0;

    }




}

void BUTTON_Scan_Bt_Sence1(void){
    if(!STT_BT_1)														// phat hien an nut
   {
       if(vrts_BUTTON_Sence1.vruc_Count <= BUTTON_COUNTSWITCHMAX)
       {
    	   vrts_BUTTON_Sence1.vruc_Count++;
       }
       // tg an nut = BUTTON_COUNTSWITCH
       if(vrts_BUTTON_Sence1.vruc_Count == BUTTON_COUNTSWITCH)			// tin hieu an nut sau khi chong rung xong
       {
       	if(vrts_BUTTON_Sence1.vruc_Flag == One_Press_Check)			// da an ngay trc do 1 lan
       	{
       		vrts_BUTTON_Sence1.vruc_Flag = Double_Press_Check;		// tam tinh an double
       	}
       	else
       	{
       		vrts_BUTTON_Sence1.vruc_Flag = One_Press_Check;			// tam tinh an lan 1
       	}
       	vrts_BUTTON_Sence1.Time_out =0;
       }

       // tg an nut == BUTTON_COUNTSWITCHMAX
       if(vrts_BUTTON_Sence1.vruc_Count == BUTTON_COUNTSWITCHMAX)
       {
    	   vrts_BUTTON_Sence1.vruc_Flag = Hold_Press;                   // an giu
    	   flagHoldButton =1;
    	   vrts_BUTTON_Sence1.Time_out =0;
       }
   }
   else
   {
   	if(vrts_BUTTON_Sence1.vruc_Flag != Null_Press)					//  trong qua trinh an nut
   	{
   		vrts_BUTTON_Sence1.Time_out++;									// tang time out
   	}

   	if(vrts_BUTTON_Sence1.Time_out >200)								// gan gia tri cho nut
   	{
   		if(vrts_BUTTON_Sence1.vruc_Flag == One_Press_Check)
   		{
   			vrts_BUTTON_Sence1.vruc_Flag = One_Press;				// an 1 lan
   		}
   		if(vrts_BUTTON_Sence1.vruc_Flag == Double_Press_Check)
   		{
   			vrts_BUTTON_Sence1.vruc_Flag =Double_Press;				// an double
   		}
   		vrts_BUTTON_Sence1.Time_out =201;
   	}
   	vrts_BUTTON_Sence1.vruc_Count = 0;

   }
}

void BUTTON_Scan_Bt_Sence2(void){
    if(!STT_BT_2)														// phat hien an nut
   {
       if(vrts_BUTTON_Sence2.vruc_Count <= BUTTON_COUNTSWITCHMAX)
       {
    	   vrts_BUTTON_Sence2.vruc_Count++;
       }
       // tg an nut = BUTTON_COUNTSWITCH
       if(vrts_BUTTON_Sence2.vruc_Count == BUTTON_COUNTSWITCH)			// tin hieu an nut sau khi chong rung xong
       {
       	if(vrts_BUTTON_Sence2.vruc_Flag == One_Press_Check)			// da an ngay trc do 1 lan
       	{
       		vrts_BUTTON_Sence2.vruc_Flag = Double_Press_Check;		// tam tinh an double
       	}
       	else
       	{
       		vrts_BUTTON_Sence2.vruc_Flag = One_Press_Check;			// tam tinh an lan 1
       	}
       	vrts_BUTTON_Sence2.Time_out =0;
       }

       // tg an nut == BUTTON_COUNTSWITCHMAX
       if(vrts_BUTTON_Sence2.vruc_Count == BUTTON_COUNTSWITCHMAX)
       {
    	   vrts_BUTTON_Sence2.vruc_Flag = Hold_Press;                   // an giu
    	   flagHoldButton =1;
    	   vrts_BUTTON_Sence2.Time_out =0;
       }
   }
   else
   {
   	if(vrts_BUTTON_Sence2.vruc_Flag != Null_Press)					//  trong qua trinh an nut
   	{
   		vrts_BUTTON_Sence2.Time_out++;									// tang time out
   	}

   	if(vrts_BUTTON_Sence2.Time_out >200)								// gan gia tri cho nut
   	{
   		if(vrts_BUTTON_Sence2.vruc_Flag == One_Press_Check)
   		{
   			vrts_BUTTON_Sence2.vruc_Flag = One_Press;				// an 1 lan
   		}
   		if(vrts_BUTTON_Sence2.vruc_Flag == Double_Press_Check)
   		{
   			vrts_BUTTON_Sence2.vruc_Flag =Double_Press;				// an double
   		}
   		vrts_BUTTON_Sence2.Time_out =201;
   	}
   	vrts_BUTTON_Sence2.vruc_Count = 0;

   }
}

void BUTTON_Scan_Bt_Sence3(void)
{
    if(!STT_BT_3)														// phat hien an nut
   {
       if(vrts_BUTTON_Sence3.vruc_Count <= BUTTON_COUNTSWITCHMAX)
       {
    	   vrts_BUTTON_Sence3.vruc_Count++;
       }
       // tg an nut = BUTTON_COUNTSWITCH
       if(vrts_BUTTON_Sence3.vruc_Count == BUTTON_COUNTSWITCH)			// tin hieu an nut sau khi chong rung xong
       {
       	if(vrts_BUTTON_Sence3.vruc_Flag == One_Press_Check)			// da an ngay trc do 1 lan
       	{
       		vrts_BUTTON_Sence3.vruc_Flag = Double_Press_Check;		// tam tinh an double
       	}
       	else
       	{
       		vrts_BUTTON_Sence3.vruc_Flag = One_Press_Check;			// tam tinh an lan 1
       	}
       	vrts_BUTTON_Sence3.Time_out =0;
       }

       // tg an nut == BUTTON_COUNTSWITCHMAX
       if(vrts_BUTTON_Sence3.vruc_Count == BUTTON_COUNTSWITCHMAX)
       {
    	   vrts_BUTTON_Sence3.vruc_Flag = Hold_Press;                   // an giu
    	   flagHoldButton =1;
    	   vrts_BUTTON_Sence3.Time_out =0;
       }
   }
   else
   {
   	if(vrts_BUTTON_Sence3.vruc_Flag != Null_Press)					//  trong qua trinh an nut
   	{
   		vrts_BUTTON_Sence3.Time_out++;									// tang time out
   	}

   	if(vrts_BUTTON_Sence3.Time_out >200)								// gan gia tri cho nut
   	{
   		if(vrts_BUTTON_Sence3.vruc_Flag == One_Press_Check)
   		{
   			vrts_BUTTON_Sence3.vruc_Flag = One_Press;				// an 1 lan
   		}
   		if(vrts_BUTTON_Sence3.vruc_Flag == Double_Press_Check)
   		{
   			vrts_BUTTON_Sence3.vruc_Flag =Double_Press;				// an double
   		}
   		vrts_BUTTON_Sence3.Time_out =201;
   	}
   	vrts_BUTTON_Sence3.vruc_Count = 0;

   }
}

void BUTTON_Scan_Bt_Sence4(void){
    if(!STT_BT_4)														// phat hien an nut
   {
       if(vrts_BUTTON_Sence4.vruc_Count <= BUTTON_COUNTSWITCHMAX)
       {
    	   vrts_BUTTON_Sence4.vruc_Count++;
       }
       // tg an nut = BUTTON_COUNTSWITCH
       if(vrts_BUTTON_Sence4.vruc_Count == BUTTON_COUNTSWITCH)			// tin hieu an nut sau khi chong rung xong
       {
       	if(vrts_BUTTON_Sence4.vruc_Flag == One_Press_Check)			// da an ngay trc do 1 lan
       	{
       		vrts_BUTTON_Sence4.vruc_Flag = Double_Press_Check;		// tam tinh an double
       	}
       	else
       	{
       		vrts_BUTTON_Sence4.vruc_Flag = One_Press_Check;			// tam tinh an lan 1
       	}
       	vrts_BUTTON_Sence4.Time_out =0;
       }

       // tg an nut == BUTTON_COUNTSWITCHMAX
       if(vrts_BUTTON_Sence4.vruc_Count == BUTTON_COUNTSWITCHMAX)
       {
    	   vrts_BUTTON_Sence4.vruc_Flag = Hold_Press;                   // an giu
    	   flagHoldButton =1;
    	   vrts_BUTTON_Sence4.Time_out =0;
       }
   }
   else
   {
   	if(vrts_BUTTON_Sence4.vruc_Flag != Null_Press)					//  trong qua trinh an nut
   	{
   		vrts_BUTTON_Sence4.Time_out++;									// tang time out
   	}

   	if(vrts_BUTTON_Sence4.Time_out >200)								// gan gia tri cho nut
   	{
   		if(vrts_BUTTON_Sence4.vruc_Flag == One_Press_Check)
   		{
   			vrts_BUTTON_Sence4.vruc_Flag = One_Press;				// an 1 lan
   		}
   		if(vrts_BUTTON_Sence4.vruc_Flag == Double_Press_Check)
   		{
   			vrts_BUTTON_Sence4.vruc_Flag =Double_Press;				// an double
   		}
   		vrts_BUTTON_Sence4.Time_out =201;
   	}
   	vrts_BUTTON_Sence4.vruc_Count = 0;

   }
}

void BUTTON_Scan_Bt_Sence5(void){
    if(!STT_BT_5)														// phat hien an nut
   {
       if(vrts_BUTTON_Sence5.vruc_Count <= BUTTON_COUNTSWITCHMAX)
       {
    	   vrts_BUTTON_Sence5.vruc_Count++;
       }
       // tg an nut = BUTTON_COUNTSWITCH
       if(vrts_BUTTON_Sence5.vruc_Count == BUTTON_COUNTSWITCH)			// tin hieu an nut sau khi chong rung xong
       {
       	if(vrts_BUTTON_Sence5.vruc_Flag == One_Press_Check)			// da an ngay trc do 1 lan
       	{
       		vrts_BUTTON_Sence5.vruc_Flag = Double_Press_Check;		// tam tinh an double
       	}
       	else
       	{
       		vrts_BUTTON_Sence5.vruc_Flag = One_Press_Check;			// tam tinh an lan 1
       	}
       	vrts_BUTTON_Sence5.Time_out =0;
       }

       // tg an nut == BUTTON_COUNTSWITCHMAX
       if(vrts_BUTTON_Sence5.vruc_Count == BUTTON_COUNTSWITCHMAX)
       {
    	   vrts_BUTTON_Sence5.vruc_Flag = Hold_Press;                   // an giu
    	   flagHoldButton =1;
    	   vrts_BUTTON_Sence5.Time_out =0;
       }
   }
   else
   {
   	if(vrts_BUTTON_Sence5.vruc_Flag != Null_Press)					//  trong qua trinh an nut
   	{
   		vrts_BUTTON_Sence5.Time_out++;									// tang time out
   	}

   	if(vrts_BUTTON_Sence5.Time_out >200)								// gan gia tri cho nut
   	{
   		if(vrts_BUTTON_Sence5.vruc_Flag == One_Press_Check)
   		{
   			vrts_BUTTON_Sence5.vruc_Flag = One_Press;				// an 1 lan
   		}
   		if(vrts_BUTTON_Sence5.vruc_Flag == Double_Press_Check)
   		{
   			vrts_BUTTON_Sence5.vruc_Flag =Double_Press;				// an double
   		}
   		vrts_BUTTON_Sence5.Time_out =201;
   	}
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
