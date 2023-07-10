/*
 ****************************************
 Full Name  : Aydin Ghorbani
 Student ID#: 124170226
 Email      : aghorbani8@myseneca.ca
 
 completion date (updated) : 4/june/23
 
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 ****************************************
 */
#ifndef SDDS_CSTRING_H_
#define SDDS_CSTRING_H_

namespace sdds {

//Copies the string pointed to by 'src' into the character array 'des'.
void strCpy(char* des, const char* src);

//Copies at most 'len' characters from the string pointed to by 'src' into
//the character array 'des'.
void strnCpy(char* des, const char* src, int len);

//Compares two strings with each other.
int strCmp(const char* s1, const char* s2);

// Compares at most 'len' characters of two strings
int strnCmp(const char* s1, const char* s2, int len);

//Calculates the length of a null-terminated string.
int strLen(const char* s);

// Searches for the first occurrence of the substring 'str2' within the string 'str1'.
const char* strStr(const char* str1, const char* str2);

//Concatenates the string pointed to by 'src' to the end of the string pointed to by'des'.
void strCat(char* des, const char* src);


char* subStr(const char* str, int start, int length) ;

}
#endif // !SDDS_CSTRING_H_



