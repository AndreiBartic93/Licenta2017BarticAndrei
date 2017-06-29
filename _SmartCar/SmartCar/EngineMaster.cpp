#include "Engine.h"
#include "EngineMaster.h"

EngineMaster::EngineMaster(Engine *engineA, Engine *engineB)
	:m_engineA(engineA),
	 m_engineB(engineB)
{

}

EngineMaster::~EngineMaster()
{
	delete m_engineA;
	delete m_engineB;
}

void EngineMaster::goForward()
{
	//Serial.write("[EngineMaster] Forward");
	m_engineA->forward();
	//delay(50);
	m_engineB->forward();
}

void EngineMaster::goBackward()
{
	//Serial.write("[EngineMaster] Backward");
	m_engineA->backward();
	//delay(50);
	m_engineB->backward();
}

void EngineMaster::goLeft()
{
//	Serial.write("[EngineMaster] Left");
	m_engineB->forward();
	m_engineA->backward();
}

void EngineMaster::goRight()
{
	//Serial.write("[EngineMaster] Right");
	m_engineA->forward();
	m_engineB->backward();
}

void EngineMaster::releaseEngine()
{
	//Serial.write("[EngineMaster] Release Engine");
	m_engineA->releaseEngine();
	m_engineB->releaseEngine();
}

void EngineMaster::setGear(byte gear)
{
	m_engineA->setGear(gear);
	m_engineB->setGear(gear);
}
