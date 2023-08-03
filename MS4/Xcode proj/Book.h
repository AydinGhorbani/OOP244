// Final Project Milestone 1
// Date Module
// File    Date.cpp
// Version 1.0
// Author    Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name  aydin Ghorbani             Date 23/07/14                    Reason
//
/////////////////////////////////////////////////////////////////
#pragma once
#include "Publication.h"
#include "Utils.h"

namespace sdds{
    class Book : public Publication
    {
        char* m_name;
    public:
        Book();
        Book(const Book& src);
        virtual ~Book();
        Book& operator=(const Book& src);
        
        char type()const;
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& istr);
        void set(int m_id);
        operator bool() const;
    };

}
