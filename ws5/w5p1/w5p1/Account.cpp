
/*
 ****************************************
 Full Name  : Aydin Ghorbani
 Student ID#: 124170226
 Email      : aghorbani8@myseneca.ca
 
 completion date (updated) : 9/june/23
 
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 ****************************************
 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
void Account::setEmpty() {
    m_number = -1;
    m_balance = 0.0;
}
// New account
Account::Account() {
    m_number = 0;
    m_balance = 0.0;
}
Account::Account(int number, double balance ) {
    setEmpty();
    if (number >= 10000 && number <= 99999
        && balance > 0) {
        m_number = number;
        m_balance = balance;
    }
}
std::ostream& Account::display() const{
    if (*this) {
        cout << " ";
        cout << m_number;
        cout << " | ";
        cout.width(12);
        cout.precision(2);
        cout.setf(ios::right);
        cout.setf(ios::fixed);
        cout << m_balance;
        cout.unsetf(ios::right);
        cout << " ";
    }
    else if(~*this) {
        cout << "  NEW  |         0.00 ";
    }
    else {
        cout << "  BAD  |    ACCOUNT   ";
    }
    return cout;
}

Account::operator bool() const {
    if (m_number > 10000 && m_number < 99999
        && m_balance >= 0)
    {
        return true;
    }
    else return false;
    
    
}
Account::operator int() const{
    return m_number;
}

Account::operator double() const{
    return m_balance;
}

bool Account::operator ~() const {
    if (m_number == 0) {
        return true;
    }
    else return false;
    
}

    Account& Account::operator =(int number) {
        if (m_number == 0) {
            if (number > 9999 && number < 100000) {
                m_number = number;
            }
            else {
                m_number = -1;
                m_balance = 0;
            }
        }
        return *this;
    }
    

Account& Account::operator=(Account& other){
    if (other.validation() && m_number == 0) {
        m_balance = other.m_balance;
        m_number = other.m_number;
        other.m_balance = 0.0;
        other.m_number = 0;
        return *this;
    }
    return *this;
    
    
   }

Account& Account::operator+=(const double add){
    if (*this && add > 0)
    {
        m_balance += add;
    }
    return *this;
    
}

Account& Account::operator-=(const double subtract){
    
    if (*this && subtract > 0 && m_balance > subtract)
    {
        m_balance -= subtract;
    }
    return *this;
    
}


Account& Account::operator <<(Account& acc) {
    if (this != &acc) {
        m_balance += acc.m_balance;
        acc.m_balance = 0;
    }
    return *this;
}


Account& Account::operator >>(Account& acc) {
    if (this != &acc) {
        acc.m_balance += m_balance;
        m_balance = 0;
    }
    return *this;
}

// used for overloading operator += and +
bool Account::validation() const {
    if ((m_number < 100000 && m_number > 9999)
        && m_balance >= 0)
    {
        return true;
    }
    return false;
}


double operator+(const Account& left, const Account& right) {
    if (left.validation() && right.validation())
    {
        return double(left) + double(right);
    }
    else
    {
        return 0.0;
    }
}


double operator+=(double& left, const Account& right) {
    if (right.validation()) {
        left += double(right);
    }
    return left;
}
}
