/* ----------------------------------------------------------------------------
 * matrix.hpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

/** \file matrix.hpp Templated matrix class
 *
 * Matrix
 * ======
 *
 * This is a very general matrix class that can then be inherited by
 * vectors and other similar data structures to minimize code
 * density.
 */

#ifndef YAGE_MATH_MATRIX_HPP
#define YAGE_MATH_MATRIX_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace yage {

template <int Rows, int Cols, class Type>
class Matrix;

/** \internal Namespace for internal details.
 *
 * Detail Namespace
 * ================
 *
 * This is the namespace used for implementation detail.
 */
namespace detail {

/** \internal Internal Row class used by the Matrix class to return the
 * internal data structure of the Matrix.
 *
 * Row
 * ===
 *
 * Internal Row class to return a value in the row of the matrix.
 */
template <int Rows, int Cols, class Type>
class Row {
private:
    Matrix<Rows, Cols, Type>* parent_;
    int index_;

public:
    Row<Rows, Cols, Type>(Matrix<Rows, Cols, Type>* parent, int index)
        : parent_(parent), index_(index) {}

    Type& operator[](int col) {
        // the index is the y-position of the element in the matrix
        return parent_->data_[index_ * Cols + col];
    }

    const Type& operator[](int col) const {
        return parent_->data_[index_ * Cols + col];
    }
};

}  // detail

/** Base Matrix class used by other similar classes.
 *
 * Matrix class
 * ============
 *
 * This is the base matrix class that can be used by all the other matrix
 * like data structures.
 */
template <int Rows = 4, int Cols = 4, class Type = double>
class Matrix {
    // friended with the row class so that it can access protected member data
    friend class detail::Row<Rows, Cols, Type>;

protected:
    /// Vector containing the data of the matrix
    std::vector<Type> data_;

public:
    /// Initializes the size of the data_ vector
    Matrix<Rows, Cols, Type>() : data_(Rows * Cols) {}
    Matrix<Rows, Cols, Type>(const std::vector<Type>& data) : data_(data) {}

    /// Returns the row size of the Matrix
    int rowSize() const { return Rows; }

    /// Returns the column size of the Matrixxs
    int colSize() const { return Cols; }

    /** Return the row specified row as a Matrix with only one row
   *
   * \param[in] row Row number to be returned
   *
   * Returns the row that is specified by the row variables.
   */
    Matrix<1, Cols, Type> getRow(int row) const {
        Matrix<1, Cols, Type> rowMatrix;
        for (int i = 0; i < Cols; ++i) {
            rowMatrix[0][i] = data_[row][i];
        }
        return rowMatrix;
    }

    // returns the column in a column matrix
    Matrix<Rows, 1, Type> getCol(int col) const {
        Matrix<Rows, 1, Type> colMatrix;
        for (int i = 0; i < Rows; ++i) {
            colMatrix[i][0] = data_[i][col];
        }
        return colMatrix;
    }

    // iterator support for begin
    typename std::vector<Type>::iterator begin() { return data_.begin(); }

    // iterator support for end
    typename std::vector<Type>::iterator end() { return data_.end(); }

    // prints out the matrix, but can also be implemented by other classes to
    // print data differently
    virtual std::string toString() const {
        std::stringstream ss;
        ss << '[';
        for (int i = 0; i < Rows - 1; ++i) {
            ss << '[';
            for (int j = 0; j < Cols - 1; ++j) {
                ss << data_[i * Cols + j] << ' ';
            }
            ss << data_[(Rows - 1) * Cols + Cols - 1] << "],";
        }
        ss << '[';
        for (int j = 0; j < Cols - 1; ++j) {
            ss << data_[(Rows - 1) * Cols + j] << ' ';
        }
        ss << data_[(Rows - 1) * Cols + Cols - 1] << "]]";
        return ss.str();
    }

    detail::Row<Rows, Cols, Type> operator[](int row) {
        return detail::Row<Rows, Cols, Type>(this, row);
    }

    detail::Row<Rows, Cols, Type> operator[](int row) const {
        // TODO got to fix this
        return detail::Row<Rows, Cols, Type>((Matrix<Rows, Cols, Type>*)this,
                                             row);
    }

    Matrix<Rows, Cols, Type>& operator+=(const Matrix<Rows, Cols, Type>& rhs) {
        std::vector<Type> out;
        out.reserve(data_.size());
        std::transform(data_.begin(), data_.end(), rhs.data_.begin(),
                       std::back_inserter(out),
                       [](Type a, Type b) { return a + b; });
        data_ = std::move(out);
        return *this;
    }

    Matrix<Rows, Cols, Type>& operator-=(const Matrix<Rows, Cols, Type>& rhs) {
        std::vector<Type> out;
        out.reserve(data_.size());
        std::transform(data_.begin(), data_.end(), rhs.begin(),
                       std::back_inserter(out),
                       [](Type a, Type b) { return a - b; });
        data_ = std::move(out);
        return *this;
    }
};

template <int M, int N, class T>
Matrix<M, N, T> operator+(Matrix<M, N, T> lhs, const Matrix<M, N, T>& rhs) {
    lhs += rhs;
    return lhs;
}

