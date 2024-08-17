#include "Application.hpp"

const char * Application::cfgKey_BasicLaneTraffic = "BasicLaneTraffic";
const char * Application::cfgKey_laneLength = "laneLength";

Application::Application() {
    loadConfig();
    init();
}

void Application::loadConfig() {
    libconfig::Config cfg;
    cfg.readFile("etc/.cfg");
    const libconfig::Setting& root = cfg.getRoot();

    int len = root[cfgKey_BasicLaneTraffic][cfgKey_laneLength];
    laneLength = static_cast<size_t>(len);
}

void Application::init() {
    map.createSingleLane(laneLength);
    map.addVehicle(0);
}

void Application::update() {
    map.update();
}

void Application::print() {
    for(size_t i = 0; i < map.size(); i++) {
        std::cout << (map.isOccupied(i) ? "▰" : "_");
    }
    std::cout << std::endl;
}