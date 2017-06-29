#ifndef TYPES_H
#define TYPES_H

#include <Arduino.h>

extern const byte MAX_SPEED;
extern const byte MAX_GEAR;

enum radioCommands
{
	commandAutoMode,
	commandManualMode
};

enum manualModeCommands{
	goForward=1,
	goBackward=2,
	goLeft=3,
	goRight=4,
	releaseEngines=5
};
extern const char MANUALMODE;
extern const char AUTOMODE;

extern const char GEARONE;
extern const char GEARTWO;
extern const char GEARTHREE;
extern const char GEARFOUR;
extern const char GEARFIVE;
extern const char GEARSIX;

extern const char GOFORWARD;
extern const char GOBACKWARD;
extern const char GOLEFT;
extern const char GORIGHT;
extern const char BREAK;

//obstacles strategy
enum obstacleStrategies
{
	strategyOne,
	strategyTwo,
	strategyThree,
	strategyFour,
	
	strategyFive,
	strategySix,
	strategySeven,
	strategyEight,
	
	strategyNine,
	strategyTen,
	strategyEleven,
	strategyTwelve,

	strategyThirteen,
	strategyFourteen,
	strategyFifteen,
	strategySixteen
};
extern const byte OBSTACLE_LIMIT;

struct commandList{
	byte observerCommands[2];
};

extern const char* commandNames[5];
extern const byte MAX_CAPACITY;
extern const byte MAX_SENZOR_CAPACITY;
extern const byte INVALID_COMMAND;
extern const byte MAX_FIELD_ARRAY;


//UltrasonicSensors
extern const byte MAX_LENGTH;
extern const byte ERR_LENGTH;

//SensorMaster
struct incomingData
{
	byte sensorData[4];
};

struct fieldData
{
	byte fieldSensorData[4];
};

//pins:
//first engine
extern const byte ENGINE_A_PIN1;
extern const byte ENGINE_A_PIN2;
extern const byte ENGINE_A_PINSPEED;

//second engine
extern const byte ENGINE_B_PIN1;
extern const byte ENGINE_B_PIN2;
extern const byte ENGINE_B_PINSPEED;

//radio slave:
extern const byte RADIO_SLAVE_PIN;

#endif