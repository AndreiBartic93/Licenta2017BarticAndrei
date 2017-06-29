#include "Lights.h"

Lights::Lights(byte lowBeam, byte highBeam)
	:m_lowBeam(lowBeam),
	m_highBeam(highBeam)
{
	pinMode(m_highBeam, OUTPUT);
	pinMode(m_lowBeam, OUTPUT);
}

Lights::~Lights()
{
	
}

void Lights::turnOnLowBeam()
{
	digitalWrite(m_lowBeam, HIGH);
}

void Lights::turnOnHighBeam()
{
	digitalWrite(m_highBeam, HIGH);
}
void Lights::closeLights()
{
	digitalWrite(m_lowBeam, LOW);
	digitalWrite(m_highBeam, LOW);
}