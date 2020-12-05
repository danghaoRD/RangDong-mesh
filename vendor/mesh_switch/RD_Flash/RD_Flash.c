/*
 * RD_Flash.c
 *
 *  Created on: Dec 2, 2020
 *      Author: dangv
 */

#include "RD_Flash.h"


Button_Sence   button_sence_data;
unsigned char  Buff_Flash_Read[FLASH_BUFF_LEN];
unsigned char  Buff_Flash_Write[FLASH_BUFF_LEN] = {
				0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
				0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
				0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
				0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
				0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
				0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
				0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
				0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

};
uint16_t RD_Flash_Get_Sence_ID(uint8_t buttonID, uint8_t modeID )
{
	switch (buttonID)
	{
	case   Button_OnOff:
		if(modeID == One_Press)
		{
			button_sence_data.SENCE_ID[0] = Buff_Flash_Read[0];
			button_sence_data.SENCE_ID[1] = Buff_Flash_Read[1];
			uart_CSend("button_ok one Press: reaed");
		}
		else if(modeID ==  Double_Press)
		{
			button_sence_data.SENCE_ID[0] = Buff_Flash_Read[2];
			button_sence_data.SENCE_ID[1] = Buff_Flash_Read[3];
		}
		else if(modeID == Hold_Press)
		{
			button_sence_data.SENCE_ID[0] = Buff_Flash_Read[4];
			button_sence_data.SENCE_ID[1] = Buff_Flash_Read[5];
		}
		break;
 	case Button_Sence1:
		if(modeID == One_Press)
		{
			button_sence_data.SENCE_ID[0] = Buff_Flash_Read[6];
			button_sence_data.SENCE_ID[1] = Buff_Flash_Read[7];
		}
		else if(modeID == Double_Press)
		{
			button_sence_data.SENCE_ID[0] = Buff_Flash_Read[8];
			button_sence_data.SENCE_ID[1] = Buff_Flash_Read[9];
		}
		else if(modeID == Hold_Press)
		{
			button_sence_data.SENCE_ID[0] = Buff_Flash_Read[10];
			button_sence_data.SENCE_ID[1] = Buff_Flash_Read[11];
		}
		break;
	case Button_Sence2:
		if(modeID == One_Press)
		{
			button_sence_data.SENCE_ID[0] = Buff_Flash_Read[12];
			button_sence_data.SENCE_ID[1] = Buff_Flash_Read[13];
		}
		else if(modeID == Double_Press)
		{
			button_sence_data.SENCE_ID[0] = Buff_Flash_Read[14];
			button_sence_data.SENCE_ID[1] = Buff_Flash_Read[15];
		}
		else if(modeID == Hold_Press)
		{
			button_sence_data.SENCE_ID[0] = Buff_Flash_Read[16];
			button_sence_data.SENCE_ID[1] = Buff_Flash_Read[17];
		}
		break;
	case Button_Sence3:
		if(modeID == One_Press)
		{
			button_sence_data.SENCE_ID[0] = Buff_Flash_Read[18];
			button_sence_data.SENCE_ID[1] = Buff_Flash_Read[19];
		}
		else if(modeID == Double_Press)
		{
			button_sence_data.SENCE_ID[0] = Buff_Flash_Read[20];
			button_sence_data.SENCE_ID[1] = Buff_Flash_Read[21];
		}
		else if(modeID == Hold_Press)
		{
			button_sence_data.SENCE_ID[0] = Buff_Flash_Read[22];
			button_sence_data.SENCE_ID[1] = Buff_Flash_Read[23];
		}
		break;
	case Button_Sence4:
		if(modeID == One_Press)
		{
			button_sence_data.SENCE_ID[0] = Buff_Flash_Read[24];
			button_sence_data.SENCE_ID[1] = Buff_Flash_Read[25];
		}
		else if(modeID == Double_Press)
		{
			button_sence_data.SENCE_ID[0] = Buff_Flash_Read[26];
			button_sence_data.SENCE_ID[1] = Buff_Flash_Read[27];
		}
		else if(modeID == Hold_Press)
		{
			button_sence_data.SENCE_ID[0] = Buff_Flash_Read[28];
			button_sence_data.SENCE_ID[1] = Buff_Flash_Read[29];
		}
		break;
	case Button_Sence5:
		if(modeID == One_Press)
		{
			button_sence_data.SENCE_ID[0] = Buff_Flash_Read[30];
			button_sence_data.SENCE_ID[1] = Buff_Flash_Read[31];
		}
		else if(modeID == Double_Press)
		{
			button_sence_data.SENCE_ID[0] = Buff_Flash_Read[32];
			button_sence_data.SENCE_ID[1] = Buff_Flash_Read[33];
		}
		else if(modeID == Hold_Press)
		{
			button_sence_data.SENCE_ID[0] = Buff_Flash_Read[34];
			button_sence_data.SENCE_ID[1] = Buff_Flash_Read[35];
		}
		break;
	}

	uint16_t buff_H, buff_L;
	buff_H = button_sence_data.SENCE_ID[1];
	buff_L = button_sence_data.SENCE_ID[0];
		char UART_TempSend[128];
		sprintf(UART_TempSend," SenceID_From_Flash:0x%x and 0x%x \n",button_sence_data.SENCE_ID[0],button_sence_data.SENCE_ID[1] );
		uart_CSend(UART_TempSend);
	return ( (buff_H<<8)|(buff_L));
}

