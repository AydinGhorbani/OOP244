
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
    #include "Book.h"
    #include "Utils.h"
    #include <iostream>
    #include <iomanip>


    using namespace std;

    namespace sdds{

    Book::Book() {
        m_name = nullptr;
    }
    char Book::type()const
    {
        return 'B';
    }

    Book::Book(const Book& src) :Publication(src)
    {
         if(src.m_name) Ut.reAloCpy(this->m_name, src.m_name);
    }


    Book& Book::operator=(const Book& src){
       if (this != &src) {
          Publication::operator=(src);
          if (src.m_name) {
              Ut.reAloCpy(this->m_name, src.m_name);
          }
       }
       return *this;
       
    }

    std::ostream& Book::write(std::ostream& os)const {
        Publication::write(os);
        if (conIO(os)) {
            char tempName[SDDS_AUTHOR_WIDTH + 1]{0};
            Ut.strnCpy(tempName, m_name, SDDS_AUTHOR_WIDTH);
            os << " " << setw(SDDS_AUTHOR_WIDTH) << left << setfill(' ') << tempName << " |";
        }
     else {
        os << "\t" << m_name;
     }
     return os;

    }

    std::istream& Book::read(std::istream& istr)
    {
       char tempAuthorName[100] = { 0 };
       Publication::read(istr);

       if (m_name) delete[] m_name;

       if (conIO(istr)) {
          istr.ignore();
          std::cout << "Author: ";
       }
       else {
          istr.ignore(1000,'\t');
       }
       istr.get(tempAuthorName, 100);
       if (istr) {
         Ut.reAloCpy(m_name, tempAuthorName);
       }
       return istr;
    }





    void Book::set(int m_id)
    {
       Publication::set(m_id);
       Publication::resetDate();
    }


    Book::operator bool() const
    {
       return m_name && Publication::operator bool();
    }


    Book::~Book(){
       if (m_name) delete[] m_name;
    }



    }
