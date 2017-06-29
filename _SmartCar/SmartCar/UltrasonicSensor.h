#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

#include <Arduino.h>
#include "Types.h"
class UltrasonicSensor
{
private:
	byte m_echoPin;
	byte m_trigPin;
	int getDuration();
public:
	UltrasonicSensor(byte echoPin, byte trigPin);
	~UltrasonicSensor();
	int getDistanceCm();
	int getDistanceInches();

};

#endif