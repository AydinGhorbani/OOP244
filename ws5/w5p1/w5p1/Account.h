
/*
 ****************************************
 Full Name  : Aydin Ghorbani
 Student ID#: 124170226
 Email      : aghorbani8@myseneca.ca
 
 completion date (updated) : 9/june/23
 
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 ****************************************
 */
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
       operator bool() const;
       operator int() const;
       operator double() const;
       bool operator~() const;
       Account& operator=(const int m_number);
       Account& operator=(Account& other);
       Account& operator+=(const double add);
       Account& operator-=(const double subtract);
       Account& operator <<(Account& account);
       Account& operator >>(Account& account);
       bool validation() const;
   };
   
double operator+(const Account&, const Account&);
double operator+=(double& left, const Account& right);
}
#endif // SDDS_ACCOUNT_H_
