/*
 * RD_Mess_Data.c
 *
 *  Created on: Nov 24, 2020
 *      Author: RUY TUNG
 */
#include "RD_Mess_Data.h"

RD_Config_DataRemote 			RD_Config_Data;
unsigned char 					*RD_Messenger_TempSend;

void RD_Config_Data_Remote(TypeButton _Button, Type_Press _Mode, u16   _SenceID){
	RD_Config_Data.Header[0] 	 	 =  (uint8_t) (REMOTE_DC_MODULE_TYPE & 0xff);
	RD_Config_Data.Header[1] 	 	 =  (uint8_t) ((REMOTE_DC_MODULE_TYPE>>8) & 0xff);
	RD_Config_Data.BID 				 = _Button;
	RD_Config_Data.ModeID	    	 = _Mode;
	RD_Config_Data.SenceID[0] 		 = (_SenceID>>8)&0xff;
	RD_Config_Data.SenceID[1]		 =  _SenceID&0xff;
	RD_Config_Data.Future[0]		 = 0x00;
	RD_Config_Data.Future[0]		 = 0x00;
}

void RD_Messenger_CustomSendSTT(u8 *Mess, u32 _MessLength, u16 adr_dst){
	mesh_tx_cmd2normal_primary(SENSOR_STATUS, Mess, _MessLength, adr_dst, RD_MAXRESPONESEND);
}

void RD_Messenger_SendNode2Gateway (u8 *Mess, u32 _MessLength){
	RD_Messenger_CustomSendSTT(Mess, _MessLength, RD_GATEWAYADDRESS);
}

void RD_Send_Mess(void){
	RD_Messenger_TempSend = (unsigned char *)(&RD_Config_Data);
	RD_Messenger_SendNode2Gateway(RD_Messenger_TempSend,8);
}
/*
 * use #define RD_OPCODE_SEND		(0xA082)
	   #define RD_OPCODE_RSP		(0xA182)
 *
 *
 */
//void RD_Messenger_CustomSendCtrl(u8 *Mess, u32 _MessLength, u16 adr_dst){
//	mesh_tx_cmd2normal_primary(RD_OPCODE_SEND, Mess, _MessLength, adr_dst, RD_MAXRESPONESEND);
//}
//void RD_Messenger_SendBroadcast (u8 *Mess, u32 _MessLength){
//	RD_Messenger_CustomSendCtrl(Mess, _MessLength, RD_BROADCASTADDRESS);
//}
