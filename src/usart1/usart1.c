/*
 * usart1.c
 *
 *  Created on: Dec 14, 2012
 *      Author: Michal Banasiak
 */

#include "usart1.h"

void USART1_sendByte(uint8_t data) {
	while ( !USART_GetFlagStatus(USART1, USART_FLAG_TXE));
	USART_SendData(USART1, data);
}

void USART1_sendString(const char* ptr) {
	do {
		USART1_sendByte(*ptr);
		ptr++;
	}
	while (*ptr);
}

uint8_t USART1_receiveByte() {
	return USART_ReceiveData(USART1);
}
