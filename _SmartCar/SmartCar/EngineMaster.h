#ifndef ENGINEMASTER_H
#define ENGINEMASTER_H

#include <Arduino.h>
#include "Engine.h"

class EngineMaster{
private:
	Engine *m_engineA;
	Engine *m_engineB;
public:
	EngineMaster(Engine *engineA, Engine *engineB);
	~EngineMaster();
	void goForward();
	void goBackward();
	void goLeft();
	void goRight();
	void releaseEngine();
	void setGear(byte gear);
};

#endif