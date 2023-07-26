/*
 ****************************************
 Full Name  : aydi ghorbani
 Student ID#: 124170226
 Email      : aghorbani8@myseneca.ca
 
 
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 ****************************************
 */
#include <iostream>
#include <iomanip>
#include "Line.h"

using namespace std;

namespace sdds
{
  Line::Line(const char* _label, int _length) : LblShape(_label)
  {
    if (_length > 0)
      m_length = _length;
  }

  void Line::getSpecs(std::istream &istr)
  {
    size_t _len;
    bool _exit = false;

    while (!_exit)
    {
      LblShape::getSpecs(istr);
      istr >> _len;

      if (!istr) {
        istr.clear();
        istr.ignore(6000, '\n');
      }
      else {
        istr.ignore();
        m_length = _len;
        _exit = true;
      }
    }
  }

  void Line::draw(std::ostream &ostr) const
  {
      if (m_length > 0 && LblShape::label()) {
          // Output the label followed by a newline
          ostr << LblShape::label() << std::endl;

          // Output a line of '=' characters with the specified width
          ostr << setw(m_length)<< setfill('=') << '=';
      }

    }
}
