/*
 * loop.c
 *
 *  Created on: Dec 12, 2012
 *      Author: Michal Banasiak
 */

#include "loop.h"
#include "utilities/leds.h"
#include "usart1/usart1.h"
#include "motors/motors.h"
#include "registers/registers.h"

#include "communication/frame_parser_interpreter.h"

inline void loop() {
	if (registerGetLeftBackReferenceVelocity() > 0)
		motorLeftBackForward();
	else if (registerGetLeftBackReferenceVelocity() < 0)
		motorLeftBackBackward();
	else
		motorLeftBackStop();

	if (registerGetRightBackReferenceVelocity() > 0)
		motorRightBackForward();
	else if (registerGetRightBackReferenceVelocity() < 0)
		motorRightBackBackward();
	else
		motorRightBackStop();

	if (registerGetLeftFrontReferenceVelocity() > 0)
		motorLeftFrontForward();
	else if (registerGetLeftFrontReferenceVelocity() < 0)
		motorLeftFrontBackward();
	else
		motorLeftFrontStop();

	if (registerGetRightFrontReferenceVelocity() > 0)
		motorRightFrontForward();
	else if (registerGetRightFrontReferenceVelocity() < 0)
		motorRightFrontBackward();
	else
		motorRightFrontStop();

}
