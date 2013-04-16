/*
 * timers_interrupt.c
 *
 *  Created on: Apr 15, 2013
 *      Author: Jarek
 */
#include "stm32f3_discovery.h"
#include "stm32f30x.h"
#include "timers_interrupt.h"
#include "sonar/sonar.h"
#include "utilities/delay_us.h"

extern __IO uint16_t CCR1_Val;

volatile uint16_t capture =0;


void TIM4_interrupt()
{
	if (TIM_GetITStatus(TIM4, TIM_IT_CC1 ) != RESET) {
		if (SONAR_timeout())
			STM_EVAL_LEDToggle(LED5);
		STM_EVAL_LEDToggle(LED4);
		SONAR_next();
		SONAR_trigger(); //start sonar
		capture = TIM_GetCapture1(TIM4 );
		TIM_SetCompare1(TIM4, capture + CCR1_Val);
		TIM_ClearITPendingBit(TIM4, TIM_IT_CC1 );
	} else
	/* delay_us timer */
	if (TIM_GetITStatus(TIM4, TIM_IT_CC2 ) != RESET) {

		/*turning off CC2 interrupt*/
		TIM_ITConfig(TIM4, TIM_IT_CC2, DISABLE);
		delay_us_timeout();
		TIM_ClearITPendingBit(TIM4, TIM_IT_CC2 );
	}
}
