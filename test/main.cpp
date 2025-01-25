#include <gtest/gtest.h>
#include <gmock/gmock.h>

// source includes
#include "../src/std.hpp"

// test includes
#include "std.hpp"
#include "logistics/maths.hpp"

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}