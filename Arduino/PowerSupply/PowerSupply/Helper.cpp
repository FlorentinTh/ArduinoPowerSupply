/**
 *	Name:		Helper.cpp
 *	Author:		FlorentinTh
 **/

#include "Helper.h"

void Helper::log(Code code, String msg)
{
#if LOG_VERBOSE
	Serial.print("[INFO-");
	Serial.print(code);
	Serial.print("] ");
	Serial.println(msg);
#endif
}

void Helper::warn(Code code, String msg)
{
#if LOG_VERBOSE
	Serial.print("[WARN-");
	Serial.print(code);
	Serial.print("] ");
	Serial.println(msg);
#endif
}

void Helper::error(Code code, String msg)
{
#if LOG_VERBOSE
	Serial.print("[ERR-");
	Serial.print(code);
	Serial.print("] ");
	Serial.println(msg);
#endif
}
