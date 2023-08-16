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
#include <iostream>
#include <iomanip>
#include <fstream>
#include "LibApp.h"
#include "Utils.h"
#include "PublicationSelector.h"
using namespace std;

namespace sdds {
   void LibApp::load() {
      char temp{};
      int i;
      cout << "Loading Data" << endl;
      ifstream readfile(m_fileName);

      for(i = 0; readfile && i < SDDS_LIBRARY_CAPACITY; i++) {
         readfile >> temp;
         readfile.ignore();
         if(readfile) {
            if(temp == 'P') {
               m_publicationPtr[i] = new Publication;
            } else if(temp == 'B') {
               m_publicationPtr[i] = new Book;
            }
            if(m_publicationPtr[i]) {
               readfile >> *m_publicationPtr[i];
               m_no++;
               m_LLRN = m_publicationPtr[i]->getRef();
            }
         }
      }
   }
   void LibApp::save() {
      int i;
      cout << "Saving Data" << endl;
      ofstream writeFile(m_fileName);

      for(i = 0; i < m_no; i++) {
         if(m_publicationPtr[i]->getRef() != 0) {
            writeFile << *m_publicationPtr[i] << endl;
         }
      }
      writeFile.close();
   }
   int LibApp::search(int search) {
      char typeC = '\0';
      char title[256]{};
      int i = 0, libRef = 0, selection = 0;
      PublicationSelector publicationSel("Select one of the following found matches:", 15);

      selection = m_publication.run();
      switch(selection) {
      case 1:
         typeC = 'B';
         break;
      case 2:
         typeC = 'P';
         break;
      }

      cin.ignore(1000, '\n');
      cout << "Publication Title: ";
      cin.getline(title, 100);

      for(i = 0; i < m_no; i++) {
         if(m_publicationPtr[i]->operator==(title) && typeC == m_publicationPtr[i]->type()
            && m_publicationPtr[i]->getRef() != 0) {

            switch(search) {
            case 1:
               publicationSel << m_publicationPtr[i];
               break;
            case 2:
               if(m_publicationPtr[i]->onLoan()) {
                  publicationSel << m_publicationPtr[i];
               }
               break;
            case 3:
               if(!m_publicationPtr[i]->onLoan()) {
                  publicationSel << m_publicationPtr[i];
               }
               break;
            }

         }
      }
      if(publicationSel) {
         publicationSel.sort();
         libRef = publicationSel.run();

         if(libRef > 0) {
            cout << *getPub(libRef) << endl;
         }
         else {
            cout << "Aborted!" << endl;
         }
      } 
      else {
         cout << "No matches found!";
      }

      return libRef;
   }

