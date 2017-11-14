/**
 *	Name:		Battery.h
 *	Author:		FlorentinTh
 **/

#ifndef _BATTERY_h
#define _BATTERY_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <SparkFunBQ27441.h>
#include <BQ27441_Definitions.h>
#include "Helper.h"

class Battery
{
public:
	Battery();
	void setup(uint16_t capacity);
	uint16_t getSoC();
	uint16_t getVoltage();
	int16_t getCapacity();
	uint16_t getRemainingCapacity();
	int16_t getPower();
	uint8_t getSoH();
	~Battery();

private:

};

#endif

