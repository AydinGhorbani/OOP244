// Final Project Milestone 1
// Date Module
// File    Publication.cpp
// Version 1.0
// Author    Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name  aydin Ghorbani                           Reason
//
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Utils.h"
#include "Publication.h"
using namespace std;
namespace sdds {

void Publication::setEmpty(){
    m_title = nullptr;
    m_shelfId[0] = '\0';
    m_membership = 0;
    m_libRef = -1;
}
	Publication::Publication()
	{
        setEmpty();
	}

	Publication::Publication(const Publication& publication) {
		*this = publication;
	}

Publication& Publication::operator=(const Publication& source)
{
   set(source.m_membership);
   setRef(source.m_libRef);
   Ut.strCpy(this->m_shelfId, source.m_shelfId);
   this->m_date = source.m_date;

   if (this) {
      delete[] m_title;
   }
   Ut.aloCpy(this->m_title, source.m_title);
   return *this;
}


    // set functions are divided from other methods so it can be easily read and rewied for further
    // milestones.
	void Publication::set(int member_id)
	{
        if (member_id < 100000 && member_id> 9999) {
           m_membership = member_id;
        }
        else {
           m_membership = 0;
        }
     
	}

	void Publication::setRef(int value)
	{
		m_libRef = value;
	}
	void Publication::resetDate() {
		m_date = Date();
	}
	char Publication::type() const
	{
		return 'P';
	}
   bool Publication::onLoan() const {
    return m_membership != 0;
    }
	Date Publication::checkoutDate()const {
		return m_date;
	}
    bool Publication::operator==(const char* title) const {
    return Ut.strStr(m_title, title);
    }

	Publication::operator const char* ()const {
		return m_title;
	}
    bool Publication::conIO(std::ios& io)const {

    if (&io == &std::cin || &io == &std::cout) {
        return true;
    }
    return false;

    }
	int Publication::getRef()const {
		return m_libRef;
	}

std::istream& Publication::read(std::istream& istr) {
    char titleInput[256]{};
    char shelfIdInput[SDDS_SHELF_ID_LEN + 1]={0};
    int libRefInput = -1;
    int membershipInput = 0;
    Date dateInput;

    if (m_title) {
        delete[] m_title;
    }
    setEmpty();
    resetDate();

    if (conIO(istr)) {
        std::cout << "Shelf No: ";
        istr.getline(shelfIdInput, SDDS_SHELF_ID_LEN + 1);

        if (Ut.strLen(shelfIdInput) != SDDS_SHELF_ID_LEN) {
            istr.setstate(std::ios::failbit);
        }
        std::cout << "Title: ";
        istr.getline(titleInput, 256);
        std::cout << "Date: ";
        istr >> dateInput;
        
    } else {
        istr >> libRefInput;
        istr.ignore();
        istr.getline(shelfIdInput, SDDS_SHELF_ID_LEN + 1, '\t');
        istr.getline(titleInput, 256, '\t');
        istr >> membershipInput;
        istr.ignore();
        istr >> dateInput;
    }

    if (!dateInput) {
        istr.setstate(std::ios::failbit);
    }
    if (istr) {
        Ut.aloCpy(m_title, titleInput);
        Ut.strCpy(m_shelfId, shelfIdInput);
        m_membership = membershipInput;
        m_date = dateInput;
        m_libRef = libRefInput;
    }

    return istr;
}

std::ostream& Publication::write(std::ostream& os) const {
    
       char temp[SDDS_TITLE_WIDTH + 1] = { 0 };
       Ut.strnCpy(temp, m_title, SDDS_TITLE_WIDTH);

    if (conIO(os)) {
        os << "| " << m_shelfId << " | " << setw(30) << left << setfill('.') << temp << " | ";

        if (onLoan()) {
            os << m_membership;
        } else {
            os << " N/A ";
        }

        os << " | " << m_date << " |";
    }

       
       else {
          os << type() << "\t";
          os << m_libRef << "\t" ;
          os << m_shelfId << "\t";
          os << m_title << "\t";
          os << m_membership << "\t" ;
          os << m_date;
       }
       return os;
    }

	Publication::operator bool() const {

		if (m_title && m_shelfId[0] != '\0') {
			return true;
		}

		return false;

	}

	Publication::~Publication()
	{
		delete[] m_title;
	}
}

