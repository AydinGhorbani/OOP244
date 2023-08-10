/* Citation and Sources...
Final Project Milestone 1
Filename: Menu.cpp
Version 1.0
Author	Aydin Ghoebani
-----------------------------------------------------------
Date      Reason
2023/07/13  Preliminary release
2023/07/15  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include "Utils.h"
#include <iomanip>
#include <iostream>
using namespace std;

namespace sdds {
    MenuItem::MenuItem() {
        setEmpty();
    }

    MenuItem::MenuItem(const char* textContent) {
        if (textContent && textContent[0]) {
            Ut.aloCpy(menuContent, textContent);
        }
        else {
            setEmpty();
        }
    }

    MenuItem::~MenuItem() {
        delete[] menuContent;
    }

    // Sets a MenuItem object to safe empty
    void MenuItem::setEmpty() {
        menuContent = nullptr;
    }

    // Return true, if it is not empty and it should return false if it is empty
    MenuItem::operator bool() const {
        return (menuContent && menuContent[0]);
    }

    // Should return the address of the content Cstring.
    MenuItem::operator const char* () const {
        return menuContent;
    }
    ostream& MenuItem::display(ostream& os) {
        if (*this) {
            os << menuContent;
        }
        return os;
    }
    Menu::Menu() {
        pointerCount = 0;
    };
    Menu::Menu(const char* title) : menuTitle(title) {};

    Menu::~Menu() {
        unsigned int i;
        for (i = 0; i < MAX_MENU_ITEMS; i++)
        {
            delete menuItems[i];
        }
    }
    ostream& Menu::displayMenuTitle(ostream& os) {
        if (menuTitle) {
            menuTitle.display();
        }

        return os;
    }

    ostream& Menu::displayMenu(ostream& os) {
        unsigned int i;
        if (menuTitle)
        {
            menuTitle.display(os);
            os << endl;
        }

        for (i = 0; i < pointerCount; i++)
        {
            os << ' ' << i + 1 << "- ";
            menuItems[i]->display(os);
            os << endl;
        }
        os << " 0- Exit" << endl;
        os << "> ";

        return os;
    }

    Menu::operator int() {
        return pointerCount;
    }

    Menu::operator unsigned int() {
        return pointerCount;
    }

    Menu::operator bool() {
        return (pointerCount > 0);
    }

    ostream& operator<<(ostream& os, Menu& menu) {
        return (menu.displayMenuTitle(os));
    }
    int Menu::run() {
        int user_input;
        displayMenu();
        user_input = getIntegerInput(0, pointerCount);
        return user_input;
    }
    int Menu::operator~() {
        return run();
    }
    Menu& Menu::operator<<(const char* menuitemContent) {
        if (pointerCount < MAX_MENU_ITEMS)
        {
            MenuItem* newMenuItem = new MenuItem(menuitemContent);
            menuItems[pointerCount] = newMenuItem;
            pointerCount++;
        }

        return *this;       
    }

    const char* Menu::operator[](unsigned int index) const {
        if (pointerCount > 0) {
            index %= pointerCount;
            return menuItems[index]->menuContent;
        }
        return nullptr;
    }

    int getIntegerInput(int minRange, int maxRange) {
        int input;
        bool validInt = false;
        while (!validInt) {
            if (!(cin >> input) || input < minRange || input > maxRange) {
                cout << "Invalid Selection, try again: ";
                cin.clear();
                cin.ignore(8765, '\n');

            }
            else if (input<minRange || input >maxRange) {
                cout << "Invalid Selection, try again: ";
            }
            else {
                validInt = true;
            }
        }
        return input;
    }
}
