#ifndef SDCARD_H
#define SDCARD_H

#include <Arduino.h>
#include <SD.h>
#include <SPI.h>

class SdCard{
private:
	byte m_cePin;
	File m_file;
public:
	SdCard(byte cePin);
	~SdCard();
	void initializeSd();
	int createFile(char filename[]);
	int writeToFile(char text[]);
	void closeFile();
	int openFile(char filename[]);
	String readLine();
};
#endif