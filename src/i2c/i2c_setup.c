/*
 * i2c_setup.c
 *
 *  Created on: Apr 8, 2013
 *      Author: Jarek
 */
#include "i2c_setup.h"
#include "i2c_pins.h"

void I2C1_Initialization(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  //EXTI_InitTypeDef EXTI_InitStructure;
  I2C_InitTypeDef  I2C_InitStructure;

  /* Enable the I2C periph */
  RCC_APB1PeriphClockCmd(Sensor_I2C_CLK, ENABLE);

  /* Enable SCK and SDA GPIO clocks */
  RCC_AHBPeriphClockCmd(Sensor_I2C_SCK_GPIO_CLK | Sensor_I2C_SDA_GPIO_CLK , ENABLE);


  GPIO_PinAFConfig(Sensor_I2C_SCK_GPIO_PORT, Sensor_I2C_SCK_SOURCE, Sensor_I2C_SCK_AF);
  GPIO_PinAFConfig(Sensor_I2C_SDA_GPIO_PORT, Sensor_I2C_SDA_SOURCE, Sensor_I2C_SDA_AF);

  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

  /* I2C SCK pin configuration */
  GPIO_InitStructure.GPIO_Pin = Sensor_I2C_SCK_PIN;
  GPIO_Init(Sensor_I2C_SCK_GPIO_PORT, &GPIO_InitStructure);

  /* I2C SDA pin configuration */
  GPIO_InitStructure.GPIO_Pin =  Sensor_I2C_SDA_PIN;
  GPIO_Init(Sensor_I2C_SDA_GPIO_PORT, &GPIO_InitStructure);


  /* I2C configuration -------------------------------------------------------*/
  I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
  I2C_InitStructure.I2C_AnalogFilter = I2C_AnalogFilter_Enable;
  I2C_InitStructure.I2C_DigitalFilter = 0x00;
  I2C_InitStructure.I2C_OwnAddress1 = 0x00;
  I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
  I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
  I2C_InitStructure.I2C_Timing = 0x00902025; /*MAGIC VALUE - GO TO HELL ST*/

  /* Apply Sensor_I2C configuration after enabling it */
  I2C_Init(Sensor_I2C, &I2C_InitStructure);

  /* Sensor_I2C Peripheral Enable */
  I2C_Cmd(Sensor_I2C, ENABLE);
}

