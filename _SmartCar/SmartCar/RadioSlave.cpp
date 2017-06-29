#include "RadioSlave.h"

RadioSlave::RadioSlave(byte receivePin)
	:m_receivePin(receivePin)
	
{
	
}

RadioSlave::~RadioSlave()
{
	
}

void RadioSlave::setup()
{
	Serial.println("[RadioSlave] Start");
	vw_set_rx_pin(m_receivePin);
	vw_set_ptt_inverted(true); // Required for DR3100
	vw_setup(4000);  // Bits per secs
	vw_rx_start();       // Start the receiver PLL running
}

byte RadioSlave::receiveCommand()
{
	byte val;
	uint8_t buf;
	uint8_t buflen = sizeof(byte);
	vw_get_message(&buf, &buflen);
	return buf;
}

//incomingData RadioSlave::receiveArray()
//{
//	incomingData incomingValues;
//	uint8_t buf[VW_MAX_MESSAGE_LEN];
//	uint8_t buflen = VW_MAX_MESSAGE_LEN;
//	if (vw_get_message(buf, &buflen)) // Non-blocking
//	{
//		
//		for (int i = 0; i <buflen; i++)
//		{
//			incomingValues.sensorData[i] = buf[i];
//			//Serial.print(buf[i]);
//		}
//		Serial.println();
//		
//	}
//	return incomingValues;
//}
//
//
