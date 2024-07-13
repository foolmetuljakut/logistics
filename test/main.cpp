#include <gtest/gtest.h>

#include "../src/BasicLaneTraffic/Field.hpp"
#include "../src/BasicLaneTraffic/Map.hpp"
#include "../src/BasicLaneTraffic/Vehicle.hpp"

class BasicLaneTrafficTestFixture : public testing::Test {
protected:
    Field f, g;
    Vehicle v;

    BasicLaneTrafficTestFixture()
      : f{ 0 }
      , g{ 1 }
      , v{ 1 } {
        f.addNeighbour(g);
        f.addVehicle(v);
    }
};

TEST_F(BasicLaneTrafficTestFixture, fieldNeighbourhood) {
    ASSERT_TRUE(f.isNeighbour(g));
}

TEST_F(BasicLaneTrafficTestFixture, fieldVehicleTransfer) {

    ASSERT_TRUE(f.hasVehicle(v.getId()));
    ASSERT_FALSE(g.hasVehicle(v.getId()));

    f.transfer(g.getPosition());
    ASSERT_FALSE(f.hasVehicle(v.getId()));
    ASSERT_TRUE(g.hasVehicle(v.getId()));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}