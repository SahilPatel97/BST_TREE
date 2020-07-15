#pragma once
/*
* Author:	   Sahil Patel (your fucking boi)
* File name:   TREE.h
* Description: Header file for the Tree.cpp file. Lays out all the functions of the Tree.
*			   The priority of the tree structure goes as follows, Tree, iterator, node.
*			   The tree has access to iterator data and node data and iterator has access
*			   to the node data. However the reciprocal is not the same. The tree will be
*			   self balancing in order to maintain O(log(n)) effieciency
* Purpose:	   The purpose of the file is to initialize all functions regarding the tree
*			   and define the constructor and destructor of the tree
*/

#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "TREE_ITERATOR.h"
#include "TREE_NODE.h"

using namespace std;

template <typename Data>

class TREE {
protected:

	//Pointer to the root of the BST, or 0 if its empty
	TREE_NODE<Data> * root;

	//Size reps the # of nodes in the Tree
	unsigned int size;

	//Height of the BST, used to determine balance of tree
	unsigned int height;


public:
	typedef TREE_ITERATOR<Data> iterator;

	/*
	* Function: TREE
	* Description: Defines the constructor of the tree and sets the root,
	*			   size and height to zero
	* Purpose:	   Initializes a tree when called in main
	*/

	TREE() : root(0), size(0), height(0) {}

	/*
	* Function: ~TREE
	* Description: Defines the destructor of the tree. Calls on function
	*              destroyAll in order to deallocate the memory to prevent
	*              a memory leak
	* Purpose:	   Deallocate the memory of the tree
	*/
	virtual ~TREE() {
		deleteAll(root);
	}

	virtual bool insert(const Data &item) {
		unsigned int nheight = 1;
		if (root == nullptr) {
			root = new TREE_NODE<Data>(item);
			if (height < nheight) {
				height = nheight;
			}
			size = size + 1;
			return true;
		}

		TREE_NODE<Data> * curr = root;
		TREE_NODE<Data> * prev = nullptr;

		while (curr != nullptr) {
			if (item < curr->val) {
				prev = curr;
				curr = curr->left;
				nheight = nheight + 1;
			}
			else if (curr->val < item) {
				prev = curr;
				curr = curr->right;
				nheight = nheight + 1;
			}
			else {
				return false;
			}
		}

		if (item < prev->val) {
			curr = new TREE_NODE<Data>(item);
			curr->parent = prev;
			prev->left = curr;
		}
		else {
			curr = new TREE_NODE<Data>(item);
			curr->parent = prev;
			prev->right = curr;
		}
		if (height < nheight) {
			height = nheight;
		}
		size += 1;
		return true;
	}

	virtual iterator find(const Data &item) const {
		auto itr = this->begin();
		auto end = this->end();
		while (itr != end) {
			if (*itr < item) {
				++itr;
			}
			else if (item < *itr) {
				itr = end;
				return itr;
			}
			else {
				return itr;
			}
		}
		return itr;
	}

	unsigned int total() const {
		return size;
	}

	unsigned int Tiheight() const {
		if (root = nullptr) {
			return 0;
		}
		else {
			return height;
		}
	}

	bool empty() const {
		if (root == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}

	iterator begin() const {
		TREE_NODE<Data> * curr = root;
		while (curr->left != nullptr) {
			curr = curr->left;
		}
		return typename TREE<Data>::iterator(curr);
	}

	iterator end() const {
		return typename TREE<Data>::iterator(0);
	}

	void inorder() const {
		inOrder(root);
	}

private:

	static TREE_NODE<Data> * first(TREE_NODE<Data> *current) {
		if (!current) return 0;
		while (current->left) {
			current = current->left;
		}
		return current;
	}
	static void inOrder(TREE_NODE<Data> *n) {
		if (n = nullptr) {
			return;
		}
		inorder(n->left);
		cout << n->val;
		inOrder(n->right);
	}

	static void deleteAll(TREE_NODE<Data> *n) {
		if (n == nullptr) {
			return;
		}
		deleteAll(n->left);
		deleteAll(n->right);
		delete n;
	}


};

#endif // TREE_H