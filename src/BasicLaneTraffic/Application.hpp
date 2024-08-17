#pragma once

#include "Field.hpp"
#include "Map.hpp"
#include "Vehicle.hpp"

#include <libconfig.h++>

class Application {

static const char *cfgKey_BasicLaneTraffic;
static const char *cfgKey_laneLength;

    size_t laneLength;
    Map map;

    void loadConfig();
    void init();
public:
    Application();
    void update();
    void print();
};