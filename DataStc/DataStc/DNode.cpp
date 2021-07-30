#include "DNode.h"
#include <iostream>

DNode::DNode(int val)
{
	data = val;
	next = NULL;
	prev = NULL;
	std::cout << "Created a node with value: " << val << "\n";
}