

#include <Arduino.h>
#include <VirtualWire.h>
#include "RadioCommander.h"
#include "TemperatureAndHumidity.h"


RadioCommander radioCommander(2);
dht DHT;
TemperatureAndHumidity tempAndHumidity(&DHT, 3);
byte commandReceived = 0;

void setup()
{
	Serial.begin(9600);
	radioCommander.setup();
	tempAndHumidity.setup();
}

void loop()
{

	if (Serial.available() > 0)
	{
		//commandReceived += (Serial.read() - '0');
		//commandReceived = Serial.read();

		commandReceived = Serial.read();
		
		if (commandReceived == 'E'){
			byte buf[2];
			buf[0] = tempAndHumidity.getTemperature();
			buf[1] = tempAndHumidity.getHumidity();
			Serial.write(buf,2);
		}


		radioCommander.sendCommand(&commandReceived);
	}
	else
	{
		commandReceived = 0;
		radioCommander.sendCommand(&commandReceived);
	}


}
