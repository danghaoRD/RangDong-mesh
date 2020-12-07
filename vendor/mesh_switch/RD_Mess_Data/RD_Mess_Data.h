/*
 * RD_Mess_Data.h
 *
 *  Created on: Nov 24, 2020
 *      Author: RUY TUNG
 */

#ifndef RD_MESS_DATA_H_
#define RD_MESS_DATA_H_

#include "proj/common/types.h"
#include "proj/tl_common.h"
#include "proj/mcu/watchdog_i.h"
#include "vendor/common/user_config.h"
#include "proj_lib/rf_drv.h"
#include "proj_lib/pm.h"
#include "proj_lib/ble/blt_config.h"
#include "proj_lib/ble/ll/ll.h"
#include "proj_lib/sig_mesh/app_mesh.h"

#include "../Button/Button.h"
#include "../RD_Remote/RD_Remote.h"
#include "../RD_Flash/RD_Flash.h"
#define RD_OPCODE_SEND		(0xA082)
#define RD_OPCODE_RSP		(0xA182)
#define RD_MAXRESPONESEND (2)
#define RD_GATEWAYADDRESS (0x0001)
#define REMOTE_DC_MODULE_TYPE				0x0002
#define REMOTE_AC_MODULE_TYPE				0x0003
typedef struct{
	unsigned char Header[2];
	unsigned char BID;
	unsigned char ModeID;
	unsigned char SenceID[2];
	unsigned char Future[2];
}RD_Config_DataRemote;
extern RD_Config_DataRemote RD_Config_Data;
extern unsigned char 		*RD_Messenger_TempSend;

//#define mesh_cmd_sig_RD_respone_status      (0)


extern void RD_Config_Data_Remote(u8 _Button, u8 _Mode, u16 _SenceID);
int mesh_cmd_sig_RD_respone_status (u8 *par, int par_len, mesh_cb_fun_par_t *cb_par);
int RD_Messenger_ProcessCommingProcess (u8 *par, int par_len, mesh_cb_fun_par_t *cb_par);
int RD_Mess_ProcessCommingProcess (u8 *par, int par_len, mesh_cb_fun_par_t *cb_par);
void RD_Messenger_CustomSendSTT(u8 *Mess, u32 _MessLength, u16 adr_dst);
void RD_Messenger_SendNode2Gateway (u8 *Mess, u32 _MessLength);
void RD_Send_Mess(void);

//void RD_Messenger_SendBroadcast (u8 *Mess, u32 _MessLength);
//void RD_Messenger_CustomSendCtrl(u8 *Mess, u32 _MessLength, u16 adr_dst);

//void RD_Config_Data_Remote(TypeButton _Button, Type_Press _Mode, u16   _SenceID);


#endif /* RD_MESS_DATA_H_ */
