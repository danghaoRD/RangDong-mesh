/*
 * RD_Type_Device.h
 *
 *  Created on: Dec 9, 2020
 *      Author: dangv
 */

#ifndef RD_TYPE_DEVICE_H_
#define RD_TYPE_DEVICE_H_


#define RD_OPCODE_SEND		(0xA082)
#define RD_OPCODE_RSP		(0xA182)

#define RD_MAXRESPONESEND   (2)
#define RD_GATEWAYADDRESS   (0x0001)
#define RD_BROADCASTADDRESS (0XFFFF)


typedef enum{
	RD_MAINTYPE_LAMP   = 0,
	RD_MAINTYPE_SENCE  = 1,
	RD_MAINTYPE_SENSOR = 2
} RD_TYPE_MAINDEVICE;

typedef enum{
	RD_TYPE_LAMP_ONOFF   	= 0,
	RD_TYPE_LAMP_CCT  		= 1,
	RD_TYPE_LAMP_RGB 		= 2,
	RD_TYPE_LAMP_CCT_RGB 	= 3
} RD_TYPE_LAMP;

typedef enum{
	RD_TYPE_SENCE_AC   		= 0,
	RD_TYPE_SENCE_DC  		= 1
} RD_TYPE_SENCE;

typedef enum{
	RD_TYPE_SENSOR_PIR   		= 0,
	RD_TYPE_SENSOR_LIGHT 		= 1
} RD_TYPE_SENSOR;


typedef enum{
	RD_TYPE_POWER_NONE   		= 0,
	RD_TYPE_POWER_3W   			= 1,
	RD_TYPE_POWER_5W   			= 2,
	RD_TYPE_POWER_7W   			= 3,
	RD_TYPE_POWER_9W   			= 4,
	RD_TYPE_POWER_15W   		= 5
} RD_TYPE_POWER;



#define RD_CONFIGTYPE_MAINTYPE	RD_MAINTYPE_SENCE
#define RD_CONFIGTYPE_SUBTYPE	RD_TYPE_SENCE_DC
#define RD_CONFIGTYPE_POWER		RD_TYPE_POWER_NONE


typedef struct{
	unsigned char Header[2];
	unsigned char MainType;
	unsigned char SubType;
	unsigned char Power;
	unsigned char Reserved[3];
}RD_TypeDevice_Message;

//extern RD_TypeDevice_Message	vrts_RD_TypeDeviceMessage;
extern unsigned char *vrp_TypeDevice_Point2Message;


void RD_TypeDevice_Conver2Message (void);

#endif /* RD_TYPE_DEVICE_H_ */
