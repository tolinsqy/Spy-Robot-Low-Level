/*
 * sonar_pins.h
 *
 *  Created on: Apr 15, 2013
 *      Author: Jarek
 */

#ifndef SONAR_PINS_H_
#define SONAR_PINS_H_
#include "stm32f30x.h"


#define pinOfSonar1TriggerGPIO 		(GPIOB)
#define pinOfSonar1TriggerPin 		(GPIO_Pin_10)
#define pinOfSonar1TriggerCLK		(RCC_AHBPeriph_GPIOB)

#define pinOfSonar1EchoGPIO			(GPIOD)
#define pinOfSonar1EchoPin			(GPIO_Pin_0)
#define pinOfSonar1EchoCLK			(RCC_AHBPeriph_GPIOD)
#define pinOfSonar1EchoEXTIPort		(EXTI_PortSourceGPIOD)
#define pinOfSonar1EchoEXTIPin		(EXTI_PinSource0)
#define pinOfSonar1EchoEXTILine		(EXTI_Line0)
#define pinOfSonar1EchoNVICIRQCH	(EXTI0_IRQn)


#define pinOfSonar2TriggerGPIO 		(GPIOB)
#define pinOfSonar2TriggerPin 		(GPIO_Pin_11)
#define pinOfSonar2TriggerCLK		(RCC_AHBPeriph_GPIOB)

#define pinOfSonar2EchoGPIO			(GPIOD)
#define pinOfSonar2EchoPin			(GPIO_Pin_1)
#define pinOfSonar2EchoCLK			(RCC_AHBPeriph_GPIOD)
#define pinOfSonar2EchoEXTIPort		(EXTI_PortSourceGPIOD)
#define pinOfSonar2EchoEXTIPin		(EXTI_PinSource1)
#define pinOfSonar2EchoEXTILine		(EXTI_Line1)
#define pinOfSonar2EchoNVICIRQCH	(EXTI1_IRQn)



#define pinOfSonar3TriggerGPIO 		(GPIOB)
#define pinOfSonar3TriggerPin 		(GPIO_Pin_12)
#define pinOfSonar3TriggerCLK		(RCC_AHBPeriph_GPIOB)

#define pinOfSonar3EchoGPIO			(GPIOD)
#define pinOfSonar3EchoPin			(GPIO_Pin_2)
#define pinOfSonar3EchoCLK			(RCC_AHBPeriph_GPIOD)
#define pinOfSonar3EchoEXTIPort		(EXTI_PortSourceGPIOD)
#define pinOfSonar3EchoEXTIPin		(EXTI_PinSource2)
#define pinOfSonar3EchoEXTILine		(EXTI_Line2)
#define pinOfSonar3EchoNVICIRQCH	(EXTI2_TS_IRQn)


#define pinOfSonar4TriggerGPIO 		(GPIOB)
#define pinOfSonar4TriggerPin 		(GPIO_Pin_13)
#define pinOfSonar4TriggerCLK		(RCC_AHBPeriph_GPIOB)

#define pinOfSonar4EchoGPIO			(GPIOD)
#define pinOfSonar4EchoPin			(GPIO_Pin_3)
#define pinOfSonar4EchoCLK			(RCC_AHBPeriph_GPIOD)
#define pinOfSonar4EchoEXTIPort		(EXTI_PortSourceGPIOD)
#define pinOfSonar4EchoEXTIPin		(EXTI_PinSource3)
#define pinOfSonar4EchoEXTILine		(EXTI_Line3)
#define pinOfSonar4EchoNVICIRQCH	(EXTI3_IRQn)



#define pinOfSonar5TriggerGPIO 		(GPIOB)
#define pinOfSonar5TriggerPin 		(GPIO_Pin_14)
#define pinOfSonar5TriggerCLK		(RCC_AHBPeriph_GPIOB)

#define pinOfSonar5EchoGPIO			(GPIOD)
#define pinOfSonar5EchoPin			(GPIO_Pin_4)
#define pinOfSonar5EchoCLK			(RCC_AHBPeriph_GPIOD)
#define pinOfSonar5EchoEXTIPort		(EXTI_PortSourceGPIOD)
#define pinOfSonar5EchoEXTIPin		(EXTI_PinSource4)
#define pinOfSonar5EchoEXTILine		(EXTI_Line4)
#define pinOfSonar5EchoNVICIRQCH	(EXTI4_IRQn)
/*inline GPIO_TypeDef* pinOfSonar1TriggerGPIO();
inline uint16_t 	 pinOfSonar1TriggerPin();

inline GPIO_TypeDef* pinOfSonar1EchoGPIO();
inline uint16_t 	 pinOfSonar1EchoPin();
*/

#endif /* SONAR_PINS_H_ */
