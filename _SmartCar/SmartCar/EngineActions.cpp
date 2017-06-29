#include "EngineActions.h"

EngineActions::EngineActions(EngineMaster *engineMaster)
	:m_engineMaster(engineMaster)
{
	
}

EngineActions::~EngineActions()
{
	
}

void EngineActions::goForward15Cm()
{
	m_engineMaster->setGear(3);
	m_engineMaster->goForward();
	//delay(700);
	//delay(300);
	delay(250);
	m_engineMaster->releaseEngine();
}

void EngineActions::goBackward15Cm()
{	
	m_engineMaster->setGear(3);
	m_engineMaster->goBackward();
	delay(700);
	m_engineMaster->releaseEngine();
}



void EngineActions::goZeroTo45()
{
	m_engineMaster->setGear(6);
	m_engineMaster->goRight();
	delay(150);
	m_engineMaster->releaseEngine();
}

void EngineActions::goZeroTo90()
{
	m_engineMaster->setGear(6);
	m_engineMaster->goRight();
	delay(260);
	m_engineMaster->releaseEngine();
}

void EngineActions::goZeroTo135()
{
	m_engineMaster->setGear(6);
	m_engineMaster->goRight();
	delay(375);
	m_engineMaster->releaseEngine();
}

void EngineActions::goZeroTo180()
{
	m_engineMaster->setGear(6);
	m_engineMaster->goRight();
	delay(450);
	m_engineMaster->releaseEngine();
}


void EngineActions::go180To135()
{
	m_engineMaster->setGear(6);
	m_engineMaster->goLeft();
	delay(162);
	m_engineMaster->releaseEngine();
}

void EngineActions::go180To90()
{
	m_engineMaster->setGear(6);
	m_engineMaster->goLeft();
	delay(260);
	m_engineMaster->releaseEngine();
}

void EngineActions::go180To45()
{
	m_engineMaster->setGear(6);
	m_engineMaster->goLeft();
	delay(375);
	m_engineMaster->releaseEngine();
}

void EngineActions::go180To0()
{
	m_engineMaster->setGear(6);
	m_engineMaster->goLeft();
	delay(460);
	m_engineMaster->releaseEngine();
}


void EngineActions::go90To45()
{
	m_engineMaster->setGear(6);
	m_engineMaster->goLeft();
	delay(155);
	m_engineMaster->releaseEngine();
}
void EngineActions::go90To0()
{
	m_engineMaster->setGear(6);
	m_engineMaster->goLeft();
	delay(260);
	m_engineMaster->releaseEngine();
}
void EngineActions::go90To135()
{
	m_engineMaster->setGear(6);
	m_engineMaster->goRight();
	delay(150);
	m_engineMaster->releaseEngine();
}
void EngineActions::go90To180()
{
	m_engineMaster->setGear(6);
	m_engineMaster->goRight();
	delay(250);
	m_engineMaster->releaseEngine();
}

//L>15, F>15, R>15, B>15
char EngineActions::doStrategyOne()
{
	goForward15Cm();
	return '1,';
}

//L>15, F>15, R>15, B<15
char EngineActions::doStrategyTwo()
{
	goForward15Cm();
	return '2,';
}

//L>15, F>15, R<15, B>15
char EngineActions::doStrategyThree()
{
	go90To45();
	return '3,';
}

char EngineActions::doStrategyFour()
{
	go90To45();
	return '4,';
}

char EngineActions::doStrategyFive()
{
	go90To0();
	return '5,';
}

char EngineActions::doStrategySix()
{
	go90To0();
	return '6';
}

char EngineActions::doStrategySeven()
{
	go90To0();
	return '7';
}

char EngineActions::doStrategyEight()
{
	go90To0();
	return '8';
}


char EngineActions::doStrategyNine()
{
	go90To135();
	return '9';
}

char EngineActions::doStrategyTen()
{
	go90To180();
	return '10';
}

char EngineActions::doStrategyEleven()
{
	goForward15Cm();
	return '11';
}

char EngineActions::doStrategyTwelve()
{
	goForward15Cm();
	return '12';
}

char EngineActions::doStrategyThirteen()
{
	go90To180();
	return '13';
}

char EngineActions::doStrategyFourteen()
{
	go90To135();
	return '14';
}

char EngineActions::doStrategyFifteen()
{
	go90To180();
	go90To180();
	return '15';
}

char EngineActions::doStrategySixteen()
{
	return '16';
}