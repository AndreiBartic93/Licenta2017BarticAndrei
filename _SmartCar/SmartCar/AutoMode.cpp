#include "AutoMode.h"

AutoMode::AutoMode(ThinkAction *thinkAction, SdCard *card)
	:m_thinkAction(thinkAction),
	m_Card(card)
{
	
}

AutoMode::~AutoMode()
{
	delete m_thinkAction;
	delete m_Card;
}

void AutoMode::setup()
{
	m_thinkAction->setup();
	
}

void AutoMode::driveCar(char command, char carState)
{
	char buf[20];
	for (int i = 0; i < 50; i++){
		buf[i] = m_thinkAction->think(command, carState);
		if (i == 9){
			m_Card->initializeSd();
			m_Card->createFile("test.txt");
			m_Card->writeToFile(buf);
			m_Card->closeFile();
		}
	}
	Serial.println("--------");
	

}
