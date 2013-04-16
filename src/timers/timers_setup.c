
/*
 * timers_setup.c
 *
 *  Created on: Apr 15, 2013
 *      Author: Jarek
 */


#include "timers_setup.h"
#include "stm32f30x.h"

#include "interrupts/interrupts.h"

__IO uint16_t CCR1_Val = 50000;// 1us
//__IO uint16_t CCR2_Val = 720;//10us
//__IO uint16_t CCR3_Val = 13654;
//__IO uint16_t CCR4_Val = 6826;


void TIM4_NVIC_Initialization(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;

	  /* TIM4 clock enable */
	  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

	  /* Enable the TIM4 gloabal Interrupt */
	  NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
	  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	  NVIC_Init(&NVIC_InitStructure);

	  /* Initialize Leds mounted on STM32F3-Discovery EVAL board */
	 // STM_EVAL_LEDInit(LED3);
	 // STM_EVAL_LEDInit(LED4);
	 // STM_EVAL_LEDInit(LED5);
	 // STM_EVAL_LEDInit(LED6);

	  /* Turn on LED3, LED4, LED5 and LED6 */
	  //STM_EVAL_LEDOn(LED3);
	  //STM_EVAL_LEDOn(LED4);
	 // STM_EVAL_LEDOn(LED5);
	 // STM_EVAL_LEDOn(LED6);
}

TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
TIM_OCInitTypeDef  TIM_OCInitStructure;

void TIM4_Initialization()
{
	TIM4_NVIC_Initialization();
	/* -----------------------------------------------------------------------
	    TIM4 Configuration: Output Compare Timing Mode:

	    In this example TIM4 input clock (TIM4CLK) is set to 2 * APB1 clock (PCLK1),
	    since APB1 prescaler is different from 1.
	      TIM4CLK = 2 * PCLK1
	      PCLK1 = HCLK / 2
	      => TIM4CLK = HCLK = SystemCoreClock

	    To get TIM3 counter clock at 72 MHz, the prescaler is computed as follows:
	       Prescaler = (TIM3CLK / TIM3 counter clock) - 1
	       Prescaler = ((SystemCoreClock) /72 MHz) - 1

	    CC1 update rate = TIM3 counter clock / CCR1_Val = 1757.77 Hz
	    ==> Toggling frequency = 878.88 Hz

	    C2 update rate = TIM3 counter clock / CCR2_Val = 2636.49 Hz
	    ==> Toggling frequency = 1318.24 Hz

	    CC3 update rate = TIM3 counter clock / CCR3_Val = 5273.18 Hz
	    ==> Toggling frequency = 2636.59 Hz

	    CC4 update rate = TIM3 counter clock / CCR4_Val = 10547.9 Hz
	    ==> Toggling frequency = 5273.95 Hz

	    Note:
	     SystemCoreClock variable holds HCLK frequency and is defined in system_stm32f3xx.c file.
	     Each time the core clock (HCLK) changes, user had to call SystemCoreClockUpdate()
	     function to update SystemCoreClock variable value. Otherwise, any configuration
	     based on this variable will be incorrect.
	  ----------------------------------------------------------------------- */


	 /* Compute the prescaler value */
	  uint16_t PrescalerValue = (uint16_t) ((SystemCoreClock) / 1000000) - 1;

	  /* Time base configuration */
	  TIM_TimeBaseStructure.TIM_Period = 65535;
	  TIM_TimeBaseStructure.TIM_Prescaler = 0;
	  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

	  TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

	  /* Prescaler configuration */
	  TIM_PrescalerConfig(TIM4, PrescalerValue, TIM_PSCReloadMode_Immediate);

	  /* Output Compare Timing Mode configuration: Channel1 */
	  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Timing;
	  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	  TIM_OCInitStructure.TIM_Pulse = CCR1_Val;
	  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

	  TIM_OC1Init(TIM4, &TIM_OCInitStructure);

	  TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Disable);

	  /* Output Compare Timing Mode configuration: Channel2 */
	  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	  TIM_OCInitStructure.TIM_Pulse = 10;

	  TIM_OC2Init(TIM4, &TIM_OCInitStructure);

	  TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Disable);


	  /* TIM Interrupts enable */
	  TIM_ITConfig(TIM4, TIM_IT_CC1, ENABLE);

	  /* TIM4 enable counter */
	  TIM_Cmd(TIM4, ENABLE);

}
/*
void TIMERS_setup()
{


}*/
