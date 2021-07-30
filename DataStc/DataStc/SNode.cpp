#include <iostream>
#include "SNode.h"

SNode::SNode(int val)
{
	data = val;
	next = NULL;
	std::cout << "Created a node with value: " << val << "\n";
}

