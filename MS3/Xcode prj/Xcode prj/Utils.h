/***********************************************************************
// OOP244 Utils Module
// File	Utils.h
// Version  2.0
// Date     Date 23/07/13
// Author   Aydin Ghorbani
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__

    namespace sdds {
    class Utils{
    public:
        void strCpy(char* des, const char* src);
        int strLen(const char* s);
        const char* strStr(const char* str1, const char* str2);
        void reAloCpy( char*& des, const char* src );
        void aloCpy( char*& des, const char* src );
    };
}
#endif 
