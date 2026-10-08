#include "bigint.hpp"

std::ostream& operator<<(std::ostream& os, bigint obj)
{
	return os << obj.getStr();
}
