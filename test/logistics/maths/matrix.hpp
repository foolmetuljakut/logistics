#pragma once

// source includes
#include "../../../src/logistics/maths/matrix.hpp"

// test includes
#include "../../std.hpp"

namespace logistics::maths {

    TEST(MatrixTests, DefinitionTest) {
        matrix m(3,3);

        ASSERT_EQ(m.get_cols(), 3);
        ASSERT_EQ(m.get_rows(), 3);
    }

};