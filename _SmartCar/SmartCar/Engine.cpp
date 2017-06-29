#include "Engine.h"

Engine::Engine(byte pinA1, byte pinA2, byte pinSpeed)
	:m_pinA1(pinA1),
	m_pinA2(pinA2),
	m_pinSpeed(pinSpeed),
	m_isRunning(false),
	m_gear(0)
{
	pinMode(m_pinA1, OUTPUT);
	pinMode(m_pinA2, OUTPUT);
	pinMode(m_pinSpeed, OUTPUT);
}

Engine::~Engine()
{

}

void Engine::writeSpeed()
{
	if (m_gear > 0)
	{
		analogWrite(m_pinSpeed, (MAX_SPEED / MAX_GEAR)*m_gear);
		m_isRunning = true;
	}
	else
	{
		//Serial.println(F("[TractionEngine] Relanti, nu mergi nicaieri!"));
	}
}

void Engine::gearUp()
{
	if ((m_gear >= 0) && (m_gear < MAX_GEAR))
	{
		Serial.println(F("[TractionEngine] GearUp"));
		m_gear++;
	}
	else
	{
		Serial.println(F("[TractionEngine] You have reached full speed"));
	}
}

void Engine::gearDown()
{
	if ((m_gear > 0) && (m_gear <= MAX_GEAR))
	{
		Serial.println(F("[TractionEngine] GearDown"));
		m_gear--;
	}
	else
	{
		Serial.println(F("[TractionEngine] You have reached full speed"));
	}
}

void Engine::setGear(byte gear)
{
	m_gear = gear;
}

byte Engine::getGear()
{
	return m_gear;
}

void Engine::forward()
{
	m_isRunning = true;
	digitalWrite(m_pinA1, HIGH);
	digitalWrite(m_pinA2, LOW);
	writeSpeed();
}

void Engine::backward()
{
	m_isRunning = true;
	digitalWrite(m_pinA2, HIGH);
	digitalWrite(m_pinA1, LOW);
	writeSpeed();
}

void Engine::releaseEngine()
{
	digitalWrite(m_pinA1, LOW);
	digitalWrite(m_pinA2, LOW);
	analogWrite(m_pinSpeed, 0);
	m_isRunning = false;
	m_gear = 0;
}

bool Engine::isRunning()
{
	return m_isRunning;
}