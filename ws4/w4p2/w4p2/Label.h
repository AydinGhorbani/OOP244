/*
 ****************************************
 Full Name  : Aydin Ghorbani
 Student ID#: 124170226
 Email      : aghorbani8@myseneca.ca
 
 completion date (updated) : 9/june/23
 
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 ****************************************
 */
#pragma once

using namespace std;

namespace sdds {
  const char defaultSymbol[9] = "+-+|+-+|";

  class Label
  {
    char symbol[9];
    char *oneLineText;

  public:
   
    Label();
    Label(const char *frameArg);

    Label(const char *frmaeArg, const char *content);
    ~Label();

    void readLabel();
    std::ostream &printLabel() const;
  };
}

