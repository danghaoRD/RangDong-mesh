/*
 * RD_Mess_Data.c
 *
 *  Created on: Nov 24, 2020
 *      Author: RUY TUNG
 */
#include "RD_Mess_Data.h"

RD_Config_DataRemote 			RD_Config_Data;
unsigned char 					*RD_Messenger_TempSend;
unsigned char vr_RD_ProvDone;
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
int RD_Mess_ProcessCommingProcess (u8 *par, int par_len, mesh_cb_fun_par_t *cb_par)
{
	uart_CSend("Co Ban Tin\n");
	if(flagHoldButton == 1)
	{
		flagHoldButton = 0;
	RD_Remote_Led(TYPE_LED_BLINK_RED_AND_BLUE, LED_EVENT_FLASH_4HZ_3T);
	char UART_TempSend[128];
	sprintf(UART_TempSend,"SENCE_SET-From:0x%x to 0x%x-Opcode:0x%x\n",cb_par->adr_src, cb_par->adr_dst, cb_par->op);
	uart_CSend(UART_TempSend);
	sprintf(UART_TempSend,"Messenger length:%d-Content:%x-%x-%x-%x-%x-%x-%x-%x\n",par_len,par[0],par[1],par[2],par[3],par[4],par[5],par[6],par[7]);
	uart_CSend(UART_TempSend);
	uart_CSend("..\n");

	// RD_EDIT:Flash Save Sence_SetUp to Flash
		button_sence_data.BID = par[0];
		button_sence_data.MODE_ID = par[1];
		button_sence_data.SENCE_ID[0]= par[3];
		button_sence_data.SENCE_ID[1]= par[2];
		RD_Flash_SaveChangeSenceID2Flash(button_sence_data.BID, button_sence_data.MODE_ID, button_sence_data.SENCE_ID );
	}
	RD_Remote_ResponeSetSence(button_sence_data.BID, button_sence_data.MODE_ID, *button_sence_data.SENCE_ID);
	return 0;
}
//int mesh_cmd_sig_RD_respone_status (u8 *par, int par_len, mesh_cb_fun_par_t *cb_par)
//{
//	uart_CSend("Goto Rsp\n");
//	RD_Remote_SendButtonID2GW1(0x01, 0x01, 0x1111);
////    int err = 0;
////    if(cb_par->model){  // model may be Null for status message
////    }
////    return err;
//	return 0;
//}
int RD_Messenger_ProcessCommingProcess (u8 *par, int par_len, mesh_cb_fun_par_t *cb_par){

	return 0;
}
void RD_Messenger_CustomSendSTT(u8 *Mess, u32 _MessLength, u16 adr_dst){
	mesh_tx_cmd2normal_primary(SENSOR_STATUS, Mess, _MessLength, adr_dst, RD_MAXRESPONESEND);
}

void RD_Messenger_SendNode2Gateway (u8 *Mess, u32 _MessLength){
	RD_Messenger_CustomSendSTT(Mess, _MessLength, RD_GATEWAYADDRESS);
}

void RD_Messenger_CustomSendSTTRsp(u8 *Mess, u32 _MessLength, u16 adr_dst){
	mesh_tx_cmd2normal_primary(RD_OPCODE_RSP, Mess, _MessLength, adr_dst, RD_MAXRESPONESEND);
}

void RD_Messenger_SendNode2GatewayRsp (u8 *Mess, u32 _MessLength){
	RD_Messenger_CustomSendSTTRsp(Mess, _MessLength, RD_GATEWAYADDRESS);
}

int RD_Messenger_BindAll(u8 *par, int par_len, mesh_cb_fun_par_t *cb_par){
	extern int mesh_cmd_sig_cfg_bind(u8 *par, int par_len, mesh_cb_fun_par_t *cb_par);

	extern unsigned char vr_RD_ProvDone;
	if((par[4] == 0x06) && (par[5] == 0x13)){
		vr_RD_ProvDone = 1;
	}
	return(mesh_cmd_sig_cfg_bind(par, par_len,  cb_par));
}


void RD_Messenger_CustomSendSTTBindAll(u8 *Mess, u32 _MessLength, u16 adr_dst){
	mesh_tx_cmd2normal_primary(RD_OPCODE_RSP, Mess, _MessLength, adr_dst, RD_MAXRESPONESEND);
}

void RD_Messenger_SendNode2GatewayBindAll (u8 *Mess, u32 _MessLength){
	RD_Messenger_CustomSendSTTBindAll(Mess, _MessLength, RD_GATEWAYADDRESS);
}

void RD_Send_MessTypeDivice(void){
	if(vr_RD_ProvDone == 1){
		vr_RD_ProvDone = 0;
		RD_TypeDevice_Conver2Message();
		RD_Messenger_SendNode2GatewayRsp(vrp_TypeDevice_Point2Message,8);
		uart_CSend("bind xong\n");
	}
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
