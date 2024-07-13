#ifndef BasicLaneTrafficVehicle
#define BasicLaneTrafficVehicle

#include <vector>
#include <map>
#include <utility>
#include <iostream>

#include <exception>
#include <sstream>
class VehicleException : public std::exception {
public:
    std::string w;
    VehicleException(std::initializer_list<std::string> l) {
        std::stringstream ss;
        for(auto &s : l)
            ss << s;
        w = ss.str();
    }
    const char * what() const noexcept override { return w.c_str(); }
};

class Vehicle
{
    size_t id;
public:
    Vehicle() {}
    Vehicle(const size_t& id) : id{id} {}
    Vehicle(const Vehicle& v) : id{v.id} 
    {
        std::cout << "Vehicle: copying " << id << std::endl;
    }

    size_t getId() const { return id; }
};

#endif // BasicLaneTrafficVehicle