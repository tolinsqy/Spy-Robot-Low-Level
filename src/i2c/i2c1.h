
/*
 * i2c1.h
 *
 *  Created on: Apr 8, 2013
 *      Author: Jarek
 *      TODO REWRITE FROM SCRATCH - KILL IT WITH FIRE
 */

#ifndef I2C1_H_
#define I2C1_H_

#define Sensor_FLAG_TIMEOUT             ((uint32_t)0x1000)
#define Sensor_LONG_TIMEOUT             ((uint32_t)(10 * Sensor_FLAG_TIMEOUT))
#define Sensor_I2C_TIMEOUT ((uint32_t) 69)
#define Sensor_OK ((uint32_t) 0)

uint16_t SensorWrite(uint8_t DeviceAddr, uint8_t RegAddr,const uint8_t* pBuffer);
uint16_t SensorRead(uint8_t DeviceAddr, uint8_t RegAddr,uint8_t* pBuffer, uint16_t NumByteToRead);

#endif /* I2C1_H_ */
