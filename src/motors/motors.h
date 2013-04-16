/*
 * motors.h
 *
 *  Created on: Mar 15, 2013
 *      Author: Michal Banasiak
 */

#ifndef MOTORS_H_
#define MOTORS_H_

#include "motors_pins.h"
#include "stm32f30x.h"

inline void motorLeftFrontForward();
inline void motorLeftFrontBackward();
inline void motorLeftBackForward();
inline void motorLeftBackBackward();
inline void motorRightFrontForward();
inline void motorRightFrontBackward();
inline void motorRightBackForward();
inline void motorRightBackBackward();

inline void motorLeftFrontStop();
inline void motorLeftBackStop();
inline void motorRightFrontStop();
inline void motorRightBackStop();

inline void motorAllStop();

#endif /* MOTORS_H_ */
