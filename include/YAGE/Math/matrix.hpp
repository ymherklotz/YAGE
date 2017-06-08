#ifndef YAGE_MATH_MATRIX_HPP
#define YAGE_MATH_MATRIX_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

namespace yage
{

template<int Rows, int Cols, class Type> class Matrix;

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

	int rowSize()
	{
		return Rows;
	}

	int colSize()
	{
		return Cols;
	}

	detail::Row<Rows, Cols, Type> operator[](int row)
	{
		return detail::Row<Rows, Cols, Type>(this, row);
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
		os<<'[';
		for(std::size_t i=0; i<mat.data_.size()-1; ++i)
		{
			if(i%Cols == 0 && i!=0)
			{
				os<<"]\n[";
			}
			
			if((i+1)%Cols == 0)
			{
				os<<mat.data_[i];
			}
			else
			{
				os<<mat.data_[i]<<" ";
			}
		}
		os<<mat.data_[mat.data_.size()-1]<<"]";
		return os;
	}
};

template<int Rows=2, class Type=double> class Vector : public Matrix<Rows, 1, Type>
{
public:
	Vector<Rows, Type>() : Matrix<Rows, 1, Type>() {}
	explicit Vector<Rows, Type>(const Matrix<Rows, 1, Type> &other)
	{
		this->data_=other.data_;
	}

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
	static_assert(M!=1, "Called wrong transpose");
}

template<int N, class T> Vector<N, T> transpose(const Matrix<1, N, T> &m)
{
	
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

} // vector

} // yage

#endif
