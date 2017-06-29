#ifndef MANUALMODEACTIONS_H
#define MANUALMODEACTIONS_H

#include <Arduino.h>
#include "VirtualWire.h"
#include "RadioSlave.h"
#include "EngineMaster.h"
#include "Types.h"

class ManualModeActions{

private:
	RadioSlave *m_radioSlave;
	EngineMaster *m_engineMaster;
	byte m_engineGear;
	void forward();
	void backward();
	void left();
	void right();
	void release();
	void setGear(byte gear);
	void viewCurrentGear();
public:
	ManualModeActions(RadioSlave *radioSlave, EngineMaster *engineMaster);
	~ManualModeActions();
	void driveCarManually(char command, char carState);
};


#endif