#ifndef LIGHTS_H
#define LIGHTS_H

#include <Arduino.h>

class Lights{

private:
	byte m_lowBeam;
	byte m_highBeam;

	
public:
	Lights(byte lowBeam, byte highBeam);
	~Lights();
	
	void turnOnLowBeam();
	void turnOnHighBeam();

	void closeLights();
	
};

#endif