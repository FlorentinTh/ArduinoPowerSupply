/**
 *	Name:		PowerSupply.ino
 *	Author:		FlorentinTh
 **/

#include "Screen.h"
#include "Battery.h"

const long DELAY = 500;

Battery *battery;
Screen *OLEDScreen;

long time = 0;

void setup() {
	Serial.begin(115200);

	OLEDScreen = new Screen(SCREEN_D1, SCREEN_D0, SCREEN_DC, SCREEN_RESET, SCREEN_CS);
	OLEDScreen->init();
	OLEDScreen->displaySlashScreen("LIARA");

	battery->setup(1000);
}

void loop() {
	if ((millis() - time) >= DELAY)
	{
		time = millis();

		uint16_t SoC = battery->getSoC();
		uint8_t SoH = battery->getSoH();

		switch (SoC)
		{
			case 65535:
				OLEDScreen->displayWarning("WARNING", "The battery is no longer plugged.");
				break;
			case 0:
				OLEDScreen->displayInfo("Initializing...");
				break;
			default:
				String titles[] = { "State of charge : ", "Health : " };
				uint16_t values[] = { SoC, SoH };
				String units[] = { "%", "%" };
				OLEDScreen->displayValues(titles, values, units, 2);
				break;
		}
	}
}
