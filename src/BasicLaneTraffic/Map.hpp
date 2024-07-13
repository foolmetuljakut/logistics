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
    std::vector<Field> map;
    std::random_device rd;
    std::mt19937 g;
public:
    Map() : g(rd()) {}
    void createSingleLane();

    void update();
};

#endif // BasicLaneTrafficMap