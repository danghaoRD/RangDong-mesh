/*
 * RD_Remote.h
 *
 *  Created on: Nov 19, 2020
 *      Author: dangv
 */

#ifndef RD_REMOTE_H_
#define RD_REMOTE_H_
#include "proj/tl_common.h"
#include "proj/mcu/watchdog_i.h"
#include "vendor/common/user_config.h"
#include "proj_lib/rf_drv.h"
#include "proj_lib/pm.h"
#include "proj_lib/ble/blt_config.h"
#include "proj_lib/ble/ll/ll.h"
#include "proj_lib/sig_mesh/app_mesh.h"

#include "../Button/Button.h"
#include "../RD_Mess_Data/RD_Mess_Data.h"
#include "../RD_Flash/RD_Flash.h"
#define TIME_TO_SLEEP 1000
#define ADC_BATT_PIN   GPIO_PB1
#define TYPE_LED_BLINK_NULL 0
#define TYPE_LED_BLINK_RED  1
#define TYPE_LED_BLINK_BLUE 2
#define TYPE_LED_BLINK_RED_AND_BLUE 3
extern uint16_t Time2Sleep;
uint8_t type_Led_Blink ;
int check;
//void RD_Button_ConfigWakeup();

void RD_Remote_Init(void);
//void Remote_Rp_BT_All(void);
void RD_Remote_ADC_Init();
void RD_Remote_Led_Check_Unprov();
void RD_Remote_Check_And_Sleep(uint16_t time_goto_sleep);
void RD_Remote_Sleep();
void RD_Remote_Print_Mess();
void RD_Remote_Rp_BT(u8 Button_Rp );
void RD_Remote_Led(u8 type_led, u32 led_even);
void RD_Remote_SendButtonID2GW(u8 Button, u8 modePress, u16 Sence);
#endif /* RD_REMOTE_H_ */
