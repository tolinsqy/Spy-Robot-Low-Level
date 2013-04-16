/*
 * delay_us.c
 *
 *  Created on: Apr 15, 2013
 *      Author: Jarek
 */

#include "delay_us.h"

volatile uint16_t delayUsTimeout = 1;


inline void delay_us_timeout()
{
	delayUsTimeout=0;
}

inline uint16_t delay_us(uint16_t us)
{
	/* TODO reimplement delay_us to use SysTick interrupt*/
    volatile uint16_t capture = TIM_GetCapture2(TIM4);
    delayUsTimeout = 1;
    TIM_SetCompare2(TIM4, capture + us);
    TIM_ITConfig(TIM4, TIM_IT_CC2, ENABLE);
    while(!delayUsTimeout);
    return TIM_GetCapture2(TIM4)-capture;
}
