
#include "BST.h"

BST::BST()
{
	root = NULL;
}

void BST::_add(int val, BSTNode* _root)
{
	if (val < _root->data)
	{
		if (_root->left == NULL)
		{
			BSTNode* n = new BSTNode(val);
			_root->left = n;
		}
		else
		{
			_add(val, _root->left);
		}
	}
	else if (val > _root->data)
	{
		if (_root->right == NULL)
		{
			BSTNode* n = new BSTNode(val);
			_root->right = n;
		}
		else
			_add(val, _root->right);
	}
	else
	{
		std::cout << "Value already exists!\n";
		return;
	}
}

void BST::add(int val)
{
	if (root == NULL)
	{
		BSTNode* n = new BSTNode(val);
		root = n;
		return;
	}
	_add(val, root);
}

BSTNode* BST::Findmin(BSTNode* root)
{
	BSTNode* temp = root;
	if (temp->left == NULL)
	{
		return temp;
	}
	while (temp->left->left != NULL)
	{
		temp = temp->left;
	}
	BSTNode* temp1 = temp->left;
	temp->left = temp->left->right;
	return temp1;
}

BSTNode* BST::_remove(int val, BSTNode* root)
{
	if (root == NULL)
	{
		std::cout << "Value not found!\n";
		return root;
	}
	else if (val < root->data)
	{
		root->left = _remove(val, root->left);
	}
	else if (val > root->data)
	{
		root->right = _remove(val, root->right);
	}
	else if (val == root->data)
	{
		//Case 1: No child
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			return NULL;
		}
		//Case 2: One child
		else if (root->left == NULL)
		{
			BSTNode* temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL)
		{
			BSTNode* temp = root->left;
			delete root;
			return temp;
		}
		//Case 3: Two children
		else
		{
			BSTNode* temp = Findmin(root->right);
			temp->left = root->left;
			if (temp->data != root->right->data)
			{
				temp->right = root->right;
			}
			return temp;
		}
	}
	return root;
}

void BST::remove(int val)
{
	if (root == NULL)
	{
		std::cout << "Tree is empty!\n";
		return;
	}
	else
		root = _remove(val, root);
	return;
}

BSTNode* BST::_search(int val, BSTNode* root)
{
	if (root == NULL)
	{
		std::cout << "Value not found!\n";
		return NULL;
	}
	if (root->data == val)
	{
		std::cout << "Value found!\n";
		return root;
	}
	else if (val < root->data)
	{
		return _search(val, root->left);
	}
	else
		return _search(val, root->right);
}

BSTNode* BST::search(int val)
{
	if (root == NULL)
	{
		return NULL;
		std::cout << "Value not found!\n";
	}
	else
		return _search(val, root);
}

void BST::_printincreasing(BSTNode* _root)
{
	if (_root == NULL)
		return;
	_printincreasing(_root->left);
	std::cout << _root->data << " ";
	_printincreasing(_root->right);
}

void BST::sort_increasing()
{
	if (root == NULL)
	{
		std::cout << "Tree empty!\n";
		return;
	}
	_printincreasing(root);
	std::cout << "\n";
}

void BST::_printdecreasing(BSTNode* _root)
{
	if (_root == NULL)
		return;
	else
	{
		_printdecreasing(_root->right);
		std::cout << _root->data << " ";
		_printdecreasing(_root->left);
	}
}

void BST::sort_decreasing()
{
	_printdecreasing(root);
}

