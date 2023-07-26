//
//  Rectangle.hpp
//  WS8
//
//  Created by aydin ghorbani
//
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
