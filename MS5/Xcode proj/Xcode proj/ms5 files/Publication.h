// Final Project Milestone 1
// Date Module
// File    Publication.h
// Version 1.0
// Author    Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name  aydin Ghorbani                        Reason
//
/////////////////////////////////////////////////////////////////
#ifndef SDDS_PUBLICATION_H__
#define SDDS_PUBLICATION_H__

#include "Date.h"
#include "Streamable.h"
#include "Lib.h"

namespace sdds {

	class Publication : public Streamable {

	private:
        
		char* m_title;
		char m_shelfId[SDDS_SHELF_ID_LEN + 1];
		int m_membership;
		int m_libRef;
		Date m_date;

	public:
        void setEmpty();
		Publication();
		Publication(const Publication& publication);
		Publication& operator=(const Publication& publication);
		virtual void set(int member_id);
		// Sets the membership attribute to either zero or a five-digit integer.
		void setRef(int value);
        //Returns true if the argument title appears anywhere in the title of the
		void resetDate();
		// Sets the date to the current date of the system.
		virtual char type()const;
		//Returns the character 'P' to identify this object as a "Publication object"
		bool onLoan()const;
		//Returns true is the publication is checkout (membership is non-zero)
		Date checkoutDate()const;
		//Returns the date attribute
		bool operator==(const char* title)const;
		//publication. Otherwise, it returns false; (use strstr() function in <cstring>)
		operator const char* ()const;
		//Returns the title attribute
		int getRef()const;
		//Returns the libRef attirbute.
		bool conIO(std::ios& io) const;
        operator bool() const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& istr);

		~Publication();

	};

}

#endif

