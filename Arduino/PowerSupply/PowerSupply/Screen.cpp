/**
 *	Name:		Screen.cpp
 *	Author:		FlorentinTh
 **/

#include "Screen.h"

Screen::Screen(uint8_t D1, uint8_t D0, uint8_t DC, uint8_t RESET, uint8_t CS)
{
	_oled = new Adafruit_SSD1306(D1, D0, DC, RESET, CS);
}

void Screen::init()
{
	_oled->begin(SSD1306_SWITCHCAPVCC);
}

void Screen::displaySlashScreen(const char* text)
{
	_oled->clearDisplay();
	_oled->setTextSize(4);
	_oled->setTextColor(WHITE);
	_oled->setCursor(6, 2);
	_oled->println(text);
	_oled->display();
}

void Screen::displayWarning(const char* title, const char* msg)
{
	_oled->clearDisplay();
	_oled->setTextSize(2);
	_oled->setTextColor(WHITE);
	_oled->setCursor(0, 0);
	_oled->println(title);
	_oled->setTextSize(1);
	_oled->setTextColor(WHITE);
	_oled->println(msg);
	_oled->display();
}

void Screen::displayValues(String titles[], uint16_t values[], String units[], uint8_t number)
{
	if (number > 0 && number <= 2)
	{
		_oled->clearDisplay();
		_oled->setTextSize(1);
		_oled->setTextColor(WHITE);
		_oled->setCursor(0, 0);
		for (uint8_t i = 0; i < number; i++)
		{
			_oled->println(titles[i]);
			_oled->print(values[i]);
			_oled->println(units[i]);
		}
		_oled->display();
	}
	else
	{
		Helper::error(SCREEN_ERROR, "Cannot display more than 2 values.");
	}
}

void Screen::displayInfo(const char* msg)
{
	_oled->clearDisplay();
	_oled->setCursor(0, 0);
	_oled->setTextSize(1);
	_oled->setTextColor(WHITE);
	_oled->println(msg);
	_oled->display();
}

Screen::~Screen()
{
	if (_oled)
	{
		delete _oled;
	}
}