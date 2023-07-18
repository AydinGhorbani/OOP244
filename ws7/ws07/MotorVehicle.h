#ifndef MOTORVEHICLE_H
#define MOTORVEHICLE_H

#include <iostream>

namespace sdds {

    class MotorVehicle {
        char m_licensePlate[9];
        char m_address[64];
        int m_year;
    public:
        MotorVehicle(const char* licensePlate, int year);
        void moveTo(const char* address);
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& in);
    protected:
        const char* getLicensePlate() const;
        int getYear() const;
        const char* getAddress() const;
    };

    std::ostream& operator<<(std::ostream& os, const MotorVehicle& vehicle);
    std::istream& operator>>(std::istream& is, MotorVehicle& vehicle);

} // namespace sdds

#endif // MOTORVEHICLE_H
