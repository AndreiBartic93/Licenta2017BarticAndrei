#include "Context.h"

void Context::setStrategy(iStrategy *strategy)
{
	m_strategy = strategy;
}

iStrategy* Context::getStrategy()
{
	return m_strategy;
}

void Context::contextInterface(char command, char carState)
{
	m_strategy->driveCar(command, carState);
}