/*
 ****************************************
 Full Name  : aydi ghorbani
 Student ID#: 124170226
 Email      : aghorbani8@myseneca.ca
 
 
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 ****************************************
 */
#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_
#include "LblShape.h"

namespace sdds
{
  class Line : public LblShape
  {
    size_t m_length {};
  protected:
      
    void getSpecs(std::istream &istr);
    void draw(std::ostream &os) const;
  public:
    Line() {};
    Line(const char *_label, int _length);
    virtual ~Line() {};

  };
}
#endif
