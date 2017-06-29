#include "ManualMode.h"

ManualMode::ManualMode(ManualModeActions *manualModeActions)
	:m_manualModeActions(manualModeActions)
{
	Serial.println("[ManualMode] Start");
}

ManualMode::~ManualMode()
{
	delete m_manualModeActions;
}

void ManualMode::driveCar(char command, char carState)
{
	m_manualModeActions->driveCarManually(command, carState);
}