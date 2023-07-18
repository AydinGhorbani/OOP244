#ifndef TRUCK_H
#define TRUCK_H

#include "MotorVehicle.h"

namespace sdds {

    class Truck : public MotorVehicle {
        double m_capacity;
        double m_currentCargo;

    public:
        Truck(const char* licensePlate, int year, double capacity, const char* address);
        bool addCargo(double cargo);
        bool unloadCargo();
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& in);
    };

    std::ostream& operator<<(std::ostream& os, const Truck& truck);
    std::istream& operator>>(std::istream& is, Truck& truck);

} // namespace sdds

#endif // TRUCK_H
