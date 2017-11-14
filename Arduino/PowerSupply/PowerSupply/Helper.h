/**
 *	Name:		Helper.h
 *	Author:		FlorentinTh
 **/

#ifndef _HELPER_h
#define _HELPER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Config.h"

enum Code
{
	SETUP_OK = 0x100,
	SETUP_ERROR = 0x130,

	CONFIG_OK = 0x101,
	CONFIG_ERROR = 0x131,

	SCREEN_ERROR = 0x530,
};


class Helper
{
public:
	static void log(Code code, String msg);
	static void warn(Code code, String msg);
	static void error(Code code, String msg);

private:
	Helper();
};

#endif

