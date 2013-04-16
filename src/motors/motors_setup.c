/*
 * motors_setup.c
 *
 *  Created on: Mar 14, 2013
 *      Author: Michal Banasiak
 */

#include "motors_setup.h"

inline void motorsSetup() {
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE);

	GPIO_InitTypeDef  GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;

	setupLeftFront(GPIO_InitStructure);
	setupLeftBack(GPIO_InitStructure);
	setupRightFront(GPIO_InitStructure);
	setupRightBack(GPIO_InitStructure);


	GPIO_SetBits(GPIOE, GPIO_Pin_2);
	GPIO_SetBits(GPIOE, GPIO_Pin_3);
	GPIO_SetBits(GPIOE, GPIO_Pin_9);
	GPIO_SetBits(GPIOE, GPIO_Pin_11);

	motorLeftBackStop();
	motorLeftFrontStop();
	motorRightBackStop();
	motorRightFrontStop();
}

inline void setupLeftFront(GPIO_InitTypeDef GPIO_InitStructure) {
	GPIO_InitStructure.GPIO_Pin = pinOfMotorLeftFrontBackwardPin();
	GPIO_Init(pinOfMotorLeftFrontBackwardGPIO(), &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = pinOfMotorLeftFrontForwardPin();
	GPIO_Init(pinOfMotorLeftFrontForwardGPIO(), &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = pinOfMotorLeftFrontPWMPin();
	GPIO_Init(pinOfMotorLeftFrontPWMGPIO(), &GPIO_InitStructure);
}


inline void setupLeftBack(GPIO_InitTypeDef GPIO_InitStructure) {
	GPIO_InitStructure.GPIO_Pin = pinOfMotorLeftBackBackwardPin();
	GPIO_Init(pinOfMotorLeftBackBackwardGPIO(), &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = pinOfMotorLeftBackForwardPin();
	GPIO_Init(pinOfMotorLeftBackForwardGPIO(), &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = pinOfMotorLeftBackPWMPin();
	GPIO_Init(pinOfMotorLeftBackPWMGPIO(), &GPIO_InitStructure);
}

inline void setupRightFront(GPIO_InitTypeDef GPIO_InitStructure) {
	GPIO_InitStructure.GPIO_Pin = pinOfMotorRightFrontBackwardPin();
	GPIO_Init(pinOfMotorRightFrontBackwardGPIO(), &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = pinOfMotorRightFrontForwardPin();
	GPIO_Init(pinOfMotorRightFrontForwardGPIO(), &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = pinOfMotorRightFrontPWMPin();
	GPIO_Init(pinOfMotorRightFrontPWMGPIO(), &GPIO_InitStructure);
}

inline void setupRightBack(GPIO_InitTypeDef GPIO_InitStructure) {
	GPIO_InitStructure.GPIO_Pin = pinOfMotorRightBackBackwardPin();
	GPIO_Init(pinOfMotorRightBackBackwardGPIO(), &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = pinOfMotorRightBackForwardPin();
	GPIO_Init(pinOfMotorRightBackForwardGPIO(), &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = pinOfMotorRightBackPWMPin();
	GPIO_Init(pinOfMotorRightBackPWMGPIO(), &GPIO_InitStructure);
}
