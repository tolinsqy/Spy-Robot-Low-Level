/*
 * usart1.h
 *
 *  Created on: Dec 14, 2012
 *      Author: Michal Banasiak
 */

#ifndef USART1_H_
#define USART1_H_

#include "stm32f30x.h"

void USART1_sendByte(uint8_t data);
void USART1_sendString(const char* ptr);

uint8_t USART1_receiveByte();

#endif /* USART1_H_ */
