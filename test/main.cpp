#include <gtest/gtest.h>

#include "../src/BasicLaneTraffic/Field.hpp"
#include "../src/BasicLaneTraffic/Map.hpp"
#include "../src/BasicLaneTraffic/Vehicle.hpp"

// TODO
// create folders: FieldVehicleTests, MapTests, ApplicationTests
// move BasicLaneTraffic_BaseTests, fieldNeighbourhood, fieldVehicleTransfer -> FieldVehicleTests
// move BasicLaneTraffic_MapTests, laneCreation -> MapTests
// write application tests (config loading, passing of parameters)

#include "BasicLaneTraffic_BaseTests/BasicLaneTraffic_BaseTests.hpp"

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}