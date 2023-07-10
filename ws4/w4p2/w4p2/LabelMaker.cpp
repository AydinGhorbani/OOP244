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
#include "LabelMaker.h"
#include "cstring.h"
using namespace std;

namespace sdds {
  // Constructor
  LabelMaker::LabelMaker(int noOfLabels)
  {
    if (noOfLabels > 0) {
      totalLabels = noOfLabels;
      listOfLabels = new Label[noOfLabels];
    }
    else {
      std::cout << "You can only input a value greater than zero" << std::endl;
      totalLabels = 0;
    }
  }

  // Destructor
  LabelMaker::~LabelMaker()
  {
    delete[] listOfLabels;
    listOfLabels = nullptr;
  }

  // Read labels from user input
  void LabelMaker::readLabels()
  {
    if (totalLabels > 0) {
      std::cout << "Enter " << totalLabels << " labels:" << std::endl;

      for (int i = 0; i < totalLabels; i++) {
        std::cout << "Enter label number " << i + 1 << std::endl;
        listOfLabels[i].readLabel();
      }
    }
  }

  // Print labels
  void LabelMaker::printLabels()
  {
    for (int i = 0; i < totalLabels; i++) {
      listOfLabels[i].printLabel();
      std::cout << std::endl;
    }
  }
} 
