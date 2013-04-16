/*
 * interrupts.h
 *
 *  Created on: Dec 14, 2012
 *      Author: Michal Banasiak
 */

#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "stm32f30x.h"

void SysTick_Handler(void);
void USART1_IRQHandler(void);
void TIM4_IRQHandler(void);

void EXTI0_IRQHandler(void);
void EXTI1_IRQHandler(void);
void EXTI2_TS_IRQHandler(void);
void EXTI3_IRQHandler(void);
void EXTI4_IRQHandler(void);

//void EXTI15_10_IRQHandler(void);
#endif /* INTERRUPTS_H_ */
