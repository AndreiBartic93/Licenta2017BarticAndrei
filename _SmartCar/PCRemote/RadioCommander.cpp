#include "RadioCommander.h"


RadioCommander::RadioCommander(byte transmitPin)
	:m_transmitPin(transmitPin)
{
	
}

RadioCommander::~RadioCommander()
{
	
}

void RadioCommander::setup()
{
	Serial.println("[RadioCommander] Start");
	pinMode(m_transmitPin, OUTPUT);
	vw_set_tx_pin(m_transmitPin);
	vw_set_ptt_inverted(true); // Required for DR3100
	vw_setup(4000);
}

bool RadioCommander::sendCommand(byte* command)
{
	vw_send((uint8_t *)command, sizeof(byte));
	vw_wait_tx();
	return true;
}

bool RadioCommander::sendArray(byte* data, byte size)
{
	vw_send((uint8_t *)data, size);
	vw_wait_tx();
	return true;
}

