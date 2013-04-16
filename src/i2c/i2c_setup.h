/*
 * i2c_setup.h
 *
 *  Created on: Apr 8, 2013
 *      Author: Jarek
 */

#ifndef I2C_SETUP_H_
#define I2C_SETUP_H_

#include "stm32f30x.h"
#include "i2c_pins.h"

#define Sensor_I2C                       I2C2
#define Sensor_I2C_CLK                   RCC_APB1Periph_I2C2
#define Sensor_I2C_SCK_SOURCE           GPIO_PinSource9
#define Sensor_I2C_SCK_AF               GPIO_AF_4
#define Sensor_I2C_SDA_SOURCE           GPIO_PinSource10
#define Sensor_I2C_SDA_AF               GPIO_AF_4

#define Sensor_I2C_SCK_GPIO_CLK          RCC_AHBPeriph_GPIOA
#define Sensor_I2C_SDA_GPIO_CLK          RCC_AHBPeriph_GPIOA

void I2C1_Initialization(void);

#endif /* I2C_SETUP_H_ */
