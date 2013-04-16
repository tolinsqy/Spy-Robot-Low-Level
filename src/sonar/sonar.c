/*
 * sonar.c
 *
 *  Created on: Apr 15, 2013
 *      Author: Jarek
 */
#include "stm32f3_discovery.h"
#include "utilities/delay_us.h"
#include "registers/registers.h"
#include "sonar_pins.h"
#include "motors/motors.h"


#define NUMBER_OF_SONARS 			(3)

#define TEMPORARY_SONAR_THRESHOLD 	(50)

#define SONAR_OUT_OF_RANGE 			(6000)


extern const value_t Sonar1Distance;

volatile uint32_t ustimer=0;

GPIO_TypeDef* 	SonarTriggerGPIOs[5]={pinOfSonar1TriggerGPIO, pinOfSonar2TriggerGPIO,pinOfSonar3TriggerGPIO,
									 pinOfSonar4TriggerGPIO, pinOfSonar5TriggerGPIO};
uint16_t	  	SonarTriggerPins[5]={pinOfSonar1TriggerPin, pinOfSonar2TriggerPin, pinOfSonar3TriggerPin,
									 pinOfSonar4TriggerPin, pinOfSonar5TriggerPin};
GPIO_TypeDef* 	SonarEchoGPIOs[5]={pinOfSonar1EchoGPIO, pinOfSonar2EchoGPIO,pinOfSonar3EchoGPIO,
									 pinOfSonar4EchoGPIO, pinOfSonar5EchoGPIO};
uint16_t		SonarEchoPins[5]={pinOfSonar1EchoPin, pinOfSonar2EchoPin,pinOfSonar3EchoPin,
									pinOfSonar4EchoPin, pinOfSonar5EchoPin};

volatile int16_t		TriggeredSonar=0;

enum SonarMeasureStatus {SONAR_TRIGGERED=1, SONAR_WAITING_FOR_ECHO=2, SONAR_DISTANCE_MEASURED=3,SONAR_ERROR_UNKNOWN=100, SONAR_TIMEOUT=101, SONAR_CHANNEL_MISMATCH=102};

volatile int16_t		SonarStatus=0;


inline void usplus()
{
	++ustimer;
}

//uint32_t sonar_rissing_edge=1;
uint32_t sonar_compare=0;
uint32_t sonar_length=0;

inline void SONAR_next()
{
	if(++TriggeredSonar>=NUMBER_OF_SONARS)
		TriggeredSonar=0;
}

uint16_t SONAR_timeout()
{
	if(SonarStatus!=SONAR_DISTANCE_MEASURED)
	{
		registerSetWithIndex(Sonar1Distance+TriggeredSonar,SONAR_OUT_OF_RANGE);
		return 1;
	}
	else return 0;
}

void SONAR_trigger()
{
	GPIO_SetBits(SonarTriggerGPIOs[TriggeredSonar],SonarTriggerPins[TriggeredSonar]);
	STM_EVAL_LEDOn(LED6);
	delay_us(10);//wait for 10us
	STM_EVAL_LEDOff(LED6);
	GPIO_ResetBits(SonarTriggerGPIOs[TriggeredSonar],SonarTriggerPins[TriggeredSonar]);//turn off trigger*/
	sonar_length=0;
	SonarStatus=SONAR_TRIGGERED;
	//now wait for EXT1 interrupt to fire on echo*/

	/*GPIO_SetBits(pinOfSonar1TriggerGPIO,pinOfSonar1TriggerPin);//turn on trigger
	STM_EVAL_LEDOn(LED6);
	delay_us(10);//wait for 10us
	STM_EVAL_LEDOff(LED6);
	GPIO_ResetBits(pinOfSonar1TriggerGPIO,pinOfSonar1TriggerPin);//turn off trigger
	sonar_length=0;
	sonar_rissing_edge=0;*/


}

void SONAR_echo(uint16_t sonarIRQChannel)
{
	if(sonarIRQChannel==TriggeredSonar)
	{
		//	SonarStatus=SONAR_CHANNEL_MISMATCH;
		//else
		if (SonarStatus == SONAR_TRIGGERED) //turn on tim4 ch1 cc interrupt
				{
			sonar_compare = ustimer; //get time
				//sonar_rissing_edge=1;
			SonarStatus = SONAR_WAITING_FOR_ECHO;
		} else if (SonarStatus == SONAR_WAITING_FOR_ECHO) {
			sonar_length = ((ustimer - sonar_compare) * 10) / 58;
				//sonar_length-=;
			registerSetWithIndex(Sonar1Distance + TriggeredSonar, sonar_length);
			if (sonar_length < TEMPORARY_SONAR_THRESHOLD) {
				motorAllStop();
			}
				//registerSetSonar1Distance();
			SonarStatus = SONAR_DISTANCE_MEASURED;
			//sonar_rissing_edge=2;
		} else {
			SonarStatus = SONAR_ERROR_UNKNOWN;
			STM_EVAL_LEDToggle(LED10);
		}
	}
	else
	{
		SonarStatus = SONAR_CHANNEL_MISMATCH;
		STM_EVAL_LEDToggle(LED9);
	}
}
