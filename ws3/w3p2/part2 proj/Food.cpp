/*
 ****************************************
 Full Name  : Aydin Ghorbani
 Student ID#: 124170226
 Email      : aghorbani8@myseneca.ca
 
 completion date : 4/june/23
 
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 ****************************************
 */
#include <iostream>
#include "cstring.h"
#include "Food.h"
#include <iomanip>

using namespace std;

namespace sdds
{

    void Food::setName(const char* name)
    {

        strnCpy(f_name, name, 30);
        f_name[30] = '\0';
    }

   //sets the variables to an safe state.
    void Food::setEmpty()
    {
        f_name[0] = '\0';
        f_cal = 0;
        f_time = -1;
    }


    void Food::set(const char* name, int calorie, int time)
    {
    // validation
        if (calorie < 0 || name == nullptr)
        {
            setEmpty();
        }

        else
        {
            setName(name);
            f_cal = calorie;
            f_time = time;
        }
    }

    // accessing to the private members of class Food
    int Food::calorie() const
    {
        return f_cal;
    }

// accessing to the private members of class Food
    int Food::time() const
    {
        return f_time;
    }

    // validation for display
    bool Food::isValid() const
    {

        if ((f_cal >= 0 && f_cal <= 3000) &&
            (f_name [0] != '\0') &&
            (f_time > 0 && f_time<= 4))
        {
            return true;
        }

        return false;
    }

    // display function to print the output with filling the nessecary spaces.
    void Food::display() const
    {

        if (isValid())
        {
            cout << "| ";
            cout << setw(30) << std::left << setfill('.');
            cout << f_name << " | ";
            cout << setfill(' ') << setw(4) << right;
            cout << f_cal << " | ";
            cout << left << setw(10);

    

            string time;

            
            if (f_time== 1) {
                 time = "Breakfast";
            } else {
                if (f_time == 2) {
                    time = "Lunch";
                } else {
                    if (f_time == 3) {
                        time = "Dinner";
                    } else {
                        if (f_time== 4) {
                            time = "Snack";
                        } else {
                            time = "Unknown";
                        }
                    }
                }
            }

            cout << time << " |" << endl;
        }

        else
        {
            cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
        }
    }
}
