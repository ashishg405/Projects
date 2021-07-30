#pragma once
#include "SBBSTNode.h"
#include "DataStc.h"

class SelfBalancedBST : DataStc {
private:
	int max(int a, int b);
	int getbalancefactor(SBBSTNode* root);
	SBBSTNode* leftrotate(SBBSTNode* x);
	SBBSTNode* rightrotate(SBBSTNode* y);
	SBBSTNode* Findmin(SBBSTNode* root);
	SBBSTNode* _insert(int val, SBBSTNode* _root);
	SBBSTNode* _remove(int val, SBBSTNode* _root);
	SBBSTNode* _search(int val, SBBSTNode* leaf);
	void preorder(SBBSTNode* n);
	void postorder(SBBSTNode* n);
public:
	int height(SBBSTNode* root);
	SelfBalancedBST();
	SBBSTNode* root;
	void add(int val);
	void remove(int val);
	void sort_increasing();
	void sort_decreasing();
	SBBSTNode* search(int val);
};

