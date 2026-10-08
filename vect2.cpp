#include "vect2.hpp"

std::ostream& operator<<(std::ostream os, vect2 obj)
{
	return os << "{" << obj[0] << ", " << obj[1] << "}";
}

vect2 operator*(int n, vect2 other) { return other * n; }