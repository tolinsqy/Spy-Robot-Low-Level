/*
 * frame.h
 *
 *  Created on: Mar 4, 2013
 *      Author: Michal Banasiak
 */

#ifndef FRAME_H_
#define FRAME_H_

#include "stm32f30x.h"

typedef uint8_t register_t;

typedef enum {
	RR,
	WR,
	OK,
	NR,
	RO,
	NOT_RECOGNIZED
} command_t;

typedef int32_t value_t;

#define maxRegisters 10

typedef struct {
	command_t  command;
	uint8_t    numberOfParameters;
	register_t registers[maxRegisters];
	value_t    values[maxRegisters];
} Frame;


inline Frame createFrame(command_t command, uint8_t numberOfParameters);
inline uint8_t setRegisterAndValue(Frame frame, uint8_t position, register_t reg, value_t value);

inline const char frameBegin();
inline const char frameEnd();
inline const char frameSeparator();

#endif /* FRAME_H_ */
