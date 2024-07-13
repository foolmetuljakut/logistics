
#include <gtest/gtest.h>

#include "../../src/BasicLaneTraffic/Field.hpp"
#include "../../src/BasicLaneTraffic/Map.hpp"
#include "../../src/BasicLaneTraffic/Vehicle.hpp"

class BasicLaneTraffic_BaseTests : public testing::Test {
protected:
    Field f, g;
    Vehicle v;

    BasicLaneTraffic_BaseTests();
};