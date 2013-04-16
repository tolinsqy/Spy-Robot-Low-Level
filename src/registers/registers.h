/*
 * registers.h
 *
 *  Created on: Mar 15, 2013
 *      Author: Michal Banasiak
 */

/*
 * TODO Some registers shouldn't be writable, like those with sensor data.
 * Those registers should be read-only or protected
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "stm32f30x.h"

typedef int32_t value_t;

#define numberOfRegisters 31

inline value_t registerGetLeftFrontReferenceVelocity();
inline value_t registerGetLeftBackReferenceVelocity();
inline value_t registerGetRightFrontReferenceVelocity();
inline value_t registerGetRightBackReferenceVelocity();

inline void registerSetLeftFrontReferenceVelocity(value_t velocity);
inline void registerSetLeftBackReferenceVelocity(value_t velocity);
inline void registerSetRightFrontReferenceVelocity(value_t velocity);
inline void registerSetRightBackReferenceVelocity(value_t velocity);

inline value_t registerGetLeftFrontCurrentVelocity();
inline value_t registerGetLeftBackCurrentVelocity();
inline value_t registerGetRightFrontCurrentVelocity();
inline value_t registerGetRightBackCurrentVelocity();

inline value_t registerGetVCNL4000_1();
inline void registerSetVCNL4000_1(value_t val);//shouldn't even exist

inline value_t registerGetSonar1Distance();
inline value_t registerGetSonar2Distance();
inline value_t registerGetSonar3Distance();
inline value_t registerGetSonar4Distance();
inline value_t registerGetSonar5Distance();

inline void registerSetSonar1Distance(value_t val);
inline void registerSetSonar2Distance(value_t val);
inline void registerSetSonar3Distance(value_t val);
inline void registerSetSonar4Distance(value_t val);
inline void registerSetSonar5Distance(value_t val);


inline value_t registerGetSonar1Threshold();
inline value_t registerGetSonar2Threshold();
inline value_t registerGetSonar3Threshold();
inline value_t registerGetSonar4Threshold();
inline value_t registerGetSonar5Threshold();

inline void registerSetSonar1Threshold(value_t val);
inline void registerSetSonar2Threshold(value_t val);
inline void registerSetSonar3Threshold(value_t val);
inline void registerSetSonar4Threshold(value_t val);
inline void registerSetSonar5Threshold(value_t val);


inline void registerSetWithIndex(uint32_t index, value_t value);
inline value_t registerGetWithIndex(uint32_t index);

#endif /* REGISTERS_H_ */
