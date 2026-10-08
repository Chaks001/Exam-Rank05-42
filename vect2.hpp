#ifndef VECT2_HPP
# define VECT2_HPP


#include <iostream>

class vect2
{
private:
	int v[2];

public:
	vect2(int x = 0, int y = 0) { v[0] = x; v[1] = y; }

	int operator[](int i) const { return v[i]; }
	int& operator[](int i) { return v[i]; }

	vect2& operator+=(vect2 other) { v[0] += other.v[0]; v[1] += other.v[1]; return *this; }
	vect2& operator-=(vect2 other) { v[0] -= other.v[0]; v[1] -= other.v[1]; return *this; }
	vect2& operator*=(int n) { v[0] *= n; v[1] *= n; return *this; }

	vect2 operator+(vect2 other) const { return vect2(*this) += other; }
	vect2 operator-(vect2 other) const { return vect2(*this) -= other; }
	vect2 operator*(int n) const { return vect2(*this) *= n; }
	vect2 operator-() const { return vect2(-v[0], -v[1]); }

	vect2& operator++() { return *this += vect2(1, 1); }
	vect2& operator--() { return *this -= vect2(1, 1); }
	
	vect2 operator++(int) { vect2 tmp(*this); ++(*this); return tmp; }
	vect2 operator--(int) { vect2 tmp(*this); --(*this); return tmp; }

	bool operator==(vect2 other) const { return v[0] == other.v[0] && v[1] == other.v[1]; }
	bool operator!=(vect2 other) const { return !(*this == other); }
};

vect2 operator*(int n, vect2 other);
std::ostream& operator<<(std::ostream& os, vect2 obj);

#endif