#pragma once
#include "BSTNode.h"
#include "DataStc.h"

class BST : DataStc {
private:
	void _add(int val, BSTNode* _root);
	BSTNode* _remove(int val, BSTNode* leaf);
	BSTNode* _search(int val, BSTNode* leaf);
	void _printincreasing(BSTNode* _root);
	void _printdecreasing(BSTNode* _root);
	BSTNode* Findmin(BSTNode* root);
public:
	BSTNode* root;
	BST();
	void add(int val);
	void remove(int val);
	BSTNode* search(int val);
	void sort_increasing();
	void sort_decreasing();
};


