#pragma once

#include "../../std.hpp"

namespace logistics::maths {
    class matrix {
        std::vector<float> data;
        size_t rows, cols;

    public:
        matrix(size_t rows, size_t cols);

        // caution: solving destroys both rhs & lhs matrices with solution parameters
        matrix solve(matrix& other);

        size_t get_rows() const;
        size_t get_cols() const;
    };
};