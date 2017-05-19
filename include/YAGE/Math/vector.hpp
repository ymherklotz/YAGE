#ifndef YAGE_MATH_VECTOR_HPP
#define YAGE_MATH_VECTOR_HPP

#include <vector>

namespace yage
{

class Vector
{
protected:
	std::vector<long double> members_;

public:
	Vector()=delete;
	virtual ~Vector();

	inline long double &operator[](std::size_t index)
	{
		return members_[index];
	}
	
	inline const long double &operator[](std::size_t index) const
	{
		return members_[index];
	}
	
	inline Vector &operator+()
	{
		return *this;
	}
	
	inline Vector &operator-()
	{
		for(auto &i : members_)
		{
			i=-i;
		}
		return *this;
	}
	
	inline Vector &operator+=(const Vector &other)
	{
		for(std::size_t i=0; i<members_.size(); ++i)
		{
			members_[i]+=other[i];
		}
		return *this;
	}
	
	inline Vector &operator-=(const Vector &other)
	{
		for(std::size_t i=0; i<members_.size(); ++i)
		{
			members_[i]-=other[i];
		}
		return *this;
	}

	inline Vector &operator*=(const Vector &other)
	{
		for(std::size_t i=0; i<members_.size(); ++i)
		{
			members_[i]*=other[i];
		}
		return *this;
	}

	inline Vector operator+(const Vector &other) const
	{
		Vector v(members_);
		return v+=other;
	}

	inline Vector operator-(const Vector &other) const
	{
		Vector v(members_);
		return v-=other;
	}

	inline Vector operator*(const Vector &other) const
	{
		Vector v(members_);
		return v*=other;
	}

	inline Vector operator+(long double other) const
	{
		std::vector<long double> mem;
		for(auto i : members_)
		{
			mem.emplace_back(i+other);
		}
		return Vector(mem);
	}

	inline Vector operator-(long double other) const
	{
		std::vector<long double> mem;
		for(auto i : members_)
		{
			mem.emplace_back(i-other);
		}
		return Vector(mem);
	}

	inline Vector operator*(long double other) const
	{
		std::vector<long double> mem;
		for(auto i : members_)
		{
			mem.emplace_back(i*other);
		}
		return Vector(mem);
	}

	inline Vector operator/(long double other) const
	{
		std::vector<long double> mem;
		for(auto i : members_)
		{
			mem.emplace_back(i/other);
		}
		return Vector(mem);
	}

protected:
	Vector(const std::vector<long double> &members);
};

} // yage

#endif
