/*
 ****************************************
 Full Name  : aydi ghorbani
 Student ID#: 124170226
 Email      : aghorbani8@myseneca.ca
 
 
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 ****************************************
 */
#ifndef SDDS_SHAPE_H_
#define SDDS_SHAPE_H_
#include <iostream>

namespace sdds
{
  class Shape
  {
  public:
    virtual ~Shape() {}
    virtual void draw(std::ostream &ostr) const  {};
    virtual void getSpecs(std::istream &istr) {};
  };

  std::ostream &operator<<(std::ostream &ostr, const Shape &src);
  std::istream &operator>>(std::istream &istr, Shape &src);
}

#endif
