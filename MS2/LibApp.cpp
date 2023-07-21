#include <iostream>
#include "LibApp.h"
using namespace std;

namespace sdds {
    void LibApp::load() {
        cout << "Loading Data" << endl;
    }
    void LibApp::save() {
        cout << "Saving Data" << endl;
    }
    void LibApp::search() {
        cout << "Searching for publication" << endl;
    }
    void LibApp::returnPub() {
        search();
        cout << "Returning publication" << endl;
        cout << "Publication returned" << endl;
        cout << endl;
        m_changed = true;
    }
    LibApp::LibApp() : m_mainMenu("Seneca Library Application\n"),
        m_exitMenu("Changes have been made to the data, what would you like to do?\n") {
        m_changed = false;
        m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";

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
        cout << "Adding new publication to library" << endl;
        if (confirm("Add this publication to library?")) {
            m_changed = true;
            cout << "Publication added" << endl;
        }
    }
    void LibApp::removePublication() {
        cout << "Removing publication from library" << endl;
        search();
        if (confirm("Remove this publication from the library?")) {
            m_changed = true;
            cout << "Publication removed" << endl;
        }
    }
    void LibApp::checkOutPub() {
        search();
        if (confirm("Check out publication?")) {
            m_changed = true;
            cout << "Publication checked out" << endl;
        }
    }
    void LibApp::run() {
        int selection;
        int exitSelection;

        do {
            selection = m_mainMenu.run();

            switch (selection) {
            case 0:
                if (m_changed) {
                    exitSelection = m_exitMenu.run();
                    if (exitSelection == 1) {
                        save();
                    }
                    else if (exitSelection == 2) {
                        selection = 1;
                    }
                    else if (exitSelection == 0) {
                        if (confirm("This will discard all the changes, are you sure?")) {
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
            cout << selection << "<<<<<<<selection<<<<<<<<" << endl;
           
        } while (selection != 0);
    
       cout << "-------------------------------------------" << endl;
       cout << "Thanks for using Seneca Library Application" << endl;
    }
}
