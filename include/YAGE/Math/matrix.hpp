#ifndef YAGE_MATH_MATRIX_HPP
#define YAGE_MATH_MATRIX_HPP

namespace yage
{

template<typename Type, int Cols, int Rows> class Matrix
{
private:
	Type x[Cols][Rows];

public:
	Matrix()
	{
		for(int i=0; i<Cols; ++i)
		{
			for(int j=0; j<Rows; ++j)
			{
				x[i][j]=5;
			}
		}
	}

	Type get(int i, int j) const
	{
		return x[i][j];
	}
};

} // yage

#endif
