#ifndef SEARCHABLE_TREE_BAG_HPP
# define SEARCHABLE_TREE_BAG_HPP

#include "tree_bag.hpp"
#include "searchable_bag.hpp"

class searchable_tree_bag : public tree_bag, public searchable_bag
{
public:
	searchable_tree_bag() {}
	searchable_tree_bag(const searchable_tree_bag& src) : tree_bag(src) {}
	searchable_tree_bag& operator=(const searchable_tree_bag& src)
	{
		tree_bag::operator=(src);
		return *this;
	}
	virtual ~searchable_tree_bag() {}

	bool has(int value) const
	{
		node *cur = tree;

		while (cur && cur->value != value)
			cur = (value < cur->value) ? cur->l : cur->r;
		return (cur != 0);
	}
};

#endif
