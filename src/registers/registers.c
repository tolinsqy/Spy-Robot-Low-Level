/*
 * registers.c
 *
 *  Created on: Mar 15, 2013
 *      Author: Michal Banasiak
 */


#include "registers.h"
#include "stm32f30x.h"

value_t registers[numberOfRegisters];


const value_t leftFrontReferenceVelocity = 	0;
const value_t leftBackReferenceVelocity = 	1;
const value_t rightFrontReferenceVelocity = 2;
const value_t rightBackReferenceVelocity = 	3;

const value_t leftFrontCurrentVelocity = 	4;
const value_t leftBackCurrentVelocity = 	5;
const value_t rightFrontCurrentVelocity = 	6;
const value_t rightBackCurrentVelocity = 	7;

const value_t VCNL4000_1			=20;

const value_t Sonar1Distance		=21;
const value_t Sonar2Distance		=22;
const value_t Sonar3Distance		=23;
const value_t Sonar4Distance		=24;
const value_t Sonar5Distance		=25;

const value_t Sonar1Threshold	=26;
const value_t Sonar2Threshold	=27;
const value_t Sonar3Threshold	=28;
const value_t Sonar4Threshold	=29;
const value_t Sonar5Threshold	=30;


inline value_t registerGetLeftFrontReferenceVelocity() {
	return registers[leftFrontReferenceVelocity];
}

inline value_t registerGetLeftBackReferenceVelocity() {
	return registers[leftBackReferenceVelocity];
}

inline value_t registerGetRightFrontReferenceVelocity() {
	return registers[rightFrontReferenceVelocity];
}

inline value_t registerGetRightBackReferenceVelocity() {
	return registers[rightBackReferenceVelocity];
}

inline void registerSetLeftFrontReferenceVelocity(value_t velocity) {
	registers[leftFrontReferenceVelocity] = velocity;
}

inline void registerSetLeftBackReferenceVelocity(value_t velocity) {
	registers[leftBackReferenceVelocity] = velocity;
}

inline void registerSetRightFrontReferenceVelocity(value_t velocity) {
	registers[rightFrontReferenceVelocity] = velocity;
}

inline void registerSetRightBackReferenceVelocity(value_t velocity) {
	registers[rightBackReferenceVelocity] = velocity;
}

inline value_t registerGetLeftFrontCurrentVelocity() {
	return registers[leftFrontCurrentVelocity];
}

inline value_t registerGetLeftBackCurrentVelocity() {
	return registers[leftBackCurrentVelocity];
}

inline value_t registerGetRightFrontCurrentVelocity() {
	return registers[rightFrontCurrentVelocity];
}

inline value_t registerGetRightBackCurrentVelocity() {
	return registers[rightBackCurrentVelocity];
}

inline value_t registerGetVCNL4000_1() {

	return registers[VCNL4000_1];
}

inline void registerSetVCNL4000_1(value_t val) {

	registers[VCNL4000_1] = val;
}

inline value_t registerGetSonar1Distance(){

	return registers[Sonar1Distance];
}
inline void registerSetSonar1Distance(value_t val){

	registers[Sonar1Distance] = val;
}
inline value_t registerGetSonar2Distance(){

	return registers[Sonar2Distance];
}
inline void registerSetSonar2Distance(value_t val){

	registers[Sonar2Distance] = val;
}
inline value_t registerGetSonar3Distance(){

	return registers[Sonar3Distance];
}
inline void registerSetSonar3Distance(value_t val){

	registers[Sonar3Distance] = val;
}

inline value_t registerGetSonar4Distance(){

	return registers[Sonar4Distance];
}
inline void registerSetSonar4Distance(value_t val){

	registers[Sonar4Distance] = val;
}

inline value_t registerGetSonar5Distance(){

	return registers[Sonar5Distance];
}
inline void registerSetSonar5Distance(value_t val){

	registers[Sonar5Distance] = val;
}


inline value_t registerGetSonar1Threshold(){

	return registers[Sonar1Threshold];
}
inline void registerSetSonar1Threshold(value_t val){

	registers[Sonar1Threshold] = val;
}
inline value_t registerGetSonar2Threshold(){

	return registers[Sonar2Threshold];
}
inline void registerSetSonar2Threshold(value_t val){

	registers[Sonar2Threshold] = val;
}
inline value_t registerGetSonar3Threshold(){

	return registers[Sonar3Threshold];
}
inline void registerSetSonar3Threshold(value_t val){

	registers[Sonar3Threshold] = val;
}

inline value_t registerGetSonar4Threshold(){

	return registers[Sonar4Threshold];
}
inline void registerSetSonar4Threshold(value_t val){

	registers[Sonar4Threshold] = val;
}

inline value_t registerGetSonar5Threshold(){

	return registers[Sonar5Threshold];
}
inline void registerSetSonar5Threshold(value_t val){

	registers[Sonar5Threshold] = val;
}

inline void registerSetWithIndex(uint32_t index, value_t value) {
	registers[index] = value;
}

inline value_t registerGetWithIndex(uint32_t index) {
	return registers[index];
}
