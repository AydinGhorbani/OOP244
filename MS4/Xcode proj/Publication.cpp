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
#include <string>
#include <iomanip>
#include "Utils.h"
#include "Publication.h"

namespace sdds {

// to avoid code duplication.
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

	Publication& Publication::operator=(const Publication& publication) {
		set(publication.m_membership);
		setRef(publication.m_libRef);
		Ut.strCpy(m_shelfId, publication.m_shelfId);
		m_date = publication.m_date;
		if (m_title)
		{
			delete[] m_title;
		}
        
		if (publication.m_title) {
            Ut.aloCpy(m_title, publication.m_title);
		}
		else {
			m_title = nullptr;
		}

		return *this;
	}


    // set functions are divided from other methods so it can be easily read and rewied for further
    // milestones.
	void Publication::set(int member_id)
	{
		m_membership = member_id;
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
    return m_membership;
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
    char titleInput[SDDS_TITLE_WIDTH + 1]={0};
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
    if (conIO(os)) {
        os << "| " << m_shelfId << " | " << std::setw(30) << std::left << std::setfill('.') << m_title << " | ";
    } else {
        os << type() << "\t" << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t";
    }

    if (m_membership != 0) {
        os << m_membership;
    } else {
        os << " N/A ";
    }

    os << " | " << m_date;

        if (conIO(os)) {
            os << " |";
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

