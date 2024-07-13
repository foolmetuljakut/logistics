
#include "BasicLaneTraffic_MapTests.hpp"

BasicLaneTraffic_MapTests::BasicLaneTraffic_MapTests() {
    map.createSingleLane(laneLength);
    map.addVehicle(vehicleId);
}

TEST_F(BasicLaneTraffic_MapTests, stochasticUpdateCheck) {
    ASSERT_TRUE(map.isOccupied(startPos));
    ASSERT_FALSE(map.isOccupied(nextPos));

    map.update();

    ASSERT_FALSE(map.isOccupied(startPos));
    ASSERT_TRUE(map.isOccupied(nextPos));
}
