#include "matrix.hpp"

namespace logistics::maths {

    matrix::matrix(size_t rows, size_t cols)
        : data(rows*cols), rows{rows}, cols{cols} {

    }

    matrix matrix::solve(matrix& other) {
        if (rows != cols) {
            throw "for multiplication lhs.rows should be equal to rhs.cols";
        }

        //documentation dgesv: https://software.intel.com/en-us/node/520973
        /*lapack_int LAPACKE_dgesv (
        int matrix_layout ,
        lapack_int n ,
        lapack_int nrhs ,
        double * a ,
        lapack_int lda ,
        lapack_int * ipiv ,
        double * b ,
        lapack_int ldb );*/
        auto layout = LAPACK_ROW_MAJOR;
        auto n = this->rows; // is sqare
        auto nrhs = 1;
        auto lda = this->rows; /*In general leading dimension is equal to the number of elements in major dimension.*/
        auto ipiv = new int[this->rows];

        auto ldb = nrhs; /*In general leading dimension is equal to the number of elements in major dimension.
                    major dimension*/

        int result = LAPACKE_sgesv(
            layout,
            n,
            nrhs,
            this->data.data(),
            lda,
            ipiv,
            other.data.data(),
            ldb); //saves result into vector of inhomogeneity  

        delete[] ipiv;

        if (result < 0)
            throw "mt_Matrix::solve(): parameter " + std::to_string(result) + " was invalid";
        else if (result > 0)
            throw "mt_Matrix::solve(): U(" + std::to_string(result) + 
                "," + std::to_string(result) + ") Matrix (from LU decomp) was singular. process stopped";

        return other;
    }

    size_t matrix::get_rows() const {
        return rows;
    }

    size_t matrix::get_cols() const {
        return cols;
    }

}; // namespace logistics::maths