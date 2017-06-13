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
template<int Rows, class Type> class Vector;

namespace detail
{

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
		return parent_->data_[index_*Cols+col];
	}

	const Type& operator[](int col) const
	{
		return parent_->data_[index_*Cols+col];
	}
};

} // detail

template<int Rows=4, int Cols=4, class Type=double> class Matrix
{
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

	Matrix<1, Cols, Type> getRow(int row) const
	{
		Matrix<1, Cols, Type> rowMatrix;
		for(int i=0; i<Cols; ++i)
		{
			rowMatrix[0][i]=data_[row][i];
		}
		return rowMatrix;
	}

	Matrix<Rows, 1, Type> getCol(int col) const
	{
		Matrix<Rows, 1, Type> colMatrix;
		for(int i=0; i<Rows; ++i)
		{
			colMatrix[i][0]=data_[i][col];
		}
		return colMatrix;
	}

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

	friend Matrix<Rows, Cols, Type> operator+(Matrix<Rows, Cols, Type> lhs,
	                                          const Matrix<Rows, Cols, Type> &rhs)
	{
		lhs+=rhs;
		return lhs;
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

	friend Matrix<Rows, Cols, Type> operator-(Matrix<Rows, Cols, Type> lhs,
	                                          const Matrix<Rows, Cols, Type> &rhs)
	{
		lhs-=rhs;
		return lhs;
	}

	friend std::ostream& operator<<(std::ostream &os, const Matrix<Rows, Cols, Type> &mat)
	{
		return os<<mat.toString();
	}
};

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

	
};

template<class Type=double> class Vector2 : public Vector<2, Type>
{
public:
	Vector2<Type>() : Vector<2, Type>() {}

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

template<int R, class T> T dot(const Vector<R, T> &v1, const Vector<R, T> &v2)
{
	
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
			int sum=0;
			
		}
	}

	return res;
}

} // matrix

} // yage

#endif
