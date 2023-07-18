#define _CRT_SECURE_NO_WARNINGS
#include "Truck.h"
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
namespace sdds {

    Truck::Truck(const char* licensePlate, int year, double capacity, const char* address)
        : MotorVehicle(licensePlate, year), m_capacity(capacity), m_currentCargo(0.0) {
        moveTo(address);
    }

    bool Truck::addCargo(double cargo) {
        if (m_currentCargo != m_capacity) {
            m_currentCargo += cargo;
            if (m_currentCargo > m_capacity)
                m_currentCargo = m_capacity;

            return true;
        }
        else
            return false;
    }

    bool Truck::unloadCargo() {
        if (m_currentCargo > 0) {
            m_currentCargo = 0.0;
            return true;
        }
        return false;
    }

    std::ostream& Truck::write(std::ostream& os)const {
        os << "| " << getYear() << " | " << getLicensePlate() << " | " << getAddress()
            << " | " << m_currentCargo << "/" << m_capacity;
        return os;
    }

    std::istream& Truck::read(std::istream& in) {
        MotorVehicle::read(in);
        cout << "Capacity: ";
        in >> m_capacity;
        cout << "Cargo: ";
        in >> m_currentCargo;
        return in;
    }

    std::ostream& operator<<(std::ostream& os, const Truck& truck) {
        return truck.write(os);
    }

    std::istream& operator>>(std::istream& is, Truck& truck) {
        return truck.read(is);
    }

} // namespace sdds
