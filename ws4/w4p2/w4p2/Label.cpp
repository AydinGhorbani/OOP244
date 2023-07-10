/*
 ****************************************
 Full Name  : Aydin Ghorbani
 Student ID#: 124170226
 Email      : aghorbani8@myseneca.ca
 
 completion date (updated) : 9/june/23
 
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 ****************************************
 */
#include <iostream>
#include <iomanip>
#include "Label.h"
#include "cstring.h"


using namespace std;

namespace sdds {
  Label::Label()
  {
    
    strCpy(symbol, defaultSymbol);

   
    oneLineText = nullptr;
  }

  Label::Label(const char *frameArg)
  {
   
    strCpy(symbol, frameArg);
    oneLineText = nullptr;
  }

  Label::Label(const char *frameArg, const char *content)
  {
    
    strCpy(symbol, frameArg);

    if (strLen(content) < 71) {
      oneLineText = new char[strLen(content) + 1];
      strCpy(oneLineText, content);
    }
  }

  Label::~Label()
  {
   
    if (oneLineText) {
      delete[] oneLineText;
      oneLineText = nullptr;
    }
  }

void Label::readLabel()
{
  char content[71];

  if (oneLineText != nullptr) {
    delete[] oneLineText;
    oneLineText = nullptr;
  }

  cout << "> ";
   cin.get(content, 71);

  cin.ignore(32767, '\n');

  
    
oneLineText = new char[strLen(content) + 1];
  strCpy(oneLineText, content);
}

std::ostream& Label::printLabel() const
{
  if (oneLineText != nullptr) {
    int middleSpace = strLen(oneLineText);

    std::cout << symbol[0] << std::setw(middleSpace + 3) << std::setfill(symbol[1]) << symbol[2] << std::endl;

    std::cout << symbol[7] << std::setw(middleSpace + 3) << std::setfill(' ') << symbol[3] << std::endl;

    std::cout << symbol[7] << std::setw(middleSpace + 1) << oneLineText << " " << symbol[3] << std::endl;

    std::cout << symbol[7] << std::setw(middleSpace + 3) << std::setfill(' ') << symbol[3] << std::endl;

    std::cout << symbol[6] << std::setw(middleSpace + 3) << std::setfill(symbol[5]) << symbol[4];
  }

  return std::cout;
}

}
