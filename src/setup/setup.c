/*
 * setup.c
 *
 *  Created on: Dec 12, 2012
 *      Author: Michal Banasiak
 */

#include "setup.h"
#include "stm32f3_discovery.h"
#include "usart1/usart1_setup.h"
#include "utilities/leds.h"
#include "motors/motors_setup.h"
#include "registers/registers_setup.h"
#include "i2c_devices/vcnl4000.h"
#include "sonar/sonar_setup.h"
#include "timers/timers_setup.h"

void setup() {
	SysTick_Config(72);

	setupUSART1();

	ledsSetup();

	motorsSetup();

	registersSetup();

	sonarSetup();

	TIM4_Initialization();
	//VCNL4000_Setup();
}


