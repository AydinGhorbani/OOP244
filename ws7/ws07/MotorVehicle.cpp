f#define _CRT_SECURE_NO_WARNINGS
#include "MotorVehicle.h"
#include <iomanip>
#include <cstring>

using namespace std;

namespace sdds {
    const char* MotorVehicle::getLicensePlate() const {
        return m_licensePlate;
    }

    int MotorVehicle::getYear() const {
        return m_year;
    }

    const char* MotorVehicle::getAddress() const {
        return m_address;
    }
    MotorVehicle::MotorVehicle(const char* licensePlate, int year)
        : m_year(year) {
        strncpy(m_licensePlate, licensePlate, 8);
        m_licensePlate[8] = '\0';
        strcpy(m_address, "Factory");
    }

    void MotorVehicle::moveTo(const char* address) {
        if (strcmp(m_address, address) != 0) {
            cout << "|" << setw(8) << right << m_licensePlate << "| "
                << setw(20) << right << m_address << " ---> "
                << setw(20) << left << address << "|" << endl;
            strcpy(m_address, address);
        }
    }

    std::ostream& MotorVehicle::write(std::ostream& os) const {
        return os << "| " << setw(6) << m_year << " | " << setw(8) << m_licensePlate << " | " << m_address;
    }

    std::istream& MotorVehicle::read(std::istream& in) {
        cout << "Built year: ";
        in >> m_year;
        cout << "License plate: ";
        in.ignore();
        in.getline(m_licensePlate, 9);
        cout << "Current location: ";
        in.getline(m_address, 64);
        return in;
    }

    std::ostream& operator<<(std::ostream& os, const MotorVehicle& vehicle) {
        return vehicle.write(os);
    }

    std::istream& operator>>(std::istream& is, MotorVehicle& vehicle) {
        return vehicle.read(is);
    }

} 
