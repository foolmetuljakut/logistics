
#include "BasicLaneTraffic_BaseTests.hpp"

BasicLaneTraffic_BaseTests::BasicLaneTraffic_BaseTests()
    : f{ 0 }, g{ 1 }, v{ 1 } {
    f.addNeighbour(g);
    f.addVehicle(v);
}

TEST_F(BasicLaneTraffic_BaseTests, fieldNeighbourhood) {
    ASSERT_TRUE(f.isNeighbour(g));
}

TEST_F(BasicLaneTraffic_BaseTests, fieldVehicleTransfer) {

    ASSERT_TRUE(f.isOccupied());
    ASSERT_TRUE(f.hasVehicle(v.getId()));
    ASSERT_FALSE(g.isOccupied());
    ASSERT_FALSE(g.hasVehicle(v.getId()));

    f.transfer(g.getPosition());

    ASSERT_FALSE(f.isOccupied());
    ASSERT_FALSE(f.hasVehicle(v.getId()));
    ASSERT_TRUE(g.isOccupied());
    ASSERT_TRUE(g.hasVehicle(v.getId()));
}
