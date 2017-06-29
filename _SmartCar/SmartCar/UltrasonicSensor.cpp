#include "UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor(byte echoPin, byte trigPin)
	: m_echoPin(echoPin),
	m_trigPin(trigPin)
{
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
}
UltrasonicSensor::~UltrasonicSensor()
{

}

int UltrasonicSensor::getDuration()
{
	int duration = 0;
	// The sensor is triggered by a HIGH pulse of 10 or more microseconds.
	// Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
	digitalWrite(m_trigPin, LOW);
	delayMicroseconds(5);
	digitalWrite(m_trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(m_trigPin, LOW);
	// Read the signal from the sensor: a HIGH pulse whose
	// duration is the time (in microseconds) from the sending
	// of the ping to the reception of its echo off of an object.
	pinMode(m_echoPin, INPUT);
	duration = pulseIn(m_echoPin, HIGH);
	
	return duration;
}

int UltrasonicSensor::getDistanceCm()
{
	int duration = 0;
	unsigned int cm = 0;
	duration = getDuration();
	cm = (duration / 2) / 29.1;
	if (cm != 0)
	{
		return cm;
	}
	else
	{
		return ERR_LENGTH;
	}
		
}

int UltrasonicSensor::getDistanceInches()
{
	int duration = 0, inches = 0;
	duration = getDuration();
	inches = (duration / 2) / 74;
	return inches;
}