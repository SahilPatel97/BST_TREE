#pragma once
#pragma once
#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <iostream>
#include <iomanip>

using namespace std;

template <typename Data>


class TREE_NODE {
public:
	TREE_NODE<Data> *left;
	TREE_NODE<Data> *right;
	TREE_NODE<Data> *parent;
	Data const val;

	TREE_NODE(const Data &d) : val(d) {
		right = left = parent = nullptr;
	}

	TREE_NODE<Data> *next_node() {
		TREE_NODE<Data> * temp_node = this;
		if (temp_node->right != nullptr) {
			temp_node = temp_node->right;
			while (temp_node->left != nullptr) {
				temp_node = temp_node->left;
			}
			return temp_node;
		}
	}
};

template <typename Data>
ostream &operator << (ostream & str, const TREE_NODE<Data> &x) {
	str << '{';
	str << setw(10) << &x;
	str << "; parent:" << setw(10) << x.parent;
	str << "; r_child:" << setw(10) << x.right;
	str << "; l_child:" << setw(10) << x.left;
	str << '}';
	return str;
}

#endif // !TREE_NODE_H
