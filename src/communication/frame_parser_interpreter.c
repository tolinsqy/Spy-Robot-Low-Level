/*
 * frame_parser.c
 *
 *  Created on: Mar 4, 2013
 *      Author: Michal Banasiak
 */


#include "frame_parser_interpreter.h"
#include "utilities/helpers.h"
#include "usart1/usart1.h"


uint32_t numberOfParametersFromMessage(const char* message);
uint8_t isMessageValid(const char* message);
command_t commandTypeFromMessage(const char* message);
uint8_t saveToRegisters(const char* registerName, value_t value);
uint8_t readFromRegisters(const char* registerName,
		uint32_t* index,
		char* buffer);
uint8_t interpretWriteToRegistersMessage(const char* message,
		command_t commandType,
		uint32_t index,
		uint32_t numberOfParameters);
uint8_t interpretReadFromRegistersMessage(const char* message,
		command_t commandType,
		uint32_t index,
		uint32_t numberOfParameters);
uint8_t indexOfFirstRegisterInMessage(const char* message);

/**
 * Parsing for command WR. If you want to write to some registers,
 * update this function. Be sure to include '\0'!
 */
uint8_t saveToRegisters(const char* registerName, value_t value) {
	if (registerName[0] == 'L' &&
		registerName[1] == 'F' &&
		registerName[2] == '\0') {

		registerSetLeftFrontReferenceVelocity(value);
		return 1;
	}
	if (registerName[0] == 'R' &&
		registerName[1] == 'F' &&
		registerName[2] == '\0') {

		registerSetRightFrontReferenceVelocity(value);
		return 1;
	}
	if (registerName[0] == 'L' &&
		registerName[1] == 'B' &&
		registerName[2] == '\0') {

		registerSetLeftBackReferenceVelocity(value);
		return 1;
	}
	if (registerName[0] == 'R' &&
		registerName[1] == 'B' &&
		registerName[2] == '\0') {

		registerSetRightBackReferenceVelocity(value);
		return 1;
	}

	return 0;
}

/**
 * Parsing for command RR. Update this function to read from your registers.
 * Be sure to include '\0'!
 *
 * TODO: Very ugly, I'm going to improve it in future :P
 */
uint8_t readFromRegisters(const char* registerName,
		uint32_t* index,
		char* buffer) {

	if (registerName[0] == 'L' &&
		registerName[1] == 'F' &&
		registerName[2] == '\0') {

		uint32_t bufferIndex = *index;

		buffer[bufferIndex++] = 'L';
		buffer[bufferIndex++] = 'F';

		buffer[bufferIndex++] = frameSeparator();

		value_t value = registerGetLeftFrontReferenceVelocity();

		char valueString[10];
		itoa(value, valueString, 10);

		const char* i = &valueString[0];

		while(*i)
			buffer[bufferIndex++] = *(i++);

		buffer[bufferIndex++] = frameSeparator();


		*index = bufferIndex;

		return 1;
	}
	if (registerName[0] == 'R' &&
		registerName[1] == 'F' &&
		registerName[2] == '\0') {

		uint32_t bufferIndex = *index;

		buffer[bufferIndex++] = 'R';
		buffer[bufferIndex++] = 'F';

		buffer[bufferIndex++] = frameSeparator();

		value_t value = registerGetRightFrontReferenceVelocity();

		char valueString[10];
		itoa(value, valueString, 10);

		const char* i = &valueString[0];

		while(*i)
			buffer[bufferIndex++] = *(i++);

		buffer[bufferIndex++] = frameSeparator();


		*index = bufferIndex;

		return 1;
	}
	if (registerName[0] == 'L' &&
		registerName[1] == 'B' &&
		registerName[2] == '\0') {

		uint32_t bufferIndex = *index;

		buffer[bufferIndex++] = 'L';
		buffer[bufferIndex++] = 'B';

		buffer[bufferIndex++] = frameSeparator();

		value_t value = registerGetLeftBackReferenceVelocity();


		char valueString[10];
		itoa(value, valueString, 10);

		const char* i = &valueString[0];

		while(*i)
			buffer[bufferIndex++] = *(i++);

		buffer[bufferIndex++] = frameSeparator();


		*index = bufferIndex;

		return 1;
	}
	if (registerName[0] == 'R' &&
		registerName[1] == 'B' &&
		registerName[2] == '\0') {

		uint32_t bufferIndex = *index;

		buffer[bufferIndex++] = 'R';
		buffer[bufferIndex++] = 'B';

		buffer[bufferIndex++] = frameSeparator();

		value_t value = registerGetRightBackReferenceVelocity();

		char valueString[10];
		itoa(value, valueString, 10);

		const char* i = &valueString[0];

		while(*i)
			buffer[bufferIndex++] = *(i++);

		buffer[bufferIndex++] = frameSeparator();


		*index = bufferIndex;

		return 1;
	}

	return 0;
}

