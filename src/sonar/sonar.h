/*
 * sonar.h
 *
 *  Created on: Apr 15, 2013
 *      Author: Jarek
 */

#ifndef SONAR_H_
#define SONAR_H_



inline void usplus();

inline void SONAR_next();
void SONAR_trigger();
void SONAR_echo();


uint16_t SONAR_timeout();

#endif /* SONAR_H_ */
