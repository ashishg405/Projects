#pragma once


#include <iostream>

class SBBSTNode {
public:
	int data;
	SBBSTNode* left;
	SBBSTNode* right;
	int height;
	SBBSTNode(int val);
};
