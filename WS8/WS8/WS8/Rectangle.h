/*
 ****************************************
 Full Name  : aydi ghorbani
 Student ID#: 124170226
 Email      : aghorbani8@myseneca.ca
 
 
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 ****************************************
 */
#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_

#include "LblShape.h"

namespace sdds
{
  class Rectangle : public LblShape
  {
      // unsigned int also dose the same thing. basicly they are not different.
      // as it was mentioned in the class.
    size_t m_width  {};
    size_t m_height {};
  protected:
    void getSpecs(std::istream &istr);
    void draw(std::ostream &ostr) const;

  public:
    Rectangle() {}
    Rectangle(const char *_label, int _width, int _height);
      

  };
}
#endif
