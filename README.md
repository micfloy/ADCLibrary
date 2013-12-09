ADCLibrary
==========

This library contains 4 basic functions to interface with the analog sensors on the ECE382 robot.

## Description

There are three sensors on the ECE382 robot.  A left distance sensor, a right distance sensor and a forward
distance sensor (referred to here as "center").  The sensors can return a value of 0-5V.  In a well-lighted
room with nothing nearby the sensors return about 1.2V.  A good value to trigger on for walls is a little above 3V.

The ADC conversion provides a quantized value between 0 and 1023 in the `ADC10MEM` register.

## Functions

`initADCandPins()` will initialize the ADC10 subsystem as well as the MSP430's two controllable LEDs.  These may 
not be necessary but are convenient to have, just the same.

`getLeftSensor()` returns a value taken from the robot's left sensor between 0 and 1023, stored in `ADC10MEM`.

`getRightSensor()` returns the value taken from the robot's right sensor.

`getCenterSensor()` returns the value taken from the robot's forward-facing, center sensor.
