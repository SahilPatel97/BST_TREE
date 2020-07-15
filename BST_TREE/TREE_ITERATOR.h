#pragma once
#ifndef TREE_ITERATOR_H
#define TREE_ITERATOR_H

#include <iterator>
#include <list>

#include "TREE_NODE.h"


using namespace std;

template <typename Data>
class TREE_ITERATOR : public iterator<input_iterator_tag, Data> {
private:
	TREE_NODE<Data> * curr_node;


public:
	/*
	* Constructor that initializes TREE_iterator that points to
	* the current node
	*/
	TREE_ITERATOR(TREE_NODE<Data> * curr_node) {
		this->curr_node = curr_node;
	}

	Data operator *() const {
		return curr_node->val;
	}

	TREE_ITERATOR<Data> & operator++ () {
		curr_node = curr_node->next_node();
		return *this;
	}

	TREE_ITERATOR<Data>operator++ (int) {
		TREE_ITERATOR prev = TREE_ITERATOR(curr_node);
		++(this);
		return prev;
	}
	bool operator == (TREE_ITERATOR<Data> const& diff) const {
		if (this->curr_node == diff.curr_node) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator!= (TREE_ITERATOR<Data> const& diff) const {
		if (this->curr_node != diff.curr_node) {
			return true;
		}
		else {
			return false;
		}
	}
};
#endif
