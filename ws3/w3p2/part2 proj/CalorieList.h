/*
 ****************************************
 Full Name  : Aydin Ghorbani
 Student ID#: 124170226
 Email      : aghorbani8@myseneca.ca
 
 completion date : 4/june/23
 
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 ****************************************
 */
#pragma once
#include "Food.h"
namespace sdds
{
    class CalorieList
    {

        Food* f_list;
        int f_num;
        int f_add;

     
        // Calculates and returns the total number of calories in the list
        int totalCal() const;

        // Displays the title of the calorie list
        void title() const;

        // Displays the footer of the calorie list
        void footer() const;

        // Sets The CalorieList Object To An Empty State
        void setEmpty();


        // Checks if the food items in the list are valid
        bool isValid() const;

    public:
        // Sets it to an empty state if the size is invalid
        void init(int size);

        // Adds a food item to the CalorieList if there is available space in the array
        bool add(const char* item_name, int calories, int when);

        // Display
        void display()const;

        // Deallocation tye New key word.
        void deallocate();
    };
}


