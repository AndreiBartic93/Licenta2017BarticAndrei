#include <Arduino.h>
#include <ServoTimer2.h>
#include <VirtualWire.h>
#include "Array.h"
#include "Types.h"
#include "Engine.h"
#include "EngineMaster.h"
//#include "RadioSlave.h"
#include <SPI.h>
#include "Context.h"
#include <Arduino.h>
#include <SD.h>
#include <SPI.h>
#include "SdCard.h"
//ManualMode:
#include "ManualModeActions.h"
#include "ManualMode.h"

//AutoMode:
#include "UltrasonicSensor.h"
#include "SensorMaster.h"
#include "AvoidObstacleStrategy.h"
#include "ThinkAction.h"
#include "EngineActions.h"
#include "AutoMode.h"

//DriveCar:
#include "DriveCar.h"
//-------------------finish libs----------------------



Context *context = new Context();

//ManualMode
Engine engineA(A0, A1, 5);
Engine engineB(A2, A3, 6);
RadioSlave radioSlave(12);
EngineMaster engineMaster(&engineA, &engineB);
ManualModeActions manualModeActions(&radioSlave, &engineMaster);
ManualMode *manualMode = new ManualMode(&manualModeActions);

//AutoMode
SensorMaster sensorMaster;
EngineActions engineActions(&engineMaster);
SdCard card(10);
ThinkAction thinkAction(sensorMaster, engineActions);
AutoMode *autoMode = new AutoMode(&thinkAction, &card);

//DriveCar
DriveCar driveCar(&radioSlave, manualMode, autoMode, context, &thinkAction);


//tESTE
UltrasonicSensor u1(2, 3);
UltrasonicSensor u2(4, 7);
UltrasonicSensor u3(8, 9);
UltrasonicSensor u4(A4, A5);



char command = ' ';
char m_carState = 'M';
void setup()
{
	Serial.begin(9600);
	//autoMode->setup();
	thinkAction.setup();
	//pinMode(13, OUTPUT);
	/*card.initializeSd();
	card.createFile("fieldData.txt");*/
	
}

void loop()
{
	thinkAction.think('1', '1');
	//digitalWrite(2, HIGH);
	//digitalWrite(3, HIGH);
	
	//if (Serial.available())
	//{
	//	char command = Serial.read();
	//	if (command == '1'){
	//		Serial.println(command);
	//	}
	//	if (command == 'M')
	//	{
	//		Serial.println("Manual Mode");
	//		context->setStrategy(manualMode);
	//		m_carState = 'M';
	//	}
	//	else if (command == 'A')
	//	{
	//		Serial.println("Auto");
	//		context->setStrategy(autoMode);
	//		m_carState = 'A';
	//	}
	//	context->contextInterface(command, m_carState);
	//	//m_carState = 'M';
	//	//----	
	//}
}





//void setup()
//{
//	Serial.begin(9600);
//
//	card.initializeSd();
//	card.createFile("test.txt");
//	for (int i = 0; i < 10; i++){
//		card.writeToFile("h1i");
//	}
//	card.closeFile();
//
//	/*openFile("prefs.txt");
//	Serial.println(readLine());
//	Serial.println(readLine());
//	closeFile();*/
//}
//void loop()
//{
//}





int ledPin = 13;                 // Led conectat la pinul digital 13
int analogPin = 3				// Declaram pinul analog 3 care va avea ata?at un poten?iometru
int val = 0;					// Variabila în care vom stoca valoarea senzorului
void setup()
{
	pinMode(ledPin, OUTPUT);      // setam pinul digital ca fiind OUTPUT

void loop()
{
	digitalWrite(ledPin, HIGH);   // aprindem ledul
	delay(1000);                  // a?tepm?m o secund?
	digitalWrite(ledPin, LOW);    // stingem ledul
	delay(1000);                  // a?tept?m o secund?
}