/*
 * usart1_interrupt.c
 *
 *  Created on: Mar 3, 2013
 *      Author: Michal Banasiak
 */

#include "usart1_interrupt.h"
#include "usart1.h"
#include "communication/frame.h"

#include "communication/frame_parser_interpreter.h"

#define bufferSize 100 // fuckin C!

uint8_t receiveIndex;
uint8_t isMessageReceived;
char messageBuffer[bufferSize];

void stringReceived(const char* message) {
	uint8_t result = interpretReceivedMessage(message);
//TODO:
	if (result == 1)
		USART1_sendString("$OK*");
	else if (result == 0)
		USART1_sendString("$NR*");
	else if (result == 2) {
		// do nothing
	}

}

void USART1_interrupt(void) {
	char receivedCharacter;

	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) {
		receivedCharacter = (char)USART1_receiveByte();

		if (receivedCharacter == frameBegin()) {
			receiveIndex = 0;
			isMessageReceived = 0;
		}

		if (!isMessageReceived)
			messageBuffer[receiveIndex++] = receivedCharacter;

		if ( receivedCharacter == frameEnd() && messageBuffer[0] == frameBegin() && !isMessageReceived) {
			messageBuffer[receiveIndex++] = '\0';

			stringReceived(messageBuffer);

			isMessageReceived = 1;
			receiveIndex = 0;
		}

		if (receiveIndex == bufferSize-1)
			receiveIndex = bufferSize-2;
	}

	USART_ClearITPendingBit(USART1,USART_IT_RXNE);
}
