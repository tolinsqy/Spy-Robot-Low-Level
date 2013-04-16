/*
 * motors.c
 *
 *  Created on: Mar 15, 2013
 *      Author: Michal Banasiak
 */


#include "motors.h"

inline void motorLeftFrontForward() {
	GPIO_SetBits(pinOfMotorLeftFrontForwardGPIO(), pinOfMotorLeftFrontForwardPin());
	GPIO_ResetBits(pinOfMotorLeftFrontBackwardGPIO(), pinOfMotorLeftFrontBackwardPin());
}

inline void motorLeftFrontBackward() {
	GPIO_SetBits(pinOfMotorLeftFrontBackwardGPIO(), pinOfMotorLeftFrontBackwardPin());
	GPIO_ResetBits(pinOfMotorLeftFrontForwardGPIO(), pinOfMotorLeftFrontForwardPin());
}

inline void motorLeftBackForward() {
	GPIO_SetBits(pinOfMotorLeftBackForwardGPIO(), pinOfMotorLeftBackForwardPin());
	GPIO_ResetBits(pinOfMotorLeftBackBackwardGPIO(), pinOfMotorLeftBackBackwardPin());
}

inline void motorLeftBackBackward() {
	GPIO_SetBits(pinOfMotorLeftBackBackwardGPIO(), pinOfMotorLeftBackBackwardPin());
	GPIO_ResetBits(pinOfMotorLeftBackForwardGPIO(), pinOfMotorLeftBackForwardPin());
}

inline void motorRightFrontForward() {
	GPIO_SetBits(pinOfMotorRightFrontForwardGPIO(), pinOfMotorRightFrontForwardPin());
	GPIO_ResetBits(pinOfMotorRightFrontBackwardGPIO(), pinOfMotorRightFrontBackwardPin());
}

inline void motorRightFrontBackward() {
	GPIO_SetBits(pinOfMotorRightFrontBackwardGPIO(), pinOfMotorRightFrontBackwardPin());
	GPIO_ResetBits(pinOfMotorRightFrontForwardGPIO(), pinOfMotorRightFrontForwardPin());
}

inline void motorRightBackForward() {
	GPIO_SetBits(pinOfMotorRightBackForwardGPIO(), pinOfMotorRightBackForwardPin());
	GPIO_ResetBits(pinOfMotorRightBackBackwardGPIO(), pinOfMotorRightBackBackwardPin());
}

inline void motorRightBackBackward() {
	GPIO_SetBits(pinOfMotorRightBackBackwardGPIO(), pinOfMotorRightBackBackwardPin());
	GPIO_ResetBits(pinOfMotorRightBackForwardGPIO(), pinOfMotorRightBackForwardPin());
}

inline void motorLeftFrontStop() {
	GPIO_ResetBits(pinOfMotorLeftFrontBackwardGPIO(), pinOfMotorLeftFrontBackwardPin());
	GPIO_ResetBits(pinOfMotorLeftFrontForwardGPIO(), pinOfMotorLeftFrontForwardPin());
}

inline void motorLeftBackStop() {
	GPIO_ResetBits(pinOfMotorLeftBackBackwardGPIO(), pinOfMotorLeftBackBackwardPin());
	GPIO_ResetBits(pinOfMotorLeftBackForwardGPIO(), pinOfMotorLeftBackForwardPin());
}

inline void motorRightFrontStop() {
	GPIO_ResetBits(pinOfMotorRightFrontBackwardGPIO(), pinOfMotorRightFrontBackwardPin());
	GPIO_ResetBits(pinOfMotorRightFrontForwardGPIO(), pinOfMotorRightFrontForwardPin());
}

inline void motorRightBackStop() {
	GPIO_ResetBits(pinOfMotorRightBackBackwardGPIO(), pinOfMotorRightBackBackwardPin());
	GPIO_ResetBits(pinOfMotorRightBackForwardGPIO(), pinOfMotorRightBackForwardPin());
}

inline void motorAllStop() {
	motorRightFrontStop();
	motorRightBackStop();
	motorLeftBackStop();
	motorLeftFrontStop();
}
