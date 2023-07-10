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
#include "CalorieList.h"

using namespace std;

namespace sdds
{
    //sets the pointer to an safe state.
    void CalorieList::setEmpty()
    {
        f_list = nullptr;
    }

    // validating the pointer to use in the display function
    bool CalorieList::isValid() const
    {
        
        if (f_list == nullptr)
        {
            return false;
        }

        for (int i = 0; i < f_num; i++)
        {
            if (!f_list[i].isValid())
            {
                return false;
            }
        }

        return true;
    }

    // calculates the toatl calories for the foods
    int CalorieList::totalCal() const
    {
        int calSum = 0;

        for (int i = 0; i < f_num; i++)
        {

            if (f_list[i].isValid())
            {
                calSum += f_list[i].calorie();
            }
        }

        return calSum;
    }

    // header
    void CalorieList::title() const
{
    string header;
    if (isValid()) {
        header = "|  Daily Calorie Consumption                         |\n";
    } else {
        header = "| Invalid Calorie Consumption list                   |\n";
    }
    
    cout << "+----------------------------------------------------+" << '\n'
    << header
    << "+--------------------------------+------+------------+" << '\n'
    << "| Food name                      | Cals | When       |" << '\n'
    << "+--------------------------------+------+------------+" << endl;
}
    // Display The Footer
    void CalorieList::footer() const
    {

        cout << "+--------------------------------+------+------------+" << endl;

        // If Food Is Valid
        if (isValid())
        {
            cout.setf(ios::right);
            cout << "|    Total Calories for today:  ";
            cout.width(7);
            cout << totalCal() << " | ";
            cout.width(12);
            cout << " |" << endl;
            cout.unsetf(ios::right);
        }
        // Is Not Valid
        else
        {
            cout << "|    Invalid Calorie Consumption list                |" << endl;
        }

        cout << "+----------------------------------------------------+" << endl;
    }

    //dynamic allocation for the number of foods.
    void CalorieList::init(int size)
    {

        if (size <= 0)
        {
            setEmpty();
        }

        else
        {
            f_num = size;
            f_add = 0;

    
            f_list = new Food[f_num];

            for (int i = 0; i < f_num; i++)
            {
                f_list[i].setEmpty();
            }
        }
    }


    bool CalorieList::add(const char* item_name, int calories, int when)
    {
        if (f_add < f_num)
        {

            int index = f_add;


            f_list[index].set(item_name, calories, when);
            f_add++;

            return true;
        }

        return false;
    }

   // simply a display function that gathers all the dispay functions
    void CalorieList::display()const
    {
        title();

        for (int i = 0; i < f_num; i++)
        {
            f_list[i].display();
        }

        footer();
    }
    // free memory
    void CalorieList::deallocate() {
        
        delete [] f_list;
        f_list = nullptr;
    }
}

