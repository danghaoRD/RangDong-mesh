/*
 * Button.h
 *
 *  Created on: Nov 19, 2020
 *      Author: dangv
 */

#ifndef BUTTON_H_
#define BUTTON_H_
#include "proj/tl_common.h"
#include "proj/mcu/watchdog_i.h"
#include "vendor/common/user_config.h"
#include "proj_lib/rf_drv.h"
#include "proj_lib/pm.h"
#include "proj_lib/ble/blt_config.h"
#include "proj_lib/ble/ll/ll.h"
#include "proj_lib/sig_mesh/app_mesh.h"

#include "../RD_Remote/RD_Remote.h"




 #define btnOnOff	GPIO_PC1	//Key0
 #define btnScene1	GPIO_PB4	//key1
 #define btnScene2	GPIO_PB5	//key2
 #define btnScene3	GPIO_PB6	//key3
 #define btnScene4	GPIO_PB7	//key4
 #define btnScene5	GPIO_PC0	//key5

#define STT_BT_0      gpio_read(btnOnOff)
#define STT_BT_1      gpio_read(btnScene1)
#define STT_BT_2      gpio_read(btnScene2)
#define STT_BT_3      gpio_read(btnScene3)
#define STT_BT_4      gpio_read(btnScene4)
#define STT_BT_5      gpio_read(btnScene5)


#define SPEAK_COUNT  (1000)


#define BUTTON_COUNTSWITCH      (20)
#define BUTTON_COUNTSWITCHLONG  (500)
#define TIMEOUT_COUNTSWITCH		(30)

typedef struct {
    unsigned char       vruc_Flag;
    unsigned char       vruc_ValueOld;
    unsigned int        vruc_Count;
    unsigned char       vruc_FlagFirst;
    unsigned char       Time_out;
}       TS_BUTTON_Data;
  uint8_t       Time_outex;
  uint8_t       test;
typedef enum{
	Button_Null,
	Button_OnOff,
	Button_Sence1,
	Button_Sence2,
	Button_Sence3,
	Button_Sence4,
	Button_Sence5,
	Button_All,
}Button;

extern TS_BUTTON_Data   vrts_BUTTON_OnOff;
extern TS_BUTTON_Data   vrts_BUTTON_Sence1;
extern TS_BUTTON_Data   vrts_BUTTON_Sence2;
extern TS_BUTTON_Data   vrts_BUTTON_Sence3;
extern TS_BUTTON_Data   vrts_BUTTON_Sence4;
extern TS_BUTTON_Data   vrts_BUTTON_Sence5;

//void Fn_BUTTON_ScanButton1      (void);
//void Fn_BUTTON_ScanButton2      (void);
//void Fn_BUTTON_ScanButton3      (void);
//void Fn_BUTTON_ScanButton4      (void);
//void Fn_BUTTON_ScanInTimer      (void);
void Fn_BUTTON_ClearFlag        (void);

void BUTTON_Scan(Button Button_Check);
void BUTTON_Scan_Bt_OnOff(void);
void BUTTON_Scan_Bt_Sence1(void);
void BUTTON_Scan_Bt_Sence2(void);
void BUTTON_Scan_Bt_Sence3(void);
void BUTTON_Scan_Bt_Sence4(void);
void BUTTON_Scan_Bt_Sence5(void);
void Button_Test();
#endif /* BUTTON_H_ */
