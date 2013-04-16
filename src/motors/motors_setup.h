/*
 * motors_setup.h
 *
 *  Created on: Mar 14, 2013
 *      Author: Michal Banasiak
 */

#ifndef MOTORS_SETUP_H_
#define MOTORS_SETUP_H_

#include "motors_pins.h"
#include "stm32f30x.h"
#include "motors.h"

inline void motorsSetup();

inline void setupLeftFront(GPIO_InitTypeDef GPIO_InitStructure);
inline void setupLeftBack(GPIO_InitTypeDef GPIO_InitStructure);
inline void setupRightFront(GPIO_InitTypeDef GPIO_InitStructure);
inline void setupRightBack(GPIO_InitTypeDef GPIO_InitStructure);

#endif /* MOTORS_SETUP_H_ */
