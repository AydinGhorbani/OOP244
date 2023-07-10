//Full Name  : Aydin Ghorabni
//Student ID#: 124226170
//Email      : aghorbani8@museneca.ca
//Date       : May 28rd, 2023
//Authenticity Declaration:
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider. This submitted
//piece of work is entirely of my own creation.

#pragma once
namespace sdds {
bool openFile(const char filename[]);
void closeFile();
int noOfRecords();
bool read(char pCode[]);
bool read(int& pop);
}

