#include "TemperatureAndHumidity.h"

TemperatureAndHumidity::TemperatureAndHumidity(dht *DHT, byte pinDht)
	:m_dht(DHT),
	 m_pinDht(pinDht)
	 
{
	
}

TemperatureAndHumidity::~TemperatureAndHumidity()
{
	delete m_dht;
}

void TemperatureAndHumidity::setup()
{
	m_dht->read11(m_pinDht);
}
int TemperatureAndHumidity::getTemperature()
{
	return (int)m_dht->temperature;
}

int TemperatureAndHumidity::getHumidity()
{
	return (int)m_dht->humidity;
}