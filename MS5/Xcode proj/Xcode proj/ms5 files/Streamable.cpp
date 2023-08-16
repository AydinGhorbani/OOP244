// Final Project Milestone 1
// Date Module
// File    Streamable.cpp
// Version 1.0
// Author    Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name  aydin Ghorbani                        Reason
//
/////////////////////////////////////////////////////////////////
#include "Streamable.h"

namespace sdds {

    std::ostream& operator<<(std::ostream& os, const Streamable& s) {
        if(s) s.write(os);	
        return os;
    }

    std::istream& operator>>(std::istream& is, Streamable& s) {
        return (s.read(is));
    }

}
