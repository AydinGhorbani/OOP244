// Final Project Milestone 1
// Date Module
// File    Date.cpp
// Version 1.0
// Author    Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name  aydin Ghorbani             Date                     Reason
//
/////////////////////////////////////////////////////////////////
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"
#include "Publication.h"
#include "Book.h"
namespace sdds {
   class LibApp {
       bool m_changed;
       Menu m_mainMenu;
       Menu m_exitMenu;
       Menu m_publication;
       int m_no;
       int m_LLRN;
       char m_fileName[256 + 1];
       Publication* m_publicationPtr[SDDS_LIBRARY_CAPACITY + 1];
       bool confirm(const char* message);
       void load();  // prints: "Loading Data"<NEWLINE>
       void save();  // prints: "Saving Data"<NEWLINE>
       int search(int search);  // prints: "Searching for publication"<NEWLINE>

       void returnPub();  /*  Calls the search() method.
                              prints "Returning publication"<NEWLINE>
                              prints "Publication returned"<NEWLINE>
                              sets m_changed to true;
                          */
       void newPublication();
       void removePublication();
       void checkOutPub();
   public:
       Publication* getPub(int libRef);

       LibApp(const char* fileName);
       void run();
       virtual ~LibApp();
   };
}
#endif // !SDDS_LIBAPP_H



