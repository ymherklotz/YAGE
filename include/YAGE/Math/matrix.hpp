/* ----------------------------------------------------------------------------
 * matrix.hpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#ifndef YAGE_MATH_MATRIX_HPP
#define YAGE_MATH_MATRIX_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace yage
{

template<int Rows, int Cols, class Type> class Matrix;

// includes implementation details that should not be accessible to the user
namespace detail
{

// Row class
//
// Used to implement the double square bracket operator and be able
// to return the value by reference of the array.
template<int Rows, int Cols, class Type> class Row
{
private:
	Matrix<Rows, Cols, Type> *parent_;
	int index_;

public:
	Row<Rows, Cols, Type>(Matrix<Rows, Cols, Type> *parent, int index) :
		parent_(parent), index_(index)
	{}

	Type& operator[](int col)
	{
		// the index is the y-position of the element in the matrix
		return parent_->data_[index_*Cols+col];
	}

	const Type& operator[](int col) const
	{
		return parent_->data_[index_*Cols+col];
	}
};

} // detail

// Matrix class
//
// Implements the base Matrix class that is inherited by other classes to make them more
// specific.
template<int Rows=4, int Cols=4, class Type=double> class Matrix
{
	// friended with the row class so that it can access protected member data
	friend class detail::Row<Rows, Cols, Type>;
protected:
	std::vector<Type> data_;

public:
	Matrix<Rows, Cols, Type>() : data_(Rows*Cols) {}
	
	int rowSize() const
	{
		return Rows;
	}

	int colSize() const
	{
		return Cols;
	}

	// returns the row in a row matrix
	Matrix<1, Cols, Type> getRow(int row) const
	{
		Matrix<1, Cols, Type> rowMatrix;
		for(int i=0; i<Cols; ++i)
		{
			rowMatrix[0][i]=data_[row][i];
		}
		return rowMatrix;
	}

	// returns the column in a column matrix
	Matrix<Rows, 1, Type> getCol(int col) const
	{
		Matrix<Rows, 1, Type> colMatrix;
		for(int i=0; i<Rows; ++i)
		{
			colMatrix[i][0]=data_[i][col];
		}
		return colMatrix;
	}

	// iterator support for begin
	typename std::vector<Type>::iterator begin()
	{
		return data_.begin();
	}

	// iterator support for end
	typename std::vector<Type>::iterator end()
	{
		return data_.end();
	}

	// prints out the matrix, but can also be implemented by other classes to print data
	// differently
	virtual std::string toString() const
	{
		std::stringstream ss;
		ss<<'[';
		for(int i=0; i<Rows-1; ++i)
		{
			ss<<'[';
			for(int j=0; j<Cols-1; ++j)
			{
				ss<<data_[i*Cols+j]<<' ';
			}
			ss<<data_[(Rows-1)*Cols+Cols-1]<<"],";
		}
		ss<<'[';
		for(int j=0; j<Cols-1; ++j)
		{
			ss<<data_[(Rows-1)*Cols+j]<<' ';
		}
		ss<<data_[(Rows-1)*Cols+Cols-1]<<"]]";
		return ss.str();
	}

	detail::Row<Rows, Cols, Type> operator[](int row)
	{
		return detail::Row<Rows, Cols, Type>(this, row);
	}

	detail::Row<Rows, Cols, Type> operator[](int row) const
	{
		// TODO got to fix this
		return detail::Row<Rows, Cols, Type>((Matrix<Rows, Cols, Type>*)this, row);
	}

	Matrix<Rows, Cols, Type>& operator=(const Matrix<Rows, Cols, Type> &other)
	{
		if(this!=&other)
		{
			data_=other.data_;
		}
		return *this;
	}

	Matrix<Rows, Cols, Type>& operator+=(const Matrix<Rows, Cols, Type> &rhs)
	{
		std::vector<Type> out;
		out.reserve(data_.size());
		std::transform(data_.begin(), data_.end(), rhs.data_.begin(), std::back_inserter(out),
		               [] (Type a, Type b) {
			               return a+b;
		               });
		data_=std::move(out);
		return *this;
	}

	Matrix<Rows, Cols, Type>& operator-=(const Matrix<Rows, Cols, Type> &rhs)
	{
		std::vector<Type> out;
		out.reserve(data_.size());
		std::transform(data_.begin(), data_.end(), rhs.begin(), std::back_inserter(out),
		               [] (Type a, Type b) {
			               return a-b;
		               });
		data_=std::move(out);
		return *this;
	}
};

template<int M, int N, class T>
Matrix<M, N, T> operator+(Matrix<M, N, T> lhs, const Matrix<M, N, T> &rhs)
{
	lhs+=rhs;
	return lhs;
}

template<int M, int N, class T>
Matrix<M, N, T> operator-(Matrix<M, N, T> lhs, const Matrix<M, N, T> &rhs)
{
	lhs-=rhs;
	return lhs;
}

template<int M, int N, class T>
Matrix<M, N, T> operator+(Matrix<M, N, T> lhs, const T &rhs)
{
	for(auto &data : lhs)
	{
		data+=rhs;
	}
	return lhs;
}

template<int M, int N, class T>
Matrix<M, N, T> operator+(const T &lhs, Matrix<M, N, T> rhs)
{
	for(auto &data : rhs)
	{
		data+=lhs;
	}
	return rhs;
}

template<int M, int N, class T>
Matrix<M, N, T> operator-(Matrix<M, N, T> lhs, const T &rhs)
{
	for(auto &data : lhs)
	{
		data-=rhs;
	}
	return lhs;
}

template<int M, int N, class T>
Matrix<M, N, T> operator-(const T &lhs, Matrix<M, N, T> rhs)
{
	for(auto &data : rhs)
	{
		data=lhs-data;
	}
	return rhs;
}

template<int M, int N, class T>
Matrix<M, N, T> operator*(Matrix<M, N, T> lhs, const T &rhs)
{
	for(auto &data : lhs)
	{
		data*=rhs;
	}
	return lhs;
}

template<int M, int N, class T>
Matrix<M, N, T> operator*(const T &lhs, Matrix<M, N, T> rhs)
{
	for(auto &data : rhs)
	{
		data*=lhs;
	}
	return rhs;
}

template<int M, int N, class T>
Matrix<M, N, T> operator/(Matrix<M, N, T> lhs, const T &rhs)
{
	for(auto &data : lhs)
	{
		data/=rhs;
	}
	return lhs;
}

template<int M, int N, class T>
bool operator==(const Matrix<M, N, T> &lhs, const Matrix<M, N, T> &rhs)
{
	for(int i=0; i<M; ++i)
		for(int j=0; j<N; ++j)
			if(lhs[i][j]!=rhs[i][j])
					return false;
	return true;
}

template<int M, int N, class T>
std::ostream& operator<<(std::ostream &os, const Matrix<M, N, T> &mat)
{
	return os<<mat.toString();
}

template<int Rows=2, class Type=double> class Vector : public Matrix<Rows, 1, Type>
{
public:
	Vector<Rows, Type>() : Matrix<Rows, 1, Type>() {}
	explicit Vector<Rows, Type>(const Matrix<Rows, 1, Type> &other) : Matrix<Rows, 1, Type>(other) {}

	Type& operator[](int col)
	{
		return this->data_[col];
	}

	const Type& operator[](int col) const
	{
		return this->data_[col];
	}

	virtual std::string toString() const
	{
		std::stringstream ss;
		ss<<"[";
		for(std::size_t i=0; i<this->data_.size()-1; ++i)
		{
			ss<<this->data_[i]<<" ";
		}
		ss<<this->data_[this->data_.size()-1]<<"]";
		return ss.str();
	}
};

template<class Type=double> class Vector2 : public Vector<2, Type>
{
public:
	Vector2<Type>() : Vector<2, Type>() {}
	
	Vector2<Type>(Type x, Type y)
	{
		this->data_[0]=x;
		this->data_[1]=y;
	}
	
	Vector2<Type>(const Matrix<2, 1, Type> &other) : Vector<2, Type>(other) {} 

	Type& x()
	{
		return this->data_[0];
	}

	const Type& x() const
	{
		return this->data_[0];
	}
	
	Type& y()
	{
		return this->data_[1];
	}

	const Type& y() const
	{
		return this->data_[1];
	}	
};

typedef Vector2<double> Vector2d;

namespace matrix
{

template<int M, int N, class T> Matrix<N, M, T> transpose(const Matrix<M, N, T> &m)
{
	Matrix<N, M, T> trans;
	for(int i=0; i<M; ++i)
	{
		for(int j=0; j<N; ++j)
		{
			trans[j][i]=m[i][j];
		}
	}
	return trans;
}

template<int R, class T> T dot(const Matrix<R, 1, T> &m1, const Matrix<R, 1, T> &m2)
{
	T sum=0;
	for(int i=0; i<R; ++i)
	{
		sum += m1[i][0]*m2[i][0];
	}
	return sum;
}

template<int M, int N, int P, int Q, class T>
Matrix<M, Q, T> multiply(const Matrix<M, N, T> &m1, const Matrix<P, Q, T> &m2)
{
	if(N!=P)
	{
		throw std::runtime_error("Matrices don't have the right dimensions for multiplication");
	}
	
	Matrix<M, Q, T> res;

	for(int i=0; i<M; ++i)
	{
		for(int j=0; j<Q; ++j)
		{
			res[i][j] = dot(transpose(m1.getRow(i)), m2.getCol(j));
		}
	}

	return res;
}

} // matrix

} // yage

#endif
