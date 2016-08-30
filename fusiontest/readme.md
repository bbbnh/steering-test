# fusiontest

This sketch emulates a Ford Fusion steering input torque sensor.

A potentiometer should be connected across 3.3v and ground with the 
output on pin A0. The signal lines are pins 9 and 10, and the device and 
gear grounds should be tied together.

IMPORTANT: The device should be booted before the gear is powered up; if 
not, the gear will not function correctly. This means that the uC32 must 
be independently powered.
