//
//  Line.hpp
//  WS8
//
//  Created by aydin ghorbani
//
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
