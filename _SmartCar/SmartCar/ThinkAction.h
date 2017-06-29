#ifndef THINKACTION_H
#define THINKACTION_H

#include <Arduino.h>
#include "SensorMaster.h"
#include "AvoidObstacleStrategy.h"
#include "EngineActions.h"

class ThinkAction{
private:
	SensorMaster *m_sensorMaster;
	AvoidObstalceStrategy *m_avoidObstacleStrategy;
	EngineActions *m_engineActions;
public:
	ThinkAction(SensorMaster &sensorMaster, EngineActions &engineActions);
	~ThinkAction();
	void setup();
	char think(char command, char carState);//un while care se opreste atunci cand primeste o anumita comanda
	
};

#endif