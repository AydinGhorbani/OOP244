//
//  Shape.hpp
//  WS8
//
//  Created by aydin ghorbani
//
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
