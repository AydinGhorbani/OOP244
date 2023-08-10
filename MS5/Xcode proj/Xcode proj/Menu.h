/* Citation and Sources...
Final Project Milestone 1
Filename: Menu.h
Version 1.0
Author	Aydin Ghoebani
-----------------------------------------------------------
Date      Reason
2023/07/13  Preliminary release
2023/07/15  Debugged DMA
----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#ifndef SDDS_MENU_H
#define SDDS_MENU_H

#include <iostream>

namespace sdds {
    const int  MAX_MENU_ITEMS = 20;

    class MenuItem {
    private:
        char* menuContent{};
        MenuItem();
        MenuItem(const char* textContent);
        void setEmpty();
        MenuItem(const MenuItem& menuItem) = delete;
        void operator=(const MenuItem& MI) = delete;
        operator bool() const;
        operator const char* () const;
        std::ostream& display(std::ostream& os = std::cout);
        ~MenuItem();
        friend class Menu;
    };

    class Menu {
    private:
        MenuItem menuTitle{};
        MenuItem* menuItems[MAX_MENU_ITEMS]{};
        unsigned int pointerCount = 0;

    public:
        Menu();
        Menu(const char* title);
        ~Menu();
        Menu(const Menu& M) = delete;
        void operator=(const Menu& M) = delete;
        std::ostream& displayMenuTitle(std::ostream& os);
        std::ostream& displayMenu(std::ostream& os = std::cout);
        operator int();
        operator unsigned int();
        operator bool();
        int run();
        int operator~();
        Menu& operator<<(const char* menuitemContent);
        const char* operator[](unsigned int index) const;
    };
    std::ostream& operator<<(std::ostream& os, Menu& menu);
    int getIntegerInput(int minRange, int maxRange);
}

#endif
