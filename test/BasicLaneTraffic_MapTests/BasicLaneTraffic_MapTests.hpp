
#include <gtest/gtest.h>

#include "../../src/BasicLaneTraffic/Field.hpp"
#include "../../src/BasicLaneTraffic/Map.hpp"
#include "../../src/BasicLaneTraffic/Vehicle.hpp"

class BasicLaneTraffic_MapTests : public testing::Test {
protected:
    size_t startPos = 0, nextPos = 1;
    const size_t laneLength = 5;
    Map map;
    size_t vehicleId = 0;

    BasicLaneTraffic_MapTests();
};