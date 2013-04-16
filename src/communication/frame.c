/*
 * frame.c
 *
 *  Created on: Mar 4, 2013
 *      Author: Michal Banasiak
 */

#include "frame.h"

inline Frame createFrame(command_t command, uint8_t numberOfParameters) {
	Frame frame;

	frame.command = command;
	frame.numberOfParameters = numberOfParameters;

	return frame;
}

inline uint8_t setRegisterAndValue(Frame frame, uint8_t position, register_t reg, value_t value) {
	if (frame.numberOfParameters <= position)
		return 0;

	frame.registers[position] = reg;
	frame.values[position] = value;

	return 1;
}

inline const char frameBegin() {
	return '$';
}

inline const char frameEnd() {
	return '*';
}

inline const char frameSeparator() {
	return '&';
}
