#ifndef YAGE_MATH_MATRIX_HPP
#define YAGE_MATH_MATRIX_HPP

#include <memory>
#include <vector>

namespace yage
{

template<int Rows, int Cols, class Type> class Matrix;

namespace detail
{

template<int Rows, int Cols, class Type> class Row
{
private:
	std::shared_ptr<Matrix<Rows, Cols, Type>> parent_;
	int index_;

public:
	Row<Rows, Cols, Type>(std::shared_ptr<Matrix<Rows, Cols, Type>> parent, int index) :
		parent_(parent), index_(index)
	{}

	Type &operator[](int col)
	{
		return parent_->data_[index_*Cols+col];
	}
};

} // detail

template<int Rows=4, int Cols=4, class Type=double> class Matrix
{
	friend class detail::Row<Rows, Cols, Type>;
private:
	std::vector<Type> data_;

public:
	Matrix<Rows, Cols, Type>() : data_(Rows*Cols) {}
	Matrix<Rows, Cols, Type>(int rows, int cols) : data_(rows*cols) {}

	detail::Row<Rows, Cols, Type> operator[](int row)
	{
		return detail::Row<Rows, Cols, Type>(std::make_shared<Matrix<Rows, Cols, Type>>(*this), row);
	}
};

} // yage

#endif
