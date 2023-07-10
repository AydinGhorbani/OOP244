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

namespace sdds
{
    class Food
    {

        char f_name[30 + 1];
        int f_cal;
        int f_time;

   
        void setName(const char* name);

    public:

        // Sets the food object to an empty state( Safe state)
        void setEmpty();

        // Sets the values of the food item
        void set(const char* name, int calorie, int time);

        // Displays the information of the food item
        void display() const;

        // Checks if the food object is valid (not in an empty state)
        bool isValid() const;
        
        // Returns the number of calories in the food item
        int calorie() const;

        // Returns the consumption code indicating the time of consumption
        int time() const;
    };
}

