#include "Types.h"

const char* commandNames[5] = { "Forward", "Backward", "Stop", "GearUp", "GearDown" };

const byte MAX_CAPACITY = 10;
const byte MAX_SENZOR_CAPACITY = 4;
const byte INVALID_COMMAND = 255;
const byte MAX_FIELD_ARRAY = 180;
const byte MAX_SPEED = 255;
extern const byte MAX_GEAR = 6;
//UltrasonicSensors
extern const byte MAX_LENGTH = 30;
extern const byte ERR_LENGTH = 255;

//Obstacle Strategy
extern const byte OBSTACLE_LIMIT = 25;

//pins:
//first engine
extern const byte ENGINE_A_PIN1=2;
extern const byte ENGINE_A_PIN2=3;
extern const byte ENGINE_A_PINSPEED=9;

//second engine
extern const byte ENGINE_B_PIN1=4;
extern const byte ENGINE_B_PIN2=5;
extern const byte ENGINE_B_PINSPEED=10;

//radio slave:
extern const byte RADIO_SLAVE_PIN = A0;


extern const char GEARONE='1';
extern const char GEARTWO='2';
extern const char GEARTHREE='3';
extern const char GEARFOUR='4';
extern const char GEARFIVE='5';
extern const char GEARSIX='6';

extern const char GOFORWARD='F';
extern const char GOBACKWARD='B';
extern const char GOLEFT='L';
extern const char GORIGHT='R';
extern const char BREAK='BR';

extern const char MANUALMODE = 'M';
extern const char AUTOMODE = 'A';