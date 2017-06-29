#ifndef AUTOMODE_H
#define AUTOMODE_H

#include <Arduino.h>
#include <SD.h>
#include "iStrategy.h"
#include "ThinkAction.h"
#include <SPI.h>
#include "SdCard.h"
class AutoMode : public iStrategy{
private:
	ThinkAction *m_thinkAction;
	SdCard *m_Card;
public:
	AutoMode(ThinkAction *thinkAction, SdCard *card);
	~AutoMode();
	void driveCar(char command, char carState);
	void setup();
};


#endif