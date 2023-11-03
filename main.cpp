#include <iostream>
#include <string>
#include <sstream>

#include "BasicLaneTraffic/Map.hpp"

std::string info(std::string msg) {
    std::stringstream s;
    s << "\033[34m" << msg << "\033[0m";
    return s.str();
}

std::string decide(std::string msg, bool check) {
    std::stringstream s;
    s << msg << ": "
      << (check ? "\033[32mtrue\033[0m" : "\033[31mfalse\033[0m");
    return s.str();
}

void LOGISTICS1_ut02() {
    std::cout << std::boolalpha;

    std::cout << info("LOGISTICS1_ut02\n> msg") << "\n";

    Map map;
    map.createSingleLane();
    
    for(size_t i = 0; i < 15; i++)
        map.update();
}

void LOGISTICS1_ut01() {
    std::cout << std::boolalpha;

    std::cout << info("LOGISTICS1_ut01\n> testing creation of fields and vehicle assignment") << "\n";

    Field f{0}, g{1};
    f.addNeighbour(g);
    std::cout << decide("g is a neighbour of f", f.isNeighbour(g)) << "\n";
    
    Vehicle v{1};
    f.addVehicle(v);
    std::cout << decide("v is a vehicle on f", f.hasVehicle(1)) << "\n";
    std::cout << decide("v is not a vehicle on g", !g.hasVehicle(1)) << "\n";
    
    f.transfer(1);
    std::cout << decide("v is not a vehicle on f", !f.hasVehicle(1)) << "\n";
    std::cout << decide("v is a vehicle on g", g.hasVehicle(1)) << std::endl;
}

#ifdef MAIN
int main(int argc, char **argv) {
    LOGISTICS1_ut02();
    return 0;
}
#endif

#ifdef LOGISTICS1
int main(int argc, char **argv) {
    LOGISTICS1_ut01();
    LOGISTICS1_ut02();
    return 0;
}
#endif