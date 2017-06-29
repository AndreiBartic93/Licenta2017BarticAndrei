#ifndef ENGINE_H
#define ENGINE_H

#include <Arduino.h>
#include "Types.h"

class Engine{
private:
	byte m_pinA1;
	byte m_pinA2;
	byte m_pinSpeed;
	byte m_gear;
	bool m_isRunning;
	void writeSpeed();
public:
	Engine(byte pinA1, byte pinA2, byte spinSpeed);
	~Engine();
	
	void getSpeed();
	void gearUp();
	void gearDown();
	void setGear(byte gear);
	byte getGear();
	void forward();
	void backward();
	void releaseEngine();
	bool isRunning();
};

#endif