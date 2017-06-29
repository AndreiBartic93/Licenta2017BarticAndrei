#ifndef ISTRATEGY
#define ISTRATEGY

#include <Arduino.h>

class iStrategy{
	public:
		virtual void driveCar(char command, char carState) = 0;
};

#endif