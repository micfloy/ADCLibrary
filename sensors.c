/*
 * sensors.c
 *
 *  Created on: Dec 5, 2013
 *      Author: C15Michael.Bentley
 */
#include "sensors.h"

// Initializes ADC10 and the LED pins
void initADCandPins() {
	ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE;
	ADC10CTL1 |= ADC10SSEL1 | ADC10SSEL0;
	ADC10CTL1 = ADC10DIV_7;				// Divides the clock to prevent loading

	P1DIR |= BIT0;
	P1DIR |= BIT6;
}

// Returns a value between 0 and 1023 from the left sensor.
unsigned int getLeftSensor() {
	ADC10CTL0 &= ~ENC;				// Must clear ENC control before changing the ADC10
	ADC10CTL1 = INCH_3;				// Set input
	ADC10AE0 |= BIT3;
	ADC10CTL0 |= ENC + ADC10SC;		// Sets the ENC control to continue operation

	__bis_SR_register(CPUOFF + GIE);// Turns off the CPU and waits for the interrupt from ADC10MEM

	return ADC10MEM;
}

// Returns a value between 0 and 1023 from the right sensor.
unsigned int getRightSensor() {
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 = INCH_4;
	ADC10AE0 |= BIT4;
	ADC10CTL0 |= ENC + ADC10SC;

	__bis_SR_register(CPUOFF + GIE);

	return ADC10MEM;
}

// Returns a value between 0 and 1023 from the center sensor.
unsigned int getCenterSensor() {
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 = INCH_5;
	ADC10AE0 |= BIT5;
	ADC10CTL0 |= ENC + ADC10SC;

	__bis_SR_register(CPUOFF + GIE);

	return ADC10MEM;
}

// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void) {

	__bic_SR_register_on_exit(CPUOFF);
// Clear CPUOFF bit from 0(SR)
}