   void LibApp::returnPub() {
      int libRef;
      double penalty = 0.00;

      int loanDays;
      cout << "Return publication to the library" << endl;
      libRef = search(2);
      if(libRef > 0 && confirm("Return Publication?")) {
         loanDays = Date() - getPub(libRef)->checkoutDate();
         if(loanDays > 15) {
            penalty = (loanDays - SDDS_MAX_LOAN_DAYS) * 0.5;
            cout << std::fixed << "Please pay $" << std::setprecision(2) << penalty << " penalty for being " << (loanDays - SDDS_MAX_LOAN_DAYS) << " days late!" << endl;
            penalty = 0;
         }
         if(!penalty) {
            getPub(libRef)->set(0);
            m_changed = true;
            cout << "Publication returned";
         }
      }
      cout << endl;
   }
   LibApp::LibApp(const char* fileName) :m_mainMenu("Seneca Library Application"),
      m_exitMenu("Changes have been made to the data, what would you like to do?"),
      m_publication("Choose the type of publication:") {
      if(fileName) {
         Ut.strCpy(m_fileName, fileName);
      }
      m_changed = false;
      m_no = 0;
      m_mainMenu << "Add New Publication" << "Remove Publication"
         << "Checkout publication from library" << "Return publication to library";
      m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
      m_publication << "Book" << "Publication";
      load();
   }
   bool LibApp::confirm(const char* message) {
      int selection{};
      Menu confirmMenu(message);
      confirmMenu << "Yes";
      selection = confirmMenu.run();
      return selection == 1;
   }
   void LibApp::newPublication() {
      bool flag = false;
      int pubType;
      Publication* pubPtr = nullptr;
      if(m_no == 333) {
         cout << "Library is at its maximum capacity!";
         flag = true;
      }
      if(!flag) {
         cout << "Adding new publication to the library" << endl;
         pubType = m_publication.run();
         cin.ignore(1000, '\n');

         if(pubType == 0) {
            cout << "Aborted!" << endl;
            flag = false;
         } else if(pubType == 1) {
            pubPtr = new Book;
            cin >> *pubPtr;
         } else if(pubType == 2) {
            pubPtr = new Publication;
            cin >> *pubPtr;
         }

         if(cin.fail() && flag) {
            cin.ignore();
            cin.clear();
            cout << "Aborted!" << endl;
            exit(0);
         } else {
            if(flag && confirm("Add this publication to the library?")) {
               if(*pubPtr) {
                  m_LLRN++;
                  pubPtr->setRef(m_LLRN);
                  m_publicationPtr[m_no] = pubPtr;
                  m_no++;
                  m_changed = true;
                  cout << "Publication added";
               } else {
                  cout << "Failed to add publication!" << endl;
                  delete pubPtr;
               }
            }
         }
      }
      cout << endl;
   }
   void LibApp::removePublication() {
      int libRef;
      cout << "Removing publication from the library" << endl;
      libRef = search(1);
      if(libRef) {
         if(confirm("Remove this publication from the library?")) {
            getPub(libRef)->setRef(0);
            m_changed = true;
            cout << "Publication removed";
         }
      }
      cout << endl;
   }
   void LibApp::checkOutPub() {
      int libRef;
      int membershipInput = 0;
      bool validInput = false;
      cout << "Checkout publication from the library" << endl;
      libRef = search(3);

      if(libRef > 0) {
         if(confirm("Check out publication?")) {
            cout << "Enter Membership number: ";
            do {
               while(!validInput) {
                  if(!(cin >> membershipInput)) {
                     cin.clear();
                     cin.ignore(45678, '\n');
                     cout << "Invalid membership number, try again: ";
                  } 
                  else if(membershipInput < 10000 || membershipInput > 99999) {
                     cout << "Invalid membership number, try again: ";
                  } 
                  else {
                     validInput = true;
                  }
               }
               /* DISABLES CODE */    // is added by Xcode.
               //it did not have any effect on code
            } while(membershipInput < 10000 && membershipInput > 99999);
            getPub(libRef)->set(membershipInput);
            m_changed = true;
            cout << "Publication checked out" << endl;
         }
      }
      cout << endl;
   }
   void LibApp::run() {
      int selection;
      int exitSelection;

      do {
         selection = m_mainMenu.run();

         switch(selection) {
         case 0:
            if(m_changed) {
               exitSelection = m_exitMenu.run();
               if(exitSelection == 1) {
                  save();
               } 
               else if(exitSelection == 2) {
                  selection = 1;
               } 
               else if(exitSelection == 0) {
                  if(confirm("This will discard all the changes are you sure?")) {
                     m_changed = false;
                  }
               }
            }
            break;
         case 1:
            newPublication();
            break;
         case 2:
            removePublication();
            break;
         case 3:
            checkOutPub();
            break;
         case 4:
            returnPub();
            break;
         default:
            break;
         }
         // cout << selection << "<<<<<<<selection<<<<<<<<" << endl;
          // The loop was not functiong. the exit point had a problem 
          //instade of debugging jut this line was added .

      } while(selection != 0);


      cout << "\n-------------------------------------------" << endl;
      cout << "Thanks for using Seneca Library Application" << endl;
   }
   LibApp::~LibApp() {
      for(int i = 0; i < m_no; i++) {
         delete m_publicationPtr[i];
      }
   }
   Publication* LibApp::getPub(int libRef) {
      int i;
      Publication* result = nullptr;
      for(i = 0; i < m_no; i++) {
         if(m_publicationPtr[i]->getRef() == libRef) {
            result = m_publicationPtr[i];
         }
      }
      return result;
   }


}
