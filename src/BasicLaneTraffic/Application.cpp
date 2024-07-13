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
}