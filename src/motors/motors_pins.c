/*
 * motors.c
 *
 *  Created on: Mar 14, 2013
 *      Author: Michal Banasiak
 */


#include "motors_pins.h"

inline GPIO_TypeDef* pinOfMotorLeftFrontForwardGPIO() {
	return GPIOA;
}

inline GPIO_TypeDef* pinOfMotorLeftFrontBackwardGPIO() {
	return GPIOA;
}

inline uint16_t pinOfMotorLeftFrontForwardPin() {
	return GPIO_Pin_5;
}

inline uint16_t pinOfMotorLeftFrontBackwardPin() {
	return GPIO_Pin_7;
}

inline GPIO_TypeDef* pinOfMotorLeftFrontPWMGPIO() {
	return GPIOE;
}

inline uint16_t pinOfMotorLeftFrontPWMPin() {
	return GPIO_Pin_2;
}

inline GPIO_TypeDef* pinOfMotorLeftBackForwardGPIO() {
	return GPIOA;
}

inline GPIO_TypeDef* pinOfMotorLeftBackBackwardGPIO() {
	return GPIOA;
}

inline uint16_t pinOfMotorLeftBackForwardPin() {
	return GPIO_Pin_3;
}

inline uint16_t pinOfMotorLeftBackBackwardPin() {
	return GPIO_Pin_1;
}

inline GPIO_TypeDef* pinOfMotorLeftBackPWMGPIO() {
	return GPIOE;
}

inline uint16_t pinOfMotorLeftBackPWMPin() {
	return GPIO_Pin_3;
}

inline GPIO_TypeDef* pinOfMotorRightFrontForwardGPIO() {
	return GPIOA;
}

inline GPIO_TypeDef* pinOfMotorRightFrontBackwardGPIO() {
	return GPIOA;
}

inline uint16_t pinOfMotorRightFrontForwardPin() {
	return GPIO_Pin_4;
}

inline uint16_t pinOfMotorRightFrontBackwardPin() {
	return GPIO_Pin_6;
}

inline GPIO_TypeDef* pinOfMotorRightFrontPWMGPIO() {
	return GPIOE;
}

inline uint16_t pinOfMotorRightFrontPWMPin() {
	return GPIO_Pin_9;
}

inline GPIO_TypeDef* pinOfMotorRightBackForwardGPIO() {
	return GPIOA;
}

inline GPIO_TypeDef* pinOfMotorRightBackBackwardGPIO() {
	return GPIOA;
}

inline uint16_t pinOfMotorRightBackForwardPin() {
	return GPIO_Pin_2;
}

inline uint16_t pinOfMotorRightBackBackwardPin() {
	return GPIO_Pin_0;
}

inline GPIO_TypeDef* pinOfMotorRightBackPWMGPIO() {
	return GPIOE;
}

inline uint16_t pinOfMotorRightBackPWMPin() {
	return GPIO_Pin_11;
}