template <int M, int N, class T>
Matrix<M, N, T> operator-(Matrix<M, N, T> lhs, const Matrix<M, N, T>& rhs) {
    lhs -= rhs;
    return lhs;
}

template <int M, int N, class T>
Matrix<M, N, T> operator+(Matrix<M, N, T> lhs, const T& rhs) {
    for (auto& data : lhs) {
        data += rhs;
    }
    return lhs;
}

template <int M, int N, class T>
Matrix<M, N, T> operator+(const T& lhs, Matrix<M, N, T> rhs) {
    for (auto& data : rhs) {
        data += lhs;
    }
    return rhs;
}

template <int M, int N, class T>
Matrix<M, N, T> operator-(Matrix<M, N, T> lhs, const T& rhs) {
    for (auto& data : lhs) {
        data -= rhs;
    }
    return lhs;
}

template <int M, int N, class T>
Matrix<M, N, T> operator-(const T& lhs, Matrix<M, N, T> rhs) {
    for (auto& data : rhs) {
        data = lhs - data;
    }
    return rhs;
}

template <int M, int N, class T>
Matrix<M, N, T> operator*(Matrix<M, N, T> lhs, const T& rhs) {
    for (auto& data : lhs) {
        data *= rhs;
    }
    return lhs;
}

template <int M, int N, class T>
Matrix<M, N, T> operator*(const T& lhs, Matrix<M, N, T> rhs) {
    for (auto& data : rhs) {
        data *= lhs;
    }
    return rhs;
}

template <int M, int N, class T>
Matrix<M, N, T> operator/(Matrix<M, N, T> lhs, const T& rhs) {
    for (auto& data : lhs) {
        data /= rhs;
    }
    return lhs;
}

template <int M, int N, class T>
bool operator==(const Matrix<M, N, T>& lhs, const Matrix<M, N, T>& rhs) {
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            if (lhs[i][j] != rhs[i][j]) return false;
    return true;
}

template <int M, int N, class T>
std::ostream& operator<<(std::ostream& os, const Matrix<M, N, T>& mat) {
    return os << mat.toString();
}

template <int Rows = 2, class Type = double>
class Vector : public Matrix<Rows, 1, Type> {
public:
    Vector<Rows, Type>() : Matrix<Rows, 1, Type>() {}
    Vector<Rows, Type>(const Matrix<Rows, 1, Type>& other)
        : Matrix<Rows, 1, Type>(other) {}
    Vector<Rows, Type>(const std::vector<Type>& data)
        : Matrix<Rows, 1, Type>(data) {}

    Type& operator[](int col) { return this->data_[col]; }

    const Type& operator[](int col) const { return this->data_[col]; }

    virtual std::string toString() const {
        std::stringstream ss;
        ss << "[";
        for (std::size_t i = 0; i < this->data_.size() - 1; ++i) {
            ss << this->data_[i] << " ";
        }
        ss << this->data_[this->data_.size() - 1] << "]";
        return ss.str();
    }
};

/** 2D Vector class.
 *
 * Two dimensional vector class.
 */
template <class Type = double>
class Vector2 : public Vector<2, Type> {
public:
    Vector2<Type>() : Vector<2, Type>() {}
    Vector2<Type>(const std::vector<Type>& data) : Vector<2, Type>(data) {}

    Vector2<Type>(Type x, Type y) {
        this->data_[0] = x;
        this->data_[1] = y;
    }

    Vector2<Type>(const Matrix<2, 1, Type>& other) : Vector<2, Type>(other) {}

    Type& x() { return this->data_[0]; }

    const Type& x() const { return this->data_[0]; }

    Type& y() { return this->data_[1]; }

    const Type& y() const { return this->data_[1]; }
};

/// Definition of a 2D vector.
typedef Vector2<double> Vector2d;

/** Namespace containing functions that operate on matrices. */
namespace matrix {

/** Transposes a matrix and returns the result
*
* \param[in] m input matrix.
*/
template <int M, int N, class T>
Matrix<N, M, T> transpose(const Matrix<M, N, T>& m) {
    Matrix<N, M, T> trans;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            trans[j][i] = m[i][j];
        }
    }
    return trans;
}

/** Returns the dot product between two vectors
*
* \param[in] m1,m2 Input matrices.
*/
template <int R, class T>
T dot(const Matrix<R, 1, T>& m1, const Matrix<R, 1, T>& m2) {
    T sum = 0;
    for (int i = 0; i < R; ++i) {
        sum += m1[i][0] * m2[i][0];
    }
    return sum;
}

/** Multiplies two matrices together.
*
* \param[in] m1,m2 Matrix inputs
*
* Requires the two matrices to be compatible with multiplication.
*/
template <int M, int N, int P, int Q, class T>
Matrix<M, Q, T> multiply(const Matrix<M, N, T>& m1, const Matrix<P, Q, T>& m2) {
    if (N != P) {
        throw std::runtime_error(
            "Matrices don't have the right dimensions for multiplication");
    }

    Matrix<M, Q, T> res;

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < Q; ++j) {
            res[i][j] = dot(transpose(m1.getRow(i)), m2.getCol(j));
        }
    }

    return res;
}

}  // matrix

}  // yage

#endif
