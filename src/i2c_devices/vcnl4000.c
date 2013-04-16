/*
 * vcnl4000.c
 *
 *  Created on: Apr 12, 2013
 *      Author: Jarek
 */
#include "stm32f30x.h"
#include "VCNL4000.h"
#include "i2c/i2c_setup.h"
#include "registers/registers.h"
#include "i2c/i2c1.h"

const uint16_t VCNL4000_STATUS_OK 		= 0x0000;
const uint16_t VCNL4000_STATUS_FAIL 	= 0x0001;
const uint16_t VCNL4000_STATUS_TIMEOUT 	= 0x0002;


const uint8_t VCNL4000_I2C_ADDRESS 		=0x26; // 0b0011001x

/**
 * Product ID revision register (READ-ONLY)
 */
const uint8_t VCNL4000_I2C_REG_ID			=0x81;
/**
 * Configuration registers
 */
const uint8_t VCNL4000_I2C_REG_CMD 			=0x80;/*0x8F*/
const uint8_t VCNL4000_I2C_REG_IR_CURRENT	=0x83;
const uint8_t VCNL4000_I2C_REG_AL_LP		=0x84;
const uint8_t VCNL4000_I2C_REG_PS_FREQ		=0x89;
const uint8_t VCNL4000_I2C_REG_PS_TIMING	=0x8A;

/**
 * Results registers
 */
const uint8_t VCNL4000_I2C_REG_AL_RES_H		=0x85; /*High byte*/
const uint8_t VCNL4000_I2C_REG_AL_RES_L		=0x86; /*Low byte*/
const uint8_t VCNL4000_I2C_REG_PS_Res_H		=0x87; /*High byte*/
const uint8_t VCNL4000_I2C_REG_PS_Res_L		=0x88; /*Low byte*/

/**
 * Configuration registers DEFAULT values (used in setup)
 */
const uint8_t VCNL4000_I2C_REG_CMD_DEFAULT			= 0x80;
const uint8_t VCNL4000_I2C_REG_IR_CURRENT_DEFAULT	= 20;/*200mA*///0x0A; /*100mA*/
const uint8_t VCNL4000_I2C_REG_AL_LP_DEFAULT		= 0x05; /*Datasheet default, OFF*/
const uint8_t VCNL4000_I2C_REG_PS_FREQ_DEFAULT		= 0x03; /*DS default, 781.25kHz*/
const uint8_t VCNL4000_I2C_REG_PS_TIMING_DEFAULT	= 0x81; /*DS recommended, 129d*/

const uint8_t VCNL4000_I2C_REG_CMD_CL_BIT			= 0x80;

const uint8_t VCNL4000_I2C_REG_CMD_PROX_READY_BIT	= 0x20;
const uint8_t VCNL4000_I2C_REG_CMD_PROX_START_BIT	= 0x08;

const uint8_t VCNL4000_I2C_REG_CMD_ALS_READY_BIT	= 0x40;
const uint8_t VCNL4000_I2C_REG_CMD_ALS_START_BIT	= 0x10;


const int32_t VCNL4000_MEASURE_TIMEOUT				= 0x1000;

typedef struct VCNL4000Config {
	uint8_t _cmd;
	uint8_t _irCurrent;
	uint8_t _alLp;
	uint8_t _psFreq;
	uint8_t _psTiming;

	uint16_t _status;
	uint16_t _psResult;
	uint16_t _alsResult;

	uint16_t _psScaled;


	//uint16_t _alsScaled;
} VCNL4000Config;

VCNL4000Config vcnl1;

uint16_t VCNL4000_Setup()
{
	I2C1_Initialization();//initializes I2C
	vcnl1=(VCNL4000Config){ 	VCNL4000_I2C_REG_CMD_DEFAULT, VCNL4000_I2C_REG_IR_CURRENT_DEFAULT,
		VCNL4000_I2C_REG_AL_LP_DEFAULT, VCNL4000_I2C_REG_PS_FREQ_DEFAULT,
		VCNL4000_I2C_REG_PS_TIMING_DEFAULT,VCNL4000_I2C_REG_CMD_DEFAULT,0,0,0};
	uint16_t ret=0;//
	uint8_t pBuffer=0;
	ret|=SensorRead(VCNL4000_I2C_ADDRESS, VCNL4000_I2C_REG_CMD ,&pBuffer,1);
	if(ret==0 && (pBuffer&VCNL4000_I2C_REG_CMD_CL_BIT)==0x80)
	{
		ret|=SensorWrite(VCNL4000_I2C_ADDRESS, VCNL4000_I2C_REG_IR_CURRENT, &vcnl1._irCurrent);
		ret|=SensorWrite(VCNL4000_I2C_ADDRESS, VCNL4000_I2C_REG_PS_FREQ, &vcnl1._psFreq);
		ret|=SensorWrite(VCNL4000_I2C_ADDRESS, VCNL4000_I2C_REG_PS_TIMING, &vcnl1._psTiming);
	}
	return ret;
}

uint16_t VCNL4000_ScaleProximity()
{
	return VCNL4000_STATUS_FAIL;
}

uint16_t VCNL4000_ReadProximity()
{
	uint16_t ret=0;//
	uint32_t timeleft=VCNL4000_MEASURE_TIMEOUT;
	uint8_t tmp=0;

	//uint8_t pBuffer=0;

	/*reading from cmd reg is done only cause I dont know if overwriting other registers might stop other measures*/
	ret|=SensorRead(VCNL4000_I2C_ADDRESS, VCNL4000_I2C_REG_CMD ,&vcnl1._cmd,1); //read cmd reg
	vcnl1._cmd|=VCNL4000_I2C_REG_CMD_PROX_START_BIT;//force proximity in cmd reg
	ret|=SensorWrite(VCNL4000_I2C_ADDRESS, VCNL4000_I2C_REG_CMD, &vcnl1._cmd); //write new cmd reg

	/*wait for results*/
	while((ret|=SensorRead(VCNL4000_I2C_ADDRESS, VCNL4000_I2C_REG_CMD ,&vcnl1._cmd,1))==0
			&& (vcnl1._cmd & VCNL4000_I2C_REG_CMD_PROX_READY_BIT)!=VCNL4000_I2C_REG_CMD_PROX_READY_BIT)
	{
		if(--timeleft==0)	return vcnl1._status=(VCNL4000_STATUS_FAIL & VCNL4000_STATUS_TIMEOUT);
	}
	/*data ready to read, read from device*/

	ret|=SensorRead(VCNL4000_I2C_ADDRESS, VCNL4000_I2C_REG_PS_Res_L ,&tmp,1);
	vcnl1._psResult=tmp;
	ret|=SensorRead(VCNL4000_I2C_ADDRESS, VCNL4000_I2C_REG_PS_Res_H ,&tmp,1);
	vcnl1._psResult+=tmp<<8;
	registerSetVCNL4000_1(vcnl1._psResult);

	if(ret!=0)
		vcnl1._status=VCNL4000_STATUS_FAIL;

	return ret;
}
