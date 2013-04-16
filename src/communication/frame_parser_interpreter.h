/*
 * frame_parser.h
 *
 *  Created on: Mar 4, 2013
 *      Author: Michal Banasiak
 */

#ifndef FRAME_PARSER_H_
#define FRAME_PARSER_H_

#include "frame.h"
#include "registers/registers.h"

uint8_t interpretReceivedMessage(const char* message);


#endif /* FRAME_PARSER_H_ */
