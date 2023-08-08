/*
 ****************************************
 Full Name  : Aydin Ghorbani
 Student ID#: 124170226
 Email      : aghorbani8@myseneca.ca
 
 
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 ****************************************
 */
#pragma once

#include <iostream>
#include "Collection.h"
#include "Car.h"
#include "Student.h"
#include "Employee.h"

using namespace std;
namespace sdds{

// adding template specifications in xcode is not by just typing ///
// i looked for it online but there is nothing
    template <typename T1, typename T2>
    bool search(Collection<T1>& collection, const T1* array, int size,T2 key) {
        int i = 0;
        bool result = false;
        for (i = 0; i < size; i++){
            if(array[i] == key){
                collection.add(array[i]);
                result = true;
            }
        }
        return result;
    }

// adding template specifications in xcode is not by just typing ///
// i looked for it online but there is nothing
template <typename T>

    void listArrayElements(const char* Title, const T* array, int size) {
        cout << Title <<endl;
        int i{};
        for (i = 0; i < size; i++) {
            cout << i + 1 << ": " << array[i] << endl;
        }
    }
}


