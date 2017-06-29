#ifndef SENSORMASTER_H
#define SENSORMASTER_H

#include <Arduino.h>
#include "Array.h"
#include "UltrasonicSensor.h"
#include "Types.h"

class SensorMaster
{
private:
	Array<UltrasonicSensor*> m_sensors;
	Array<int> m_values;
public:
	SensorMaster();
	~SensorMaster();
	void addSensor(UltrasonicSensor* sensor);
	incomingData getSensorData();
};

#endif