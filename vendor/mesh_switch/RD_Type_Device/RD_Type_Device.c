/*
 * RD_Type_Device.c
 *
 *  Created on: Dec 9, 2020
 *      Author: dangv
 */

#include "RD_Type_Device.h"
unsigned char *vrp_TypeDevice_Point2Message;
static RD_TypeDevice_Message	vrts_RD_TypeDeviceMessage;

void RD_TypeDevice_Conver2Message (void){
	vrts_RD_TypeDeviceMessage.Header[0] = 0x02;
	vrts_RD_TypeDeviceMessage.Header[1] = 0x00;
	vrts_RD_TypeDeviceMessage.MainType 	= RD_CONFIGTYPE_MAINTYPE;
	vrts_RD_TypeDeviceMessage.SubType  	= RD_CONFIGTYPE_SUBTYPE;
	vrts_RD_TypeDeviceMessage.Power		= RD_CONFIGTYPE_POWER;
	vrts_RD_TypeDeviceMessage.Reserved[0] = 0;
	vrts_RD_TypeDeviceMessage.Reserved[1] = 0;
	vrts_RD_TypeDeviceMessage.Reserved[2] = 0;
	vrp_TypeDevice_Point2Message = (unsigned char *)(&vrts_RD_TypeDeviceMessage);
}
