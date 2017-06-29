#ifndef DRIVECAR_H
#define DRIVECAR_H

#include <Arduino.h>
#include "Engine.h"
#include "RadioSlave.h"
#include "EngineMaster.h"
#include "ManualMode.h"
#include "AutoMode.h"
#include "Context.h"
#include "ThinkAction.h"

class DriveCar{
private:
	Context *m_context;
	ManualMode *m_manualMode;
	AutoMode *m_autoMode;
	RadioSlave *m_radioSlave;
	ThinkAction *m_thinkAction;
	char m_carState;
	//State=M => manualMode
	//State=A => AutoMode
	//State=N => No State
public:
	DriveCar(RadioSlave *radioSlave, ManualMode *manualMode, AutoMode *autoMode, Context *context, ThinkAction *thinkAction);
	~DriveCar();
	void setManualStrategy();
	void setAutoStrategy();
	void setNullStrategy();
	void start();
	
};

#endif