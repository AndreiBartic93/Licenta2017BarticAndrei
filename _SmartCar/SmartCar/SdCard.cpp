#include "SdCard.h"

SdCard::SdCard(byte cePin)
	:m_cePin(cePin)
{
	
}

SdCard::~SdCard()
{
	
}

void  SdCard::initializeSd()
{
	Serial.println("Initializing SD card...");
	pinMode(m_cePin, OUTPUT);

	if (SD.begin())
	{
		Serial.println("SD card is ready to use.");
	}
	else
	{
		Serial.println("SD card initialization failed");
		return;
	}
}

int SdCard::createFile(char filename[])
{
	m_file = SD.open(filename, FILE_WRITE);

	if (m_file)
	{
		Serial.println("File created successfully.");
		return 1;
	}
	else
	{
		Serial.println("Error while creating file.");
		return 0;
	}
}

int SdCard::writeToFile(char text[])
{
	if (m_file)
	{
		m_file.println(text);
		Serial.println("Writing to file: ");
		Serial.println(text);
		return 1;
	}
	else
	{
		Serial.println("Couldn't write to file");
		return 0;
	}
}


void SdCard::closeFile()
{
	if (m_file)
	{
		m_file.close();
		Serial.println("File closed");
	}
}

int SdCard::openFile(char filename[])
{
	m_file = SD.open(filename);
	if (m_file)
	{
		Serial.println("File opened with success!");
		return 1;
	}
	else
	{
		Serial.println("Error opening file...");
		return 0;
	}
}

String SdCard::readLine()
{
	String received = "";
	char ch;
	while (m_file.available())
	{
		ch = m_file.read();
		if (ch == '\n')
		{
			return String(received);
		}
		else
		{
			received += ch;
		}
	}
	return "";
}
