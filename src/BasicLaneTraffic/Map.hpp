#ifndef BasicLaneTrafficMap
#define BasicLaneTrafficMap

#include <vector>
#include <map>
#include <utility>
#include <iostream>
#include <random>

#include "Vehicle.hpp"
#include "Field.hpp"

#include <exception>
#include <sstream>
class MapException : public std::exception {
public:
    std::string w;
    MapException(std::initializer_list<std::string> l) {
        std::stringstream ss;
        for(auto &s : l)
            ss << s;
        w = ss.str();
    }
    const char * what() const noexcept override { return w.c_str(); }
};

class Map
{
    std::random_device rd;
    std::mt19937 g;
    std::vector<Field> map;
public:
    Map() : g(rd()) {}
    void createSingleLane(size_t length);
    void addVehicle(size_t newId);
    bool isOccupied(size_t position);

    void update();
};

#endif // BasicLaneTrafficMap