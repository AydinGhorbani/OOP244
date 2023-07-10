
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
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
using namespace std;

namespace sdds {

const double Pie = 3.14159265;

void Canister::setToDefault() {
    m_contentName = nullptr;
    m_height = 13.0;
    m_diameter = 10.0;
    m_contentVolume = 0.0;
    m_usable = true;
}

double Canister::capacity()const {
    return Pie * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
}

double Canister::volume()const {
    return m_contentVolume;
}

void Canister::setName(const char* Cstr) {
    if (Cstr != nullptr && m_usable) {
        delete[] m_contentName;
        m_contentName = new char[strLen(Cstr) + 1];
        strCpy(m_contentName, Cstr);
    }

}

bool Canister::isEmpty()const {
    return m_contentVolume < 0.00001 ? true : false;
}

bool Canister::hasSameContent(const Canister& C)const {
    return !strCmp(m_contentName, C.m_contentName);
}

Canister::Canister() {
    m_contentName = nullptr;
    m_height = 13.0;
    m_diameter = 10.0;
    m_contentVolume = 0.0;
    m_usable = true;
}

Canister::Canister(const char* contentName) {
    m_contentName = nullptr;
    m_height = 13.0;
    m_diameter = 10.0;
    m_contentVolume = 0.0;
    m_usable = true;
    setName(contentName);
}


Canister::~Canister() {
    delete[] m_contentName;
}

void Canister::clear() {
    if (!m_usable) {
        delete[] m_contentName;
        m_contentName = nullptr;
        m_contentVolume = 0.0;
        m_usable = true;
    }
}



Canister::Canister(double height, double diameter,
    const char* contentName) {
    setToDefault();
    if (height >= 10.0 && height <= 40.0 && diameter >= 10.0 && diameter <= 30.0) {
        m_height = height;
        m_diameter = diameter;
        setName(contentName);
    }
    else
    {
        m_usable = false;
    }
}


Canister& Canister::setContent(const char* contentName) {
    if (contentName == nullptr) {
        m_usable = false;
    }
    else if (isEmpty()) {
        setName(contentName);
    }
    else if (!hasSameContent(contentName)) {
        m_usable = false;
    }
    return*this;
}

Canister& Canister::pour(double quantity) {
    if (m_usable && quantity > 0 && (quantity + m_contentVolume <= capacity())) {
        m_contentVolume += quantity;
    }
    else {
        m_usable = false;
        
    }
    return *this;
}

Canister& Canister::pour(Canister& C) {
    setContent(C.m_contentName);
    if (C.m_contentVolume > capacity() - volume()) {

        C.m_contentVolume -= capacity() - volume();
        m_contentVolume = capacity();
    }
    else {
        pour(C.m_contentVolume);
        C.m_contentVolume = 0.0;
    }
    return *this;
}

std::ostream& Canister::display() const {
    cout.setf(ios::fixed);
    cout.precision(1);
    cout.width(7);
    cout.setf(ios::right);
    cout << capacity() << "cc (";
    cout.width(2);
    cout << m_height << "x";
    cout.width(2);
    cout << m_diameter << ") Canister";
    if (!m_usable) {
        cout << " of Unusable content, discard!";
    }
    else if (m_contentName != nullptr) {
        cout << " of ";
        cout.width(7);
        cout << volume() << "cc   " << m_contentName;
    }
    cout.unsetf(ios::fixed);
    cout.precision(6);
    return cout;
}

}
