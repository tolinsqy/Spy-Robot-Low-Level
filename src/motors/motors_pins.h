/*
 * motors.h
 *
 *  Created on: Mar 14, 2013
 *      Author: Michal Banasiak
 */

#ifndef MOTORS_PINS_H_
#define MOTORS_PINS_H_

#include "stm32f30x.h"

inline GPIO_TypeDef* pinOfMotorLeftFrontForwardGPIO();
inline GPIO_TypeDef* pinOfMotorLeftFrontBackwardGPIO();
inline uint16_t 	 pinOfMotorLeftFrontForwardPin();
inline uint16_t 	 pinOfMotorLeftFrontBackwardPin();
inline GPIO_TypeDef* pinOfMotorLeftFrontPWMGPIO();
inline uint16_t 	 pinOfMotorLeftFrontPWMPin();

inline GPIO_TypeDef* pinOfMotorLeftBackForwardGPIO();
inline GPIO_TypeDef* pinOfMotorLeftBackBackwardGPIO();
inline uint16_t 	 pinOfMotorLeftBackForwardPin();
inline uint16_t 	 pinOfMotorLeftBackBackwardPin();
inline GPIO_TypeDef* pinOfMotorLeftBackPWMGPIO();
inline uint16_t 	 pinOfMotorLeftBackPWMPin();

inline GPIO_TypeDef* pinOfMotorRightFrontForwardGPIO();
inline GPIO_TypeDef* pinOfMotorRightFrontBackwardGPIO();
inline uint16_t 	 pinOfMotorRightFrontForwardPin();
inline uint16_t 	 pinOfMotorRightFrontBackwardPin();
inline GPIO_TypeDef* pinOfMotorRightFrontPWMGPIO();
inline uint16_t 	 pinOfMotorRightFrontPWMPin();

inline GPIO_TypeDef* pinOfMotorRightBackForwardGPIO();
inline GPIO_TypeDef* pinOfMotorRightBackBackwardGPIO();
inline uint16_t 	 pinOfMotorRightBackForwardPin();
inline uint16_t 	 pinOfMotorRightBackBackwardPin();
inline GPIO_TypeDef* pinOfMotorRightBackPWMGPIO();
inline uint16_t 	 pinOfMotorRightBackPWMPin();

#endif /* MOTORS_H_ */
