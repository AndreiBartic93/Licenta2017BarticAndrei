#ifndef ENGINEACTIONS_H
#define ENGINEACTIONS_H

#include <Arduino.h>
#include "EngineMaster.h"

class EngineActions{
private:
	EngineMaster *m_engineMaster;
	void goForward15Cm();
	void goBackward15Cm();
	
	void goZeroTo45();
	void goZeroTo90();
	void goZeroTo135();
	void goZeroTo180();

	void go180To135();
	void go180To90();
	void go180To45();
	void go180To0();

	void go90To45();
	void go90To0();
	
	void go90To135();
	void go90To180();
	
public:
	EngineActions(EngineMaster *engineMaster);
	~EngineActions();
	char doStrategyOne();
	char doStrategyTwo();
	char doStrategyThree();
	char doStrategyFour();
	
	char doStrategyFive();
	char doStrategySix();
	char doStrategySeven();
	char doStrategyEight();

	char doStrategyNine();
	char doStrategyTen();
	char doStrategyEleven();
	char doStrategyTwelve();

	char doStrategyThirteen();
	char doStrategyFourteen();
	char doStrategyFifteen();
	char doStrategySixteen();


};

#endif