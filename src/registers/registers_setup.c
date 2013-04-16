/*
 * registers_setup.c
 *
 *  Created on: Mar 15, 2013
 *      Author: Michal Banasiak
 */


#include "registers_setup.h"
#include "registers.h"

void registersSetup() {
	int i=0;
	for (; i<numberOfRegisters;i++)
		registerSetWithIndex(i,0);
}
