//Full Name  : Aydin Ghorabni
//Student ID#: 124226170
//Email      : aghorbani8@museneca.ca
//Date       : May 28rd, 2023
//Authenticity Declaration:
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider. This submitted
//piece of work is entirely of my own creation.



#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
FILE* fptr;
bool openFile(const char filename[])
{
    fptr = fopen(filename, "r");
    return fptr != NULL;
}
int noOfRecords()
{
    int noOfRecs = 0;
    char ch;
    while (fscanf(fptr, "%c", &ch) == 1)
    {
        noOfRecs += (ch == '\n');
    }
    rewind(fptr);
    return noOfRecs;
}
void closeFile()
{
    if (fptr) fclose(fptr);
}
bool read(char m_postalcode[])
{
    return fscanf(fptr, "%[^,],", m_postalcode) == 1;
}
bool read(int& m_pop)
{
    return fscanf(fptr, "%d\n", &m_pop) == 1;
}
}
