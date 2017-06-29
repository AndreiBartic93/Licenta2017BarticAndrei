#include "ThinkAction.h"

ThinkAction::ThinkAction(SensorMaster &sensorMaster, EngineActions &engineActions)
	:m_sensorMaster(&sensorMaster),
	m_engineActions(&engineActions)
{
	
}

ThinkAction::~ThinkAction()
{
	delete m_sensorMaster;
	delete m_avoidObstacleStrategy;
	delete m_engineActions;
}

void ThinkAction::setup()
{
	UltrasonicSensor leftSensor(2, 3);
	UltrasonicSensor frontSensor(4, 7);
	UltrasonicSensor rightSensor(8, 9);
	UltrasonicSensor backwardSensor(A4, A5);

	m_sensorMaster->addSensor(&leftSensor);
	m_sensorMaster->addSensor(&frontSensor);
	m_sensorMaster->addSensor(&rightSensor);
	m_sensorMaster->addSensor(&backwardSensor);

}

char ThinkAction::think(char command, char carState)
{
	/*incomingData data = m_sensorMaster->getSensorData();
	Serial.println(data.sensorData[0]);
	Serial.println(data.sensorData[1]);
	Serial.println(data.sensorData[2]);
	Serial.println(data.sensorData[3]);
	Serial.println("-------");
	delay(500);*/
	char val = '0';
		obstacleStrategies finalStrategy = m_avoidObstacleStrategy->getStrategy(m_sensorMaster->getSensorData());
		switch (finalStrategy)
		{
		case strategyOne:
			val = m_engineActions->doStrategyOne();
			break;
		case strategyTwo:
			val = m_engineActions->doStrategyTwo();
			break;
		case strategyThree:
			val = m_engineActions->doStrategyThree();
			break;
		case strategyFour:
			val = m_engineActions->doStrategyFour();
			break;
		case strategyFive:
			val = m_engineActions->doStrategyFive();
			break;
		case strategySix:
			val = m_engineActions->doStrategySix();
			break;
		case strategySeven:
			val = m_engineActions->doStrategySeven();
			break;
		case strategyEight:
			val = m_engineActions->doStrategyEight();
			break;
		case strategyNine:
			val = m_engineActions->doStrategyNine();
			break;
		case strategyTen:
			val = m_engineActions->doStrategyTen();
			break;
		case strategyEleven:
			val = m_engineActions->doStrategyEleven();
			break;
		case strategyTwelve:
			val = m_engineActions->doStrategyTwelve();
			break;
		case strategyThirteen:
			val = m_engineActions->doStrategyThirteen();
			break;
		case strategyFourteen:
			val = m_engineActions->doStrategyFourteen();
			break;
		case strategyFifteen:
			val = m_engineActions->doStrategyFifteen();
			break;
		case strategySixteen:
			val = m_engineActions->doStrategySixteen();
			break;
		default:
			Serial.println("[ThinkAction] Default Strategy");
			val = '0';
		}
		return val;
}
