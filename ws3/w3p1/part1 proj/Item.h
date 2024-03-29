/*
 ****************************************
 Full Name  : aydi ghorbani
 Student ID#: 124179226
 Email      : aghorbani8@myseneca.ca
 
 completion date : 23/06/01
 
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 ****************************************
 */
#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_
namespace sdds {
   class Item {
      char m_itemName[21];
      double m_price;
      bool m_taxed;
      void setName(const char* name);
   public:
      void setEmpty();
      void set(const char* name, double price, bool taxed);
      void display()const;
      bool isValid()const;
      double price()const;
      double tax()const;
   };
}

#endif // !SDDS_SUBJECT_H
