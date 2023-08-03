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
    Utils Ut;

	void Utils::strCpy(char* des, const char* src) {
		while (*src != '\0') {
			*des = *src;
			des++;
			src++;
		}
		*des = '\0';
	}
	int Utils::strLen(const char* s) {
		int len = 0;
		while (*s != '\0') {
			len++;
			s++;
		}
		return len;
	}
    const char* Utils::strStr(const char* str1, const char* str2) {
    while (*str1 != '\0') {
        const char* p1 = str1;
        const char* p2 = str2;
        while (*p2 != '\0' && *p1 == *p2) {
            p1++;
            p2++;
        }
        if (*p2 == '\0') {
            return str1;
        }
        str1++;
    }
    return nullptr;
    }
    void Utils::strnCpy(char* des, const char* src, int len) {
        int i;
        for (i = 0; i < len && src[i] != '\0'; i++) {
            des[i] = src[i];
        }
        if (i < len) {
            des[i] = '\0';
        }
    }
    //directly copied from https://github.com/Seneca-244200/OOP244-NAA-NBB-ZAA-Notes
    // some modifications implimented.

    void Utils::reAloCpy( char*& des, const char* src ) {
       delete[] des;
       Ut.aloCpy( des, src );
    }

    void Utils::aloCpy( char*& des, const char* src ) {
       des = nullptr;
       if ( src ) {
           des = new char[Ut.strLen( src ) + 1];
          Ut.strCpy( des, src );
       }
    }
}
