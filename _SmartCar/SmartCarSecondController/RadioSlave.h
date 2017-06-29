#ifndef RADIOSLAVE_H
#define RADIOSLAVE_H

#include <Arduino.h>
#include <VirtualWire.h>

//struct incomingRadioData{
//	byte sensorData[4];
//};
class RadioSlave
{
	private:
		byte m_receivePin;
	public:
		RadioSlave(byte receivePin);
		~RadioSlave();
		void setup();
		//incomingData receiveArray();
		byte receiveCommand();
};

#endif