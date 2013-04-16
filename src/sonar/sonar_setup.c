/*
 * sonar_setup.c
 *
 *  Created on: Apr 15, 2013
 *      Author: Jarek
 */
#include "stm32f30x.h"
#include "sonar_pins.h"

	GPIO_InitTypeDef        GPIO_InitStructure;
	//EXTI structure to init EXT
	EXTI_InitTypeDef EXTI_InitStructure;
	//NVIC structure to set up NVIC controller
	NVIC_InitTypeDef NVIC_InitStructure;


void SONAR1_initialization()
{
	RCC_AHBPeriphClockCmd(pinOfSonar1TriggerCLK, ENABLE);


	  /* Configure PB10 in output pushpull mode */
	GPIO_InitStructure.GPIO_Pin = pinOfSonar1TriggerPin;// | GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(pinOfSonar1TriggerGPIO, &GPIO_InitStructure);


	RCC_AHBPeriphClockCmd(pinOfSonar1EchoCLK, ENABLE);

	/* Configure pinOfSonar1EchoPin pin as input floating */
	GPIO_InitStructure.GPIO_Pin = pinOfSonar1EchoPin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(pinOfSonar1EchoGPIO, &GPIO_InitStructure);

	/* Enable SYSCFG clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);


	/* Connect EXTI0 Line to PA11 pin */
	SYSCFG_EXTILineConfig(pinOfSonar1EchoEXTIPort, pinOfSonar1EchoEXTIPin );

	/* Configure EXTI11 line */
	EXTI_InitStructure.EXTI_Line = pinOfSonar1EchoEXTILine;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	/* Enable and set EXTI0 Interrupt to the lowest priority */
	NVIC_InitStructure.NVIC_IRQChannel = pinOfSonar1EchoNVICIRQCH;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;// 0x0F;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;// 0x0F;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void SONAR2_initialization()
{
	RCC_AHBPeriphClockCmd(pinOfSonar2TriggerCLK, ENABLE);


	  /* Configure PB10 in output pushpull mode */
	GPIO_InitStructure.GPIO_Pin = pinOfSonar2TriggerPin;// | GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(pinOfSonar2TriggerGPIO, &GPIO_InitStructure);


	RCC_AHBPeriphClockCmd(pinOfSonar2EchoCLK, ENABLE);

	/* Configure pinOfSonar2EchoPin pin as input floating */
	GPIO_InitStructure.GPIO_Pin = pinOfSonar2EchoPin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(pinOfSonar2EchoGPIO, &GPIO_InitStructure);

	/* Enable SYSCFG clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);


	/* Connect EXTI0 Line to PA11 pin */
	SYSCFG_EXTILineConfig(pinOfSonar2EchoEXTIPort, pinOfSonar2EchoEXTIPin );

	/* Configure EXTI11 line */
	EXTI_InitStructure.EXTI_Line = pinOfSonar2EchoEXTILine;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	/* Enable and set EXTI0 Interrupt to the lowest priority */
	NVIC_InitStructure.NVIC_IRQChannel = pinOfSonar2EchoNVICIRQCH;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;// 0x0F;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;// 0x0F;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void SONAR3_initialization()
{
	RCC_AHBPeriphClockCmd(pinOfSonar3TriggerCLK, ENABLE);


	  /* Configure PB10 in output pushpull mode */
	GPIO_InitStructure.GPIO_Pin = pinOfSonar3TriggerPin;// | GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(pinOfSonar3TriggerGPIO, &GPIO_InitStructure);


	RCC_AHBPeriphClockCmd(pinOfSonar3EchoCLK, ENABLE);

	/* Configure pinOfSonar3EchoPin pin as input floating */
	GPIO_InitStructure.GPIO_Pin = pinOfSonar3EchoPin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(pinOfSonar3EchoGPIO, &GPIO_InitStructure);

	/* Enable SYSCFG clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);


	/* Connect EXTI0 Line to PA11 pin */
	SYSCFG_EXTILineConfig(pinOfSonar3EchoEXTIPort, pinOfSonar3EchoEXTIPin );

	/* Configure EXTI11 line */
	EXTI_InitStructure.EXTI_Line = pinOfSonar3EchoEXTILine;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	/* Enable and set EXTI0 Interrupt to the lowest priority */
	NVIC_InitStructure.NVIC_IRQChannel = pinOfSonar3EchoNVICIRQCH;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;// 0x0F;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;// 0x0F;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void SONAR4_initialization()
{
	RCC_AHBPeriphClockCmd(pinOfSonar4TriggerCLK, ENABLE);


	  /* Configure PB10 in output pushpull mode */
	GPIO_InitStructure.GPIO_Pin = pinOfSonar4TriggerPin;// | GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(pinOfSonar4TriggerGPIO, &GPIO_InitStructure);


	RCC_AHBPeriphClockCmd(pinOfSonar4EchoCLK, ENABLE);

	/* Configure pinOfSonar4EchoPin pin as input floating */
	GPIO_InitStructure.GPIO_Pin = pinOfSonar4EchoPin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(pinOfSonar4EchoGPIO, &GPIO_InitStructure);

	/* Enable SYSCFG clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);


	/* Connect EXTI0 Line to PA11 pin */
	SYSCFG_EXTILineConfig(pinOfSonar4EchoEXTIPort, pinOfSonar4EchoEXTIPin );

	/* Configure EXTI11 line */
	EXTI_InitStructure.EXTI_Line = pinOfSonar4EchoEXTILine;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	/* Enable and set EXTI0 Interrupt to the lowest priority */
	NVIC_InitStructure.NVIC_IRQChannel = pinOfSonar4EchoNVICIRQCH;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;// 0x0F;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;// 0x0F;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void SONAR5_initialization()
{
	RCC_AHBPeriphClockCmd(pinOfSonar5TriggerCLK, ENABLE);


	  /* Configure PB10 in output pushpull mode */
	GPIO_InitStructure.GPIO_Pin = pinOfSonar5TriggerPin;// | GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(pinOfSonar5TriggerGPIO, &GPIO_InitStructure);


	RCC_AHBPeriphClockCmd(pinOfSonar5EchoCLK, ENABLE);

	/* Configure pinOfSonar5EchoPin pin as input floating */
	GPIO_InitStructure.GPIO_Pin = pinOfSonar5EchoPin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(pinOfSonar5EchoGPIO, &GPIO_InitStructure);

	/* Enable SYSCFG clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);


	/* Connect EXTI0 Line to PA11 pin */
	SYSCFG_EXTILineConfig(pinOfSonar5EchoEXTIPort, pinOfSonar5EchoEXTIPin );

	/* Configure EXTI11 line */
	EXTI_InitStructure.EXTI_Line = pinOfSonar5EchoEXTILine;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	/* Enable and set EXTI0 Interrupt to the lowest priority */
	NVIC_InitStructure.NVIC_IRQChannel = pinOfSonar5EchoNVICIRQCH;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;// 0x0F;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;// 0x0F;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void sonarSetup()
{
	SONAR1_initialization();
	SONAR2_initialization();
	SONAR3_initialization();
	/*SONAR4_initialization();
	SONAR5_initialization();*/
}
