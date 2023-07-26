//
//  Rectangle.cpp
//  WS8
//
//  Created by aydin ghorbani
//
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Rectangle.h"
#define MAX_HEIGHT 3

using namespace std;

namespace sdds
{
  Rectangle::Rectangle(const char *_label, int _width, int _height) : LblShape(_label)
  {
    size_t _secWidth {};
    _secWidth = strlen(LblShape::label()) + 2;
    if (_width > _secWidth && _height > MAX_HEIGHT) {
      m_width = _width;
      m_height = _height;
    }
  }

  void Rectangle::getSpecs(std::istream &istr)
  {
    size_t _width;
    size_t _height;
    char _comma;
    bool _escape = false;

    do {
      LblShape::getSpecs(istr);
      istr >> _width >> _comma >> _height;
      if (!istr) {
        istr.clear();
        istr.ignore(6000, '\n');
      }
      else {
        istr.ignore();
        m_width = _width;
        m_height = _height;
        _escape = true;
      }
    } while (!_escape);
  }


#include <iomanip>

void Rectangle::draw(std::ostream &ostr) const {
    if (m_width > 0 && m_height > 0) {
        // Draw the top border of the rectangle
        ostr << '+';
        ostr << setw(m_width - 2) << setfill('-') << '-' << '+';
        ostr << std::endl;

        // Draw the label row
        ostr << '|';
        ostr << setw(m_width - 2) << setfill(' ') << std::left << LblShape::label() << '|';
        ostr << std::endl;

        // Draw the middle rows
        for (unsigned int i = 0; i < (m_height - 3); i++) {
            ostr << '|';
            ostr << setw(m_width - 2) << setfill(' ') << ' ' << '|';
            ostr << endl;
        }

        // Draw the bottom border of the rectangle
        ostr << '+';
        ostr << setw(m_width - 2) << setfill('-') << '-' << '+';
    }
 
  }
}
