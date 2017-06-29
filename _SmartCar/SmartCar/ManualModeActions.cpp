#include "ManualModeActions.h"

ManualModeActions::ManualModeActions(RadioSlave *radioSlave, EngineMaster *engineMaster)
	:m_radioSlave(radioSlave),
	m_engineMaster(engineMaster),
	m_engineGear(0)
{
	
}

ManualModeActions::~ManualModeActions()
{
	
}

void ManualModeActions::forward()
{
	m_engineMaster->setGear(m_engineGear);
	m_engineMaster->goForward();
	delay(200);
}

void ManualModeActions::backward()
{
	m_engineMaster->setGear(m_engineGear);
	m_engineMaster->goBackward();
	delay(200);
}

void ManualModeActions::left()
{
	m_engineMaster->setGear(m_engineGear);
	m_engineMaster->goLeft();
	delay(200);
}

void ManualModeActions::right()
{
	m_engineMaster->setGear(m_engineGear);
	m_engineMaster->goRight();
	delay(200);
}

void ManualModeActions::release()
{
	m_engineMaster->releaseEngine();
}

void ManualModeActions::setGear(byte gear)
{
	m_engineGear = gear;
	viewCurrentGear();
	delay(50);
}

void ManualModeActions::viewCurrentGear()
{
	Serial.println();
	Serial.print("Gear=");
	Serial.print(m_engineGear);
	Serial.println();
}
void ManualModeActions::driveCarManually(char command, char carState)
{
	if (carState == 'M')
	{
		switch (command)
		{
		case '1':
			setGear(1);
			delay(50);
			break;
		case '2':
			setGear(2);
			delay(50);
			break;
		case '3':
			setGear(3);
			delay(50);
			break;
		case '4':
			setGear(4);
			delay(50);
			break;
		case '5':
			setGear(5);
			delay(50);
			break;
		case '6':
			setGear(6);
			delay(50);
			break;
		case 'F':
			forward();
			break;
		case 'B':
			backward();
			break;
		case 'L':
			left();
			break;
		case 'R':
			right();
			break;
		default:
			release();
		}
	}
}