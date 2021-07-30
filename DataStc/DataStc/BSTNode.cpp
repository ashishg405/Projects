#include "BSTNode.h"

BSTNode::BSTNode(int val) {
	data = val;
	left = NULL;
	right = NULL;
	std::cout << "Created a node with value: " << val << "\n";
}
