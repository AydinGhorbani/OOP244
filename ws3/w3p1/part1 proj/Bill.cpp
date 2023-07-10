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
#include "Bill.h"
#include "Item.h"
#include <iomanip>
using namespace std;

namespace sdds {

void Bill::setEmpty(){
    strCpy(m_title,"");
    m_items = nullptr;
}

bool Bill::isValid()const{
    int i;
    if (!strCmp(m_title,"" ) || m_items == nullptr) {
        return false;
    }
    
    for ( i = 0; i < m_noOfItems; i++) {
        if (!m_items[i].isValid()) {
            return false;
        }
    }
    
    return true;
}



double Bill::totalTax()const{
    double sum = 0;
    int i;
    
    for( i = 0; i < m_itemsAdded; i++){
        sum += m_items[i].tax();
    }
    return sum;
    
}

double Bill::totalPrice()const{
    double sum = 0;
    int i;
    
    for( i = 0 ; i < m_itemsAdded ; i ++){
        sum += m_items[i].price();
    }
    return sum;
}

void Bill::Title()const{
    
    cout << "+--------------------------------------+" << endl;
    
    if (isValid()) {
        cout << "| " << left << setfill(' ')<<setw(36) << m_title << " |" << endl;
    }
    else {
        cout << "| Invalid Bill                         |" << endl;
    }
    cout << "+----------------------+---------+-----+" << endl;
    cout << "| Item Name            | Price   + Tax |" << endl;
    cout << "+----------------------+---------+-----+" << endl;
}

void Bill::footer()const{
    
    cout << "+----------------------+---------+-----+" << endl;
    if (isValid()) {
        cout << "|                Total Tax: " << right << setw(10) << fixed << setprecision(2) << totalTax() << " |" << endl;
        cout << "|              Total Price: " << right << setw(10) << fixed << setprecision(2) << totalPrice() << " |" << endl;
        cout << "|          Total After Tax: " << right << setw(10) << fixed << setprecision(2) << totalTax() + totalPrice() << " |" << endl;
    }
    else {
        cout << "| Invalid Bill                         |" << endl;
    }
    cout << "+--------------------------------------+" << endl;
}


void Bill::init(const char* title, int noOfItems){
    
    if (title == nullptr || noOfItems <= 0)
    {
        setEmpty();
    }
    else
    {
        //inisialize noOfItems
        m_noOfItems = noOfItems;
        m_itemsAdded = 0;
        //inisialize m_title
        strnCpy(m_title, title, 36);
        m_title[36] = '\0';
        
        // Allocate dynamic memory for m_items array
        m_items = new Item[m_noOfItems];
        
        // Set each item in m_items array to an empty state
        for (int i = 0; i < m_noOfItems; i++) {
            m_items[i].setEmpty();
        }
    }
}

bool Bill::add(const char* item_name, double price, bool taxed){
    
    if (m_itemsAdded < m_noOfItems) {
        m_items[m_itemsAdded].set(item_name, price, taxed);
        m_itemsAdded++;
        return true;
    }
    else {
        return false;
    }
}



void Bill::display() const {
    Title();
    for (int i = 0; i < m_noOfItems; i++) {
        m_items[i].display();
    }
    footer();
}


void Bill::deallocate() {
    delete[] m_items;
    m_items = nullptr;
}

}






