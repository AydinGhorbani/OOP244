/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
// Version  2.0
// Date     Date 23/07/13
// Author   Aydin Ghorbani
// Description
//
// Revision History
// -----------------------------------------------------------
// Name   Aydin Ghorbani         Date 23/07/13           Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include "Utils.h"
namespace sdds {
	void strCpy(char* des, const char* src) {
		while (*src != '\0') {
			*des = *src;
			des++;
			src++;
		}
		*des = '\0';
	}
	int strLen(const char* s) {
		int len = 0;
		while (*s != '\0') {
			len++;
			s++;
		}
		return len;
	}
}
