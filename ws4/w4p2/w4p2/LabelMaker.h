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
#include "Label.h"

using namespace std;

namespace sdds {
  class LabelMaker
  {
    Label *listOfLabels;
    int totalLabels;

  public:
    LabelMaker(int noOfLabels);
    ~LabelMaker();

    void readLabels();
    void printLabels();
  };
}

