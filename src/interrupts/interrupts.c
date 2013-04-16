/*
 * interrupts.c
 *
 *  Created on: Dec 14, 2012
 *      Author: Michal Banasiak
 */

#include "interrupts.h"
#include "stm32f3_discovery.h"
#include "usart1/usart1_interrupt.h"
#include "timers/timers_interrupt.h"
#include "sonar/sonar.h"


void SysTick_Handler(void) {
	usplus();
}

void USART1_IRQHandler(void) {
	USART1_interrupt();
}
void TIM4_IRQHandler(void)
{
	TIM4_interrupt();
}

void EXTI0_IRQHandler(void){
	if (EXTI_GetITStatus(EXTI_Line0 )) {

			SONAR_echo(0);
			EXTI_ClearITPendingBit(EXTI_Line0 );

	}
}

void EXTI1_IRQHandler(void){
	if (EXTI_GetITStatus(EXTI_Line1 )) {

			SONAR_echo(1);
			EXTI_ClearITPendingBit(EXTI_Line1 );

	}
}

void EXTI2_TS_IRQHandler(void){
	if (EXTI_GetITStatus(EXTI_Line2 )) {

			SONAR_echo(2);
			EXTI_ClearITPendingBit(EXTI_Line2 );

	}
}

void EXTI3_IRQHandler(void){
	if (EXTI_GetITStatus(EXTI_Line3 )) {

			SONAR_echo(3);
			EXTI_ClearITPendingBit(EXTI_Line3 );

	}
}

void EXTI4_IRQHandler(void){
	if (EXTI_GetITStatus(EXTI_Line4 )) {

			SONAR_echo(4);
			EXTI_ClearITPendingBit(EXTI_Line4 );

	}
}


//void EXTI15_10_IRQHandler(void)
//{
//	STM_EVAL_LEDToggle(LED8);
//	if (EXTI_GetITStatus(EXTI_Line15 )) {
//
//		SONAR_echo();
//		EXTI_ClearITPendingBit(EXTI_Line15 );
//
//	}/* else if (EXTI_GetITStatus(EXTI_Line12 )) {
//
//		EXTI_ClearITPendingBit(EXTI_Line12 );
//
//	}*/
//	//Check if EXTI_Line0 is asserted
//}
