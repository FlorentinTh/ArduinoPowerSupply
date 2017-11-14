/**
 *	Name:		Screen.h
 *	Author:		FlorentinTh
 **/
#ifndef _SCREEN_h
#define _SCREEN_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include "Helper.h"

class Screen
{
public:
	Screen(uint8_t D1, uint8_t D0, uint8_t DC, uint8_t RESET, uint8_t CS);

	void init();
	void displaySlashScreen(const char* text);
	void displayWarning(const char* title, const char* msg);
	void displayInfo(const char* msg);
	void displayValues(String titles[], uint16_t values[], String units[], uint8_t number);

	~Screen();

private:
	Adafruit_SSD1306 *_oled;
};



#endif

