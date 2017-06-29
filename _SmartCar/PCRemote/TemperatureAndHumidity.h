#ifndef TEMPERATUREANDHUMIDITY_H
#define TEMPERATUREANDHUMIDITY_H

#include <Arduino.h>
#include <dht.h>

class TemperatureAndHumidity{
private:
	dht *m_dht;
	byte m_pinDht;
public:
	TemperatureAndHumidity(dht *DHT, byte pinDht);
	~TemperatureAndHumidity();
	void setup();
	int getTemperature();
	int getHumidity();
};

#endif