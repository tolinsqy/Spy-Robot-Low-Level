/*
 * i2c1.c
 *
 *  Created on: Apr 8, 2013
 *      Author: Jarek
 */
#include "stm32f30x.h"
#include "i2c1.h"
#include "i2c_setup.h"





uint16_t SensorWrite(uint8_t DeviceAddr, uint8_t RegAddr,const uint8_t* pBuffer)
{
  /* Test on BUSY Flag */
  uint32_t Sensor_Timeout = Sensor_LONG_TIMEOUT;
  while(I2C_GetFlagStatus(Sensor_I2C, I2C_ISR_BUSY) != RESET)
  {
    if((Sensor_Timeout--) == 0)
    	return Sensor_I2C_TIMEOUT;
  }

  /* Configure slave address, nbytes, reload, end mode and start or stop generation */
  I2C_TransferHandling(Sensor_I2C, DeviceAddr, 1, I2C_Reload_Mode, I2C_Generate_Start_Write);

  /* Wait until TXIS flag is set */
  Sensor_Timeout = Sensor_LONG_TIMEOUT;
  while(I2C_GetFlagStatus(Sensor_I2C, I2C_ISR_TXIS) == RESET)
  {
    if((Sensor_Timeout--) == 0)
    	return Sensor_I2C_TIMEOUT;
  }

  /* Send Register address */
  I2C_SendData(Sensor_I2C, (uint8_t) RegAddr);

  /* Wait until TCR flag is set */
  Sensor_Timeout = Sensor_LONG_TIMEOUT;
  while(I2C_GetFlagStatus(Sensor_I2C, I2C_ISR_TCR) == RESET)
  {
    if((Sensor_Timeout--) == 0)
    	return Sensor_I2C_TIMEOUT;
  }

  /* Configure slave address, nbytes, reload, end mode and start or stop generation */
  I2C_TransferHandling(Sensor_I2C, DeviceAddr, 1, I2C_AutoEnd_Mode, I2C_No_StartStop);

  /* Wait until TXIS flag is set */
  Sensor_Timeout = Sensor_LONG_TIMEOUT;
  while(I2C_GetFlagStatus(Sensor_I2C, I2C_ISR_TXIS) == RESET)
  {
    if((Sensor_Timeout--) == 0)
    	return Sensor_I2C_TIMEOUT;
  }

  /* Write data to TXDR */
  I2C_SendData(Sensor_I2C, *pBuffer);

  /* Wait until STOPF flag is set */
  Sensor_Timeout = Sensor_LONG_TIMEOUT;
  while(I2C_GetFlagStatus(Sensor_I2C, I2C_ISR_STOPF) == RESET)
  {
    if((Sensor_Timeout--) == 0)
    	return    		Sensor_I2C_TIMEOUT;
  }

  /* Clear STOPF flag */
  I2C_ClearFlag(Sensor_I2C, I2C_ICR_STOPCF);

  return Sensor_OK;
}


/**
  * @brief  Reads a block of data from the Sensor.
  * @param  DeviceAddr : specifies the slave address to be programmed(ACC_I2C_ADDRESS or MAG_I2C_ADDRESS).
  * @param  RegAddr : specifies the Sensor internal address register to read from.
  * @param  pBuffer : pointer to the buffer that receives the data read from the LSM303DLH.
  * @param  NumByteToRead : number of bytes to read from the LSM303DLH ( NumByteToRead >1  only for the Mgnetometer readinf).
  * @retval Sensor register value
  */
uint16_t SensorRead(uint8_t DeviceAddr, uint8_t RegAddr, uint8_t* pBuffer,uint16_t NumByteToRead)
{
  /* Test on BUSY Flag */
	uint32_t Sensor_Timeout = Sensor_LONG_TIMEOUT;
  while(I2C_GetFlagStatus(Sensor_I2C, I2C_ISR_BUSY) != RESET)
  {
    if((Sensor_Timeout--) == 0) return Sensor_I2C_TIMEOUT;
  }

  /* Configure slave address, nbytes, reload, end mode and start or stop generation */
  I2C_TransferHandling(Sensor_I2C, DeviceAddr, 1, I2C_SoftEnd_Mode, I2C_Generate_Start_Write);

  /* Wait until TXIS flag is set */
  Sensor_Timeout = Sensor_LONG_TIMEOUT;
  while(I2C_GetFlagStatus(Sensor_I2C, I2C_ISR_TXIS) == RESET)
  {
    if((Sensor_Timeout--) == 0) return Sensor_I2C_TIMEOUT;
  }

  if(NumByteToRead>1)
      RegAddr |= 0x80;


  /* Send Register address */
  I2C_SendData(Sensor_I2C, (uint8_t)RegAddr);

  /* Wait until TC flag is set */
  Sensor_Timeout = Sensor_LONG_TIMEOUT;
  while(I2C_GetFlagStatus(Sensor_I2C, I2C_ISR_TC) == RESET)
  {
    if((Sensor_Timeout--) == 0) return Sensor_I2C_TIMEOUT;
  }

  /* Configure slave address, nbytes, reload, end mode and start or stop generation */
  I2C_TransferHandling(Sensor_I2C, DeviceAddr, NumByteToRead, I2C_AutoEnd_Mode, I2C_Generate_Start_Read);

  /* Wait until all data are received */
  while (NumByteToRead)
  {
    /* Wait until RXNE flag is set */
    Sensor_Timeout = Sensor_LONG_TIMEOUT;
    while(I2C_GetFlagStatus(Sensor_I2C, I2C_ISR_RXNE) == RESET)
    {
      if((Sensor_Timeout--) == 0) return Sensor_I2C_TIMEOUT;
    }

    /* Read data from RXDR */
    *pBuffer = I2C_ReceiveData(Sensor_I2C);
    /* Point to the next location where the byte read will be saved */
    pBuffer++;

    /* Decrement the read bytes counter */
    NumByteToRead--;
  }

  /* Wait until STOPF flag is set */
  Sensor_Timeout = Sensor_LONG_TIMEOUT;
  while(I2C_GetFlagStatus(Sensor_I2C, I2C_ISR_STOPF) == RESET)
  {
    if((Sensor_Timeout--) == 0) return Sensor_I2C_TIMEOUT;
  }

  /* Clear STOPF flag */
  I2C_ClearFlag(Sensor_I2C, I2C_ICR_STOPCF);

  /* If all operations OK */
  return Sensor_OK;
}
