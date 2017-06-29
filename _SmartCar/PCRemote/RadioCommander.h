#ifndef RADIOCOMMANDER_H
#define RADIOCOMMANDER_H

#include <Arduino.h>
#include <VirtualWire.h>


class RadioCommander
{
	private:
		byte m_transmitPin;
	public:
		RadioCommander(byte transmitPin);
		~RadioCommander();
		void setup();
		bool sendCommand(byte* command);
		bool sendArray(byte* data, byte size);
		
};

#endif