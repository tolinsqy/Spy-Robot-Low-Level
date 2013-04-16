/*
 * vcnl4000.h
 *
 *  Created on: Apr 12, 2013
 *      Author: Jarek
 */

#ifndef VCNL4000_H_
#define VCNL4000_H_

const uint16_t VCNL4000_STATUS_OK;
const uint16_t VCNL4000_STATUS_FAIL;
const uint16_t VCNL4000_STATUS_TIMEOUT;

uint16_t VCNL4000_Setup();

uint16_t VCNL4000_ReadProximity();



#endif /* VCNL4000_H_ */
