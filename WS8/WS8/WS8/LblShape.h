/*
 ****************************************
 Full Name  : aydi ghorbani
 Student ID#: 124170226
 Email      : aghorbani8@myseneca.ca
 
 
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 ****************************************
 */
#ifndef SDDS_Lblshape_H_
#define SDDS_Lblshape_H_

#include "Shape.h"

namespace sdds
{
  class LblShape : public Shape
  {
    char *m_label {};

  protected:
      
    const char* label() const;
    void getSpecs(std::istream &istr);
      
  public:
    LblShape() {}
    LblShape(const char *_label);
    virtual ~LblShape();

    LblShape &operator=(const LblShape &src) = delete;
      LblShape(const LblShape &src) = delete;
  };
}
#endif
