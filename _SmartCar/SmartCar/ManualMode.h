#ifndef MANUALMODE_H
#define MANUALMODE_H

#include <Arduino.h>
#include "iStrategy.h"
#include "ManualModeActions.h"

class ManualMode : public iStrategy{

private:
	ManualModeActions *m_manualModeActions;
public:
	ManualMode(ManualModeActions *manualModeActions);
	~ManualMode();
	void setupManualMode();
	void driveCar(char command, char carState);
};

#endif