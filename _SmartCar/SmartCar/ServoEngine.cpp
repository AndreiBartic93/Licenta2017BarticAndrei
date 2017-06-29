
#include "ServoEngine.h"


ServoEngine::ServoEngine(ServoTimer2 *servoTimer, byte pin)
	:m_servoTimer(servoTimer),
	 m_pin(pin)
{

}

ServoEngine::~ServoEngine()
{
	m_servoTimer->detach();
}

void ServoEngine::setup()
{
	pinMode(m_pin, OUTPUT);
	m_servoTimer->attach(m_pin);
}

void ServoEngine::goToDegree(byte degree)
{
	Serial.println("GO");
	m_servoTimer->write(degree);
}