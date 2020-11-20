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


void RD_Button_ConfigWakeup();
void RD_Button_Init(void);
void Remote_Rp_BT(void);
#endif /* RD_REMOTE_H_ */
