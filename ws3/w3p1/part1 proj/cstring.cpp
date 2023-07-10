/*
 ****************************************
 Full Name  : aydi ghorbani
 Student ID#: 124170226
 Email      : aghorbani8@myseneca.ca
 
 completion date : 23/06/01
 
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 ****************************************
 */
#include "cstring.h"

namespace sdds{
void strCpy(char* des, const char* src) {
    while (*src != '\0') {
        *des = *src;
        des++;
        src++;
    }
    *des = '\0';
}


void strnCpy(char* des, const char* src, int len) {
    int i;
    for (i = 0; i < len && src[i] != '\0'; i++) {
        des[i] = src[i];
    }
    if (i < len) {
        des[i] = '\0';
    }
}


int strCmp(const char* s1, const char* s2) {
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2) {
            return *s1 - *s2;
        }
        s1++;
        s2++;
    }
    return *s1 - *s2;
}


int strnCmp(const char* s1, const char* s2, int len) {
    int i;
    for (i = 0; i < len && s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
    }
    if (i < len) {
        return s1[i] - s2[i];
    }
    return 0;
}


int strLen(const char* s) {
    int len = 0;
    while (*s != '\0') {
        len++;
        s++;
    }
    return len;
}


const char* strStr(const char* str1, const char* str2) {
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


void strCat(char* des, const char* src) {
    while (*des != '\0') {
        des++;
    }
    while (*src != '\0') {
        *des = *src;
        des++;
        src++;
    }
    *des = '\0';
}
}
