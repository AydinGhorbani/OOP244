/*
 ****************************************
 Full Name  : aydi ghorbani
 Student ID#: 124170226
 Email      : aghorbani8@myseneca.ca
 
 completion date : 23/06/01
 
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 ****************************************
 */
#include <iostream>
#include "cstring.h"
#include "Item.h"
#include <iomanip>
#include <string.h>
using namespace std;
namespace sdds {

Item item;
void Item::setName(const char* name) {
    // Copy the characters from name to itemName
    int i;
    for (i = 0; i < 20 && name[i] != '\0'; i++) {
        m_itemName[i] = name[i];
    }
    
    // Add null terminator at the end of itemName
    m_itemName[i] = '\0';
}



void Item::setEmpty(){
    
    m_price = 0.0;
    strcpy(m_itemName,"");
}



void Item::set(const char* name, double price, bool taxed){
    
    
    if(price < 0 || name == nullptr)
    {
        setEmpty();
    }
    else
    {
        setName(name);
        m_price = price;
        m_taxed = taxed;
    }
    
}



double Item::price()const{
    
    return m_price;
}



double Item::tax()const{
    
    const double taxRate = 0.13;
    if (m_taxed){
        
        return (taxRate * m_price) ;
    }
    else
    {
        return 0;
    }
}

bool Item::isValid() const {
    if(m_price > 0 && strCmp(m_itemName,"") ){
        return true;
    }
    return false;
}


void Item::display()const{
    
    if (isValid())
    {
        cout << "| " << left << setw(20) << setfill('.') << m_itemName << setfill(' ')
        << " | " << right << fixed << setprecision(2) << setw(7) << m_price
        << " | " << (m_taxed ? "Yes" : "No ") << " |" << endl;
    }
    else {
        cout << "| " << setw(23) << setfill('x')
        << " | " << setw(5) << "xxxxxxx"
        << " | " << "xxx" << " |" << endl;
    }
}
}
