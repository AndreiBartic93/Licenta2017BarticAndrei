#ifndef LED_H
#define LED_H

#include <Arduino.h>

class Led
{
private:
	byte m_pinLed;
public:
	Led(byte pinLed);
	~Led();
	void turnOn();
	void turnOff();
};

#endif