void RD_Flash_SaveChangeSenceID2Flash(uint8_t buttonID, uint8_t modeID, uint8_t SenceID[2])
{
	switch (buttonID)
	{
	case Button_OnOff:
		if(modeID == One_Press)
		{
			 Buff_Flash_Read[0] =SenceID[0] ;
			 Buff_Flash_Read[1] =SenceID[1];
		}
		else if(modeID == Double_Press)
		{
			 Buff_Flash_Read[2] =SenceID[0] ;
			 Buff_Flash_Read[3] =SenceID[1];
		}
		else if(modeID == Hold_Press)
		{
			 Buff_Flash_Read[4] =SenceID[0] ;
			 Buff_Flash_Read[5] =SenceID[1];
		}
		break;
	case Button_Sence1:
		if(modeID == One_Press)
		{
			 Buff_Flash_Read[6] =SenceID[0] ;
			 Buff_Flash_Read[7] =SenceID[1];
		}
		else if(modeID == Double_Press)
		{
			 Buff_Flash_Read[8] =SenceID[0] ;
			 Buff_Flash_Read[9] =SenceID[1];
		}
		else if(modeID == Hold_Press)
		{
			 Buff_Flash_Read[10] =SenceID[0] ;
			 Buff_Flash_Read[11] =SenceID[1];
		}
		break;
	case Button_Sence2:
		if(modeID == One_Press)
		{
			 Buff_Flash_Read[12] =SenceID[0] ;
			 Buff_Flash_Read[13] =SenceID[1];
		}
		else if(modeID == Double_Press)
		{
			 Buff_Flash_Read[14] =SenceID[0] ;
			 Buff_Flash_Read[15] =SenceID[1];
		}
		else if(modeID == Hold_Press)
		{
			 Buff_Flash_Read[16] =SenceID[0] ;
			 Buff_Flash_Read[17] =SenceID[1];
		}
		break;
	case Button_Sence3:
		if(modeID == One_Press)
		{
			 Buff_Flash_Read[18] =SenceID[0] ;
			 Buff_Flash_Read[19] =SenceID[1];
		}
		else if(modeID == Double_Press)
		{
			 Buff_Flash_Read[20] =SenceID[0] ;
			 Buff_Flash_Read[21] =SenceID[1];
		}
		else if(modeID == Hold_Press)
		{
			 Buff_Flash_Read[22] =SenceID[0] ;
			 Buff_Flash_Read[23] =SenceID[1];
		}
		break;
	case Button_Sence4:
		if(modeID == One_Press)
		{
			 Buff_Flash_Read[24] =SenceID[0] ;
			 Buff_Flash_Read[25] =SenceID[1];
		}
		else if(modeID == Double_Press)
		{
			 Buff_Flash_Read[26] =SenceID[0] ;
			 Buff_Flash_Read[27] =SenceID[1];
		}
		else if(modeID == Hold_Press)
		{
			 Buff_Flash_Read[28] =SenceID[0] ;
			 Buff_Flash_Read[29] =SenceID[1];
		}
		break;
	case Button_Sence5:
		if(modeID == One_Press)
		{
			 Buff_Flash_Read[30] =SenceID[0] ;
			 Buff_Flash_Read[31] =SenceID[1];
		}
		else if(modeID == Double_Press)
		{
			 Buff_Flash_Read[32] =SenceID[0] ;
			 Buff_Flash_Read[33] =SenceID[1];
		}
		else if(modeID == Hold_Press)
		{
			 Buff_Flash_Read[34] =SenceID[0] ;
			 Buff_Flash_Read[35] =SenceID[1];
		}
		break;
	}
   	flash_erase_sector(FLASH_ADDR);
	flash_write_page(FLASH_ADDR, FLASH_BUFF_LEN, Buff_Flash_Read );
	char UART_TempSend[128];
	sprintf(UART_TempSend,"Save_Change_SenceID_2_Flash: BID:%x ModeID:%x SENCE_ID:0x%x to 0x%x \n",buttonID, modeID, SenceID[0], SenceID[1] );
	uart_CSend(UART_TempSend);
}
/*
 *  Check da ghi Flash lan nao chua. neu chua thi ghi 0x00 len 64 byte dau tien
 * 	Doc 64 byte Flash tu 0x210000 vao Buff_Flash de su dung khi can.
 */
void RD_Flash_Init()
{



	flash_read_page(FLASH_ADDR, FLASH_BUFF_LEN, Buff_Flash_Read);
	if(Buff_Flash_Read[63] == 0xFF)
	{
		RD_Flash_CleanSenceFlash();
	}
	else
	{
		char UART_TempSend[128];
		sprintf(UART_TempSend,"Flash data 0x210000:0x%x 0x%x \n",Buff_Flash_Read[0],Buff_Flash_Read[1] );
		uart_CSend(UART_TempSend);
//		for(int i=0; i<36;i=i+2)
//		{
//			sprintf(UART_TempSend," 0x%x 0x%x \n",Buff_Flash_Read[i+1],Buff_Flash_Read[i] );
//			uart_CSend(UART_TempSend);
//		}
	}
}

void RD_Flash_CleanSenceFlash()
{
	uint8_t Buff_Flash_Null[FLASH_BUFF_LEN]={0};
	uart_CSend("Clean Sence Flash");
   	flash_erase_sector(FLASH_ADDR);
	flash_write_page(FLASH_ADDR, FLASH_BUFF_LEN,Buff_Flash_Null );
	flash_read_page(FLASH_ADDR, FLASH_BUFF_LEN, Buff_Flash_Read);
}
//flash_read_page(FLASH_ADDR,FLASH_BUFF_LEN,(unsigned char *)Flash_Read_Buff);

