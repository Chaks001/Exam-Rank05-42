#ifndef SET_HPP
# define SET_HPP

#include "searchable_bag.hpp"
#include <stdexcept>

/* set EMPRUNTE un searchable_bag sans le posseder : copier un set partage le
** bag, detruire un set ne detruit pas le bag, et le bag doit survivre au set. */
class set
{
private:
	searchable_bag *bag;

public:
	set() : bag(0) {}
	set(searchable_bag& src) : bag(&src) {}
	set(const set& src) : bag(src.bag) {}
	set& operator=(const set& src) { bag = src.bag; return *this; }
	~set() {}

	bool has(int value) const { return bag && bag->has(value); }
	void insert(int value) { if (bag && !has(value)) bag->insert(value); }
	void insert(int *values, int size)
	{
		for (int i = 0; i < size; i++)
			insert(values[i]);
	}
	void print() const { if (bag) bag->print(); }
	void clear() { if (bag) bag->clear(); }

	const searchable_bag& get_bag() const
	{
		if (!bag)
			throw std::runtime_error("set: aucun bag associe");
		return *bag;
	}
};

#endif
