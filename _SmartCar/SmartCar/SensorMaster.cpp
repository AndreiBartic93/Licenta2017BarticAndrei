#include "UltrasonicSensor.h"
#include "SensorMaster.h"

SensorMaster::SensorMaster()
	:m_sensors(4),
	m_values(4)
{

}


SensorMaster::~SensorMaster()
{
	for (byte i = 0; i < m_sensors.getSize(); i++)
	{
		UltrasonicSensor* sensor = *m_sensors.get(i);
		if (sensor != NULL)
		{
			delete sensor;
		}
	}
}

void SensorMaster::addSensor(UltrasonicSensor* sensor)
{
	m_sensors.add(sensor);
}
incomingData SensorMaster::getSensorData()
{
	incomingData data;
	data.sensorData[0] = (*m_sensors.get(0))->getDistanceCm();
	data.sensorData[1] = (*m_sensors.get(1))->getDistanceCm();
	data.sensorData[2] = (*m_sensors.get(2))->getDistanceCm();
	data.sensorData[3] = (*m_sensors.get(3))->getDistanceCm();
	
	return data;
}
