/*
 ****************************************
 Full Name  : aydi ghorbani
 Student ID#: 124170226
 Email      : aghorbani8@myseneca.ca
 
 
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 ****************************************
 */
#include <iostream>
#include "Shape.h"
namespace sdds
{
  std::ostream &operator<<(std::ostream &ostr, const Shape &src)
  {
    src.draw(ostr);
    return ostr;
  }
  std::istream &operator>>(std::istream &istr, Shape &src)
  {
    src.getSpecs(istr);
    return istr;
  }
};
