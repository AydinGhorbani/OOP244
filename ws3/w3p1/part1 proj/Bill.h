/*
 ****************************************
 Full Name  : aydi ghorbani
 Student ID#: 124170226
 Email      : aghorbani8@myseneca.ca
 
 completion date : 23/06/01
 
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 ****************************************
 */
#ifndef SDDS_BILL_H_
#define SDDS_BILL_H_
#include "Item.h"

namespace sdds {
class Bill {
    
    char m_title[37];
    Item* m_items;
    int m_noOfItems;
    int m_itemsAdded;
    
    //calculates the total tax of the items.
    double totalTax()const;
    
    //calculates the subtotal of the items.
    double totalPrice()const;
    
    //displays the nessecary titles for the bill including the format in the instruction.
    void Title()const;
    
    //displays the nessecary footers for the bill including the format in the instruction.
    void footer()const;
    //sets the bill to an empty state
    void setEmpty();
    // validats the
    bool isValid()const;
    
public:
    //Initializes the Bill object with the provided title //and number of items.
    //If the title is null or the number of items is less //than or equal to zero,
    //the Bill object is set to an empty state.
    void init(const char* title, int noOfItems);
    
    /* Adds an item to the Bill object with the provided item name, price, and tax status.
     If there is space in the bill to add the item, it is added and true is returned.
     If the bill is already full and no more items can be added, false is returned.*/
    bool add(const char* item_name, double price, bool taxed);
    
    void display()const;
    
    void deallocate();
};
}
#endif // !SDDS_TRANSCRIPT_H
