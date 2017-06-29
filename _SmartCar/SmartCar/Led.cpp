#include "Led.h"

Led::Led(byte pinLed)
	:m_pinLed(pinLed)
{
	pinMode(m_pinLed, OUTPUT);
}

Led::~Led()
{

}

void Led::turnOn()
{
	digitalWrite(m_pinLed, HIGH);
}

void Led::turnOff()
{
	digitalWrite(m_pinLed, LOW);
}
