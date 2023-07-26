//
//  LblShape.cpp
//  WS8
//
//  Created by aydin ghorbani
//
#include <iostream>
#include <cstring>
#include <string>
#include "LblShape.h"

using namespace std;

namespace sdds
{
  const char* LblShape::label() const
  {
    return m_label;
  }
  LblShape::LblShape(const char *_label)
  {
    if (_label) {
      m_label = new char[strlen(_label) + 1];
      strcpy(m_label, _label);
    }
  }

  LblShape::~LblShape()
  {
    if (m_label) {
      delete[] m_label;
    }
  }

  void LblShape::getSpecs(std::istream &istr)
  {
    string _label;
    getline (istr, _label, ',');
    delete[] m_label;
    m_label = new char[strlen(_label.c_str()) + 1];
    strcpy(m_label, _label.c_str());
  }
}
