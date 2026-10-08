#ifndef BIGINT_HPP
# define BIGINT_HPP

#include <sstream>
#include <iostream>
#include <string>

class bigint
{
private:
	std::string str;

public:
	bigint(unsigned int num = 0) { std::stringstream ss; ss << num; str = ss.str(); }
	std::string getStr() const { return str; }

	bigint operator+(bigint other) const
	{
		std::string res;
		int i = str.length() - 1, j = other.str.length() - 1, carry = 0;
		while (i >= 0 || j >= 0 || carry)
		{
			int sum = carry;
			if (i >= 0) sum += str[i--] - '0';
			if (j >= 0) sum += other.str[j--] - '0';
			res += char(sum % 10 + '0');
			carry = sum / 10;
		}
		bigint tmp;
		tmp.str = std::string(res.rbegin(), res.rend());
		return tmp;
	}
	bigint& operator+=(bigint other) { return *this = *this + other; }
	bigint& operator++() { return *this += 1; }
	bigint operator++(int) { bigint tmp(*this); ++(*this); return tmp; }

	bool operator<(bigint other) const
	{
		if (str.length() != other.str.length()) return str.length() < other.str.length();
		return str < other.str;
	}
	bool operator==(bigint other) const { return str == other.str; }
    bool operator!=(bigint other) const { return str != other.str; }
	bool operator>(bigint other) const  { return other < *this; }
	bool operator<=(bigint other) const { return !(*this > other); }
	bool operator>=(bigint other) const { return !(*this < other); }

	bigint& operator<<=(bigint other)
	{
		unsigned int n; 
		std::stringstream(other.str) >> n;
		if (str != "0") str.append(n, '0');
		return *this;
	}
	bigint& operator>>=(bigint other)
	{
		unsigned int n; 
		std::stringstream(other.str) >> n;
		if (n >= str.length()) str = "0";
		else str.erase(str.length() - n);
		return *this;
	}
	bigint operator<<(bigint other) const { return bigint(*this) <<= other; }
	bigint operator>>(bigint other) const { return bigint(*this) >>= other; }
};

std::ostream& operator<<(std::ostream& os, bigint obj);

#endif
