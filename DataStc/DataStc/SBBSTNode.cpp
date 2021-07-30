#include "SBBSTNode.h"

SBBSTNode::SBBSTNode(int val)
{
	data = val;
	left = NULL;
	right = NULL;
	height = 0;
	std::cout << "Created a node with value: " << val << "\n";
}