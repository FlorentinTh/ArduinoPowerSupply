/**
 *	Name:		Battery.cpp
 *	Author:		FlorentinTh
 **/

#include "Battery.h"

Battery::Battery()
{
}

void Battery::setup(uint16_t capacity)
{
	if (!lipo.begin())
	{
		Helper::error(SETUP_ERROR, "Unable to communicate with BQ27441.");
		while (1);
	}

	lipo.setCapacity(capacity);

	Helper::log(SETUP_OK, "BQ27441 setup completed.");
}

uint16_t Battery::getSoC()
{
	return lipo.soc();
}

uint16_t Battery::getVoltage()
{
	return lipo.voltage();
}

int16_t Battery::getCapacity()
{
	return lipo.current(AVG);
}

uint16_t Battery::getRemainingCapacity()
{
	return lipo.capacity(REMAIN);
}

int16_t Battery::getPower()
{
	return lipo.power();
}

uint8_t Battery::getSoH()
{
	return lipo.soh();
}

Battery::~Battery()
{
}
