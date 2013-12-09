#include <msp430.h>
/*
 * sensors.h
 *
 *  Created on: Dec 5, 2013
 *  Author: C2C Michael Bentley
 *
 *  This library can enable the analog-to-digital converter built in to the MSP430 and return values from three different distance sensors.
 *
 */

#ifndef SENSORS_H_
#define SENSORS_H_

// Initializes the ADC10 subsystem and the LED outputs on the MSP430.
void initADCandPins();

// Returns a value between 0x000 and 0x3FF from the Left sensor.
unsigned int getLeftSensor();

// Returns a value between 0x000 and 0x3FF from the Right sensor.
unsigned int getRightSensor();

// Returns a value between 0x000 and 0x3FF from the Center sensor.
unsigned int getCenterSensor();

#endif /* SENSORS_H_ */