uint8_t indexOfFirstRegisterInMessage(const char* message) {
	uint8_t index = 1;
	uint8_t foundFirstSeparator = 0;
	uint8_t foundSecondSeparator = 0;

	while (!foundSecondSeparator) {
		if (message[index] == frameSeparator()) {
			if (!foundFirstSeparator)
				foundFirstSeparator = 1;
			else
				foundSecondSeparator=1;
		}
		index++;
	}

	return index;
}

uint8_t interpretWriteToRegistersMessage(const char* message,
		command_t commandType,
		uint32_t index,
		uint32_t numberOfParameters) {

	int i=0;
	for (;i<numberOfParameters;i++) {
		char registerNameBuffer[6];
		char registerValueBuffer[6];
		int bufferIndex = 0;
			while(message[index]!='&') {
			registerNameBuffer[bufferIndex] = message[index];
			index++;
			bufferIndex++;
		}
		registerNameBuffer[bufferIndex]='\0';
		index++;
		bufferIndex = 0;
		while(message[index]!='&') {
			registerValueBuffer[bufferIndex] = message[index];
			index++;
			bufferIndex++;
		}
		registerValueBuffer[bufferIndex]='\0';
		index++;
		int value = integerFromString(registerValueBuffer);
			if (!saveToRegisters(registerNameBuffer, value))
			return 0;
	}
	return 1;
}

uint8_t interpretReadFromRegistersMessage(const char* message,
		command_t commandType,
		uint32_t index,
		uint32_t numberOfParameters) {

	char buffer[100];

	buffer[0] = frameBegin();
	buffer[1] = 'O';
	buffer[2] = 'K';
	buffer[3] = frameSeparator();

	uint32_t returnFrameIndex = 4;

	int i=0;
	for (;i<numberOfParameters;i++) {
		char registerNameBuffer[6];

		int bufferIndex = 0;
			while(message[index]!='&') {
			registerNameBuffer[bufferIndex] = message[index];
			index++;
			bufferIndex++;
		}
		registerNameBuffer[bufferIndex]='\0';
		index++;

		if (!readFromRegisters(registerNameBuffer, &returnFrameIndex, buffer))
			return 0;
	}

	buffer[returnFrameIndex++] = frameEnd();
	buffer[returnFrameIndex] = '\0';

	USART1_sendString(buffer);

	return 2;
}

uint8_t interpretReceivedMessage(const char* message) {
	if (!isMessageValid(message))
		return 0;

	command_t commandType = commandTypeFromMessage(message);
	uint8_t index = indexOfFirstRegisterInMessage(message);
	uint8_t numberOfParameters = numberOfParametersFromMessage(message);

	if (commandType == WR)
		return interpretWriteToRegistersMessage(message, commandType, index, numberOfParameters);
	if (commandType == RR)
		return interpretReadFromRegistersMessage(message, commandType, index, numberOfParameters);


	return 1;
}

command_t commandTypeFromMessage(const char* message) {
	if (message[1] == 'R' && message[2] == 'R')
		return RR;
	else if (message[1] == 'W' && message[2] == 'R')
		return WR;
	else if (message[1] == 'O' && message[2] == 'K')
		return OK;
	else if (message[1] == 'N' && message[2] == 'R')
		return NR;
	else if (message[1] == 'R' && message[2] == 'O')
		return RO;

	return NOT_RECOGNIZED;
}

uint8_t isMessageValid(const char* message) {
	if (message[0] != frameBegin())
		return 0;

	if (message[3] != frameSeparator())
		return 0;

	command_t commandType = commandTypeFromMessage(message);

	if (commandType == NOT_RECOGNIZED)
		return 0;


	int numberOfParameters = numberOfParametersFromMessage(message);
	int separatorCounter = 0;
	int endFrameCounter = 0;

	const char* i = &message[4];

	while (*i) {
		if (*i == frameSeparator())
			separatorCounter++;
		if (*i == frameEnd())
			endFrameCounter++;

		i++;
	}

	if (endFrameCounter != 1)
		return 0;

	if (commandType == WR && separatorCounter != numberOfParameters*2 + 1)
		return 0;
	if (commandType == RR && separatorCounter != numberOfParameters + 1)
		return 0;

	return 1;
}

uint32_t numberOfParametersFromMessage(const char* message) {
	int index = 4;
	int bufferIndex =0;
	char numberOfParametersBuffer[6];

	while(message[index]!='&') {
		numberOfParametersBuffer[bufferIndex] = message[index];
		index++;
		bufferIndex++;
	}

	numberOfParametersBuffer[bufferIndex]='\0';

	return integerFromString(numberOfParametersBuffer);
}
