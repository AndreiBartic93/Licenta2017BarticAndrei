#ifndef CONTEXT_H
#define CONTEXT_H

#include <Arduino.h>
#include "iStrategy.h"

class Context{

private:
	iStrategy *m_strategy;

public:
	void setStrategy(iStrategy *strategy);
	iStrategy *getStrategy();
	void contextInterface(char command, char carState);
	
};

#endif