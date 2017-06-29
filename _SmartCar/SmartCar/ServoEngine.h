#ifndef SERVOENGINE_H
#define SERVOENGINE_H

#include <Arduino.h>
#include <ServoTimer2.h>

class ServoEngine
{
private:
	ServoTimer2 *m_servoTimer;
	byte m_pin;
public:
	ServoEngine(ServoTimer2 *servoTimer, byte pin);
	~ServoEngine();
	void setup();
	void goToDegree(byte degree);

};

#endif
