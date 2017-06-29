#include "DriveCar.h"

DriveCar::DriveCar(RadioSlave *radioSlave, ManualMode *manualMode, AutoMode *autoMode, Context *context, ThinkAction *thinkAction)
	:m_context(context),
	 m_radioSlave(radioSlave),
	 m_autoMode(autoMode),
	 m_manualMode(manualMode),
	 m_thinkAction(thinkAction),
	 m_carState('N')
{
	
}

DriveCar::~DriveCar()
{
	delete m_radioSlave;
	delete m_manualMode;
}

void DriveCar::setManualStrategy()
{
	m_context->setStrategy(m_manualMode);
}

void DriveCar::setAutoStrategy()
{
	m_context->setStrategy(m_autoMode);
}

void DriveCar::setNullStrategy()
{
	m_context->setStrategy(nullptr);
}

void DriveCar::start()
{
	Serial.println("--------");
	int counter = 0;
	
	char command = m_radioSlave->receiveCommand();
	Serial.println("------11111111");
	if ( command == 'A' || command == 'M')
	{
		if (command == 'N')
		{
			Serial.println("Null");
			setNullStrategy();
			m_carState = 'N';
			Serial.println("------2");
		}
		if (command == 'M')
		{
			Serial.println("Manual Mode");
			setManualStrategy();
			m_carState = 'M';
			Serial.println("------3");
		}
		if (command == 'A')
		{
			Serial.println("Auto");
			setAutoStrategy();
			m_carState = 'A';	
			Serial.println("------4");
		}
	}
	//m_carState = 'A';
	Serial.println("------5");
	//m_carState = 'A';
	/*counter = 0;
	if (m_carState == 'N')
	{

	}*/
	if (m_carState == 'A'){
		for (int i = 0; i < 10;i++) {
			m_thinkAction->think('1', '2');
		}
	}
	else if (m_carState == 'M')
	{
		//m_context->contextInterface('1', m_carState);
	}
	
	
}