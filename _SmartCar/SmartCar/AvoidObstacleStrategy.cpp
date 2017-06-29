#include "AvoidObstacleStrategy.h"

AvoidObstalceStrategy::AvoidObstalceStrategy()
	:m_obstacleStrategy(strategyOne)
{
	
}

AvoidObstalceStrategy::~AvoidObstalceStrategy()
{
	
}

obstacleStrategies AvoidObstalceStrategy::getStrategy(incomingData sensorValues)
{
	obstacleStrategies finalStrategy;

	unsigned int leftSensor = sensorValues.sensorData[0];
	unsigned int frontSensor = sensorValues.sensorData[1];
	unsigned int rightSensor = sensorValues.sensorData[2];
	unsigned int backwardSensor = sensorValues.sensorData[3];

	//1->L=0,F=0,R=0,B=0
	if (leftSensor > 0 && frontSensor > 0 && rightSensor > 0 && backwardSensor > 0)
	{
		if (leftSensor > OBSTACLE_LIMIT && frontSensor > OBSTACLE_LIMIT && rightSensor > OBSTACLE_LIMIT && backwardSensor > OBSTACLE_LIMIT)
		{
			Serial.println("[Strategy] Strategy1");
			finalStrategy = strategyOne;
		}

		//2->L=0,F=0,R=0,B=1
		if (leftSensor > OBSTACLE_LIMIT && frontSensor > OBSTACLE_LIMIT && rightSensor > OBSTACLE_LIMIT && backwardSensor < OBSTACLE_LIMIT)
		{
			Serial.println("[Strategy] Strategy2");
			finalStrategy = strategyTwo;
		}

		//3->l=0, F=0, R=1, B=0
		if (leftSensor > OBSTACLE_LIMIT && frontSensor > OBSTACLE_LIMIT && rightSensor < OBSTACLE_LIMIT && backwardSensor > OBSTACLE_LIMIT)
		{
			Serial.println("[Strategy] Strategy3");
			finalStrategy = strategyThree;
		}

		//4->l=0, F=0, R=1, B=1
		if (leftSensor > OBSTACLE_LIMIT && frontSensor > OBSTACLE_LIMIT && rightSensor < OBSTACLE_LIMIT && backwardSensor < OBSTACLE_LIMIT)
		{
			Serial.println("[Strategy] Strategy4");
			finalStrategy = strategyFour;
		}

		//5->l=0, F=1, R=0, B=0
		if (leftSensor > OBSTACLE_LIMIT && frontSensor < OBSTACLE_LIMIT && rightSensor > OBSTACLE_LIMIT && backwardSensor > OBSTACLE_LIMIT)
		{
			Serial.println("[Strategy] Strategy5");
			finalStrategy = strategyFive;
		}

		//6->l=0, F=1, R=0, B=1
		if (leftSensor > OBSTACLE_LIMIT && frontSensor < OBSTACLE_LIMIT && rightSensor > OBSTACLE_LIMIT && backwardSensor < OBSTACLE_LIMIT)
		{
			Serial.println("[Strategy] Strategy6");
			finalStrategy = strategySix;
		}

		//7->l=0, F=1, R=1, B=0
		if (leftSensor > OBSTACLE_LIMIT && frontSensor < OBSTACLE_LIMIT && rightSensor < OBSTACLE_LIMIT && backwardSensor > OBSTACLE_LIMIT)
		{
			Serial.println("[Strategy] Strategy7");
			finalStrategy = strategySeven;
		}

		//8->l=0, F=1, R=1, B=1
		if (leftSensor > OBSTACLE_LIMIT && frontSensor < OBSTACLE_LIMIT && rightSensor < OBSTACLE_LIMIT && backwardSensor < OBSTACLE_LIMIT)
		{
			Serial.println("[Strategy] Strategy8");
			finalStrategy = strategyEight;
		}


		//9->l=1, F=0, R=0, B=0
		if (leftSensor < OBSTACLE_LIMIT && frontSensor > OBSTACLE_LIMIT && rightSensor > OBSTACLE_LIMIT && backwardSensor > OBSTACLE_LIMIT)
		{
			Serial.println("[Strategy] Strategy9");
			finalStrategy = strategyNine;
		}

		//10->l=1, F=0, R=0, B=1
		if (leftSensor < OBSTACLE_LIMIT && frontSensor > OBSTACLE_LIMIT && rightSensor > OBSTACLE_LIMIT && backwardSensor < OBSTACLE_LIMIT)
		{
			Serial.println("[Strategy] Strategy10");
			finalStrategy = strategyTen;
		}

		//11->l=1, F=0, R=1, B=0
		if (leftSensor < OBSTACLE_LIMIT && frontSensor > OBSTACLE_LIMIT && rightSensor < OBSTACLE_LIMIT && backwardSensor > OBSTACLE_LIMIT)
		{
			Serial.println("[Strategy] Strategy11");
			finalStrategy = strategyEleven;
		}

		//12->l=1, F=0, R=1, B=1
		if (leftSensor < OBSTACLE_LIMIT && frontSensor > OBSTACLE_LIMIT && rightSensor < OBSTACLE_LIMIT && backwardSensor < OBSTACLE_LIMIT)
		{
			Serial.println("[Strategy] Strategy12");
			finalStrategy = strategyTwelve;
		}


		//13->l=1, F=1, R=0, B=0
		if (leftSensor < OBSTACLE_LIMIT && frontSensor < OBSTACLE_LIMIT && rightSensor > OBSTACLE_LIMIT && backwardSensor > OBSTACLE_LIMIT)
		{
			Serial.println("[Strategy] Strategy13");
			finalStrategy = strategyThirteen;
		}

		//14->l=1, F=1, R=0, B=1
		if (leftSensor < OBSTACLE_LIMIT && frontSensor < OBSTACLE_LIMIT && rightSensor > OBSTACLE_LIMIT && backwardSensor < OBSTACLE_LIMIT)
		{
			Serial.println("[Strategy] Strategy14");
			finalStrategy = strategyFourteen;
		}

		//15->l=1, F=1, R=1, B=0
		if (leftSensor < OBSTACLE_LIMIT && frontSensor < OBSTACLE_LIMIT && rightSensor < OBSTACLE_LIMIT && backwardSensor > OBSTACLE_LIMIT)
		{
			Serial.println("[Strategy] Strategy15");
			finalStrategy = strategyFifteen;
		}

		//16->l=1, F=1, R=1, B=1
		if (leftSensor < OBSTACLE_LIMIT && frontSensor < OBSTACLE_LIMIT && rightSensor < OBSTACLE_LIMIT && backwardSensor < OBSTACLE_LIMIT)
		{
			Serial.println("[Strategy] Strategy16");
			finalStrategy = strategySixteen;
		}
	}
	

	return finalStrategy;
}