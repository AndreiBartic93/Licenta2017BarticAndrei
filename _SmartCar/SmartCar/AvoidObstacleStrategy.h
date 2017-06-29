#ifndef AVOIDOBSTACLESTRATEGY_H
#define AVOIDOBSTACLESTRATEGY_H

#include <Arduino.h>
#include "Types.h"

class AvoidObstalceStrategy{
private:
	obstacleStrategies m_obstacleStrategy;
public:
	AvoidObstalceStrategy();
	~AvoidObstalceStrategy();
	obstacleStrategies getStrategy(incomingData sensorValues);
};

#endif