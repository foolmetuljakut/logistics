#ifndef BasicLaneTrafficField
#define BasicLaneTrafficField

#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <iostream>
#include <string>

#include "Vehicle.hpp"

#include <exception>
#include <sstream>
class FieldException : public std::exception
{
public:
    std::string w;
    FieldException(std::initializer_list<std::string> l)
    {
        std::stringstream ss;
        for (auto &s : l)
            ss << s;
        w = ss.str();
    }
    const char *what() const noexcept override { return w.c_str(); }
};

class Field
{
    std::vector<Vehicle> vehicles;
    size_t x; // 1d position
    std::vector<Field*> neighbours;

public:
    Field() noexcept {}
    Field(const Field &f) : vehicles{f.vehicles}, x{f.x}, neighbours{f.neighbours}
    {
        // std::cout << "Field: copying " << x << std::endl;
    }
    Field(Field&& f) : vehicles{f.vehicles}, x{f.x}, neighbours{f.neighbours} {};
    Field(const size_t &position) noexcept : x{position} {}

    bool isOccupied() const { return vehicles.size() > 0; }
    void addVehicle(const Vehicle &v);
    void removeVehicle(const Vehicle &v) noexcept { vehicles.clear(); }
    bool hasVehicle(const size_t &id) noexcept;

    void setPosition(const size_t &p) noexcept { x = p; }
    size_t getPosition() const noexcept { return x; }

    bool isNeighbour(const Field &f) const noexcept;
    void addNeighbour(Field &f) noexcept; 
    void transfer(const size_t &target);

    friend bool operator==(const Field &lhs, const Field &rhs);
};

bool operator==(const Field &lhs, const Field &rhs);

#endif // BasicLaneTrafficField