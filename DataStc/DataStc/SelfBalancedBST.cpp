#include "SelfBalancedBST.h"

SelfBalancedBST::SelfBalancedBST()
{
	root = NULL;
}

int SelfBalancedBST::max(int a, int b)
{
	return (a > b) ? a : b;
}

int SelfBalancedBST::height(SBBSTNode* root)
{
	if (root == NULL)
		return -1;
	else
	{
		int heightleft = height(root->left);
		int heightright = height(root->right);
		if (heightleft > heightright)
			return (heightleft + 1);
		else
			return (heightright + 1);
	}
}

int SelfBalancedBST::getbalancefactor(SBBSTNode* root)
{
	if (root == NULL)
		return 0;
	else
		return (height(root->left) - height(root->right));
}

SBBSTNode* SelfBalancedBST::leftrotate(SBBSTNode* x)
{
	SBBSTNode* y = x->right;
	SBBSTNode* T2 = y->left;
	x->right = T2;
	y->left = x;
	x->height = (max(height(x->left), height(x->right)) + 1);
	y->height = (max(height(y->left), height(y->right)) + 1);
	return y;
}

SBBSTNode* SelfBalancedBST::rightrotate(SBBSTNode* y)
{
	SBBSTNode* x = y->left;
	SBBSTNode* T2 = x->right;
	x->right = y;
	y->left = T2;
	x->height = (max(height(x->left), height(x->right)) + 1);
	y->height = (max(height(y->left), height(y->right)) + 1);
	return x;
}

SBBSTNode* SelfBalancedBST::_insert(int val, SBBSTNode* _root)
{
	if (val < _root->data)
	{
		if (_root->left == NULL)
		{
			SBBSTNode* n = new SBBSTNode(val);
			_root->left = n;
		}
		else
		{
			_root->left = _insert(val, _root->left);
		}
	}
	else if (val > _root->data)
	{
		if (_root->right == NULL)
		{
			SBBSTNode* n = new SBBSTNode(val);
			_root->right = n;
		}
		else
			_root->right = _insert(val, _root->right);
	}
	else
	{
		std::cout << "Value already exists!\n";
		return _root;
	}
	_root->height = (max(height(_root->left), height(_root->right)) + 1);
	int bf = getbalancefactor(_root);
	//Left Left case
	if (bf > 1 && val < _root->left->data)
		return rightrotate(_root);
	// Right Right case
	else if (bf < -1 && val > _root->right->data)
		return leftrotate(_root);
	// Left Right case
	else if (bf > 1 && val > _root->left->data)
	{
		_root->left = leftrotate(_root->left);
		return rightrotate(_root);
	}
	//Right Left case
	else if (bf < -1 && val < _root->right->data)
	{
		_root->right = rightrotate(_root->right);
		return leftrotate(_root);
	}
	return _root;
}

void SelfBalancedBST::add(int val)
{
	if (root == NULL)
	{
		SBBSTNode* n = new SBBSTNode(val);
		root = n;
		return;
	}
	root = _insert(val, root);
	sort_increasing();
	return;
}

SBBSTNode* SelfBalancedBST::Findmin(SBBSTNode* root)
{
	SBBSTNode* temp = root;
	while (temp->left != NULL)
	{
		temp = temp->left;
	}
	return temp;
}

SBBSTNode* SelfBalancedBST::_remove(int val, SBBSTNode* root)
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
			SBBSTNode* temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL)
		{
			SBBSTNode* temp = root->left;
			delete root;
			return temp;
		}
		//Case 3: Two children
		else
		{
			SBBSTNode* temp = Findmin(root->right);
			root->data = temp->data;
			root->right = _remove(temp->data, root->right);
		}
	}
	root->height = 1 + max(height(root->left), height(root->right));
	int bf = getbalancefactor(root);
	//Left Left case
	if (bf > 1 && getbalancefactor(root->left) >= 0)
		return rightrotate(root);
	// Right Right case
	else if (bf < -1 && getbalancefactor(root->right) <= 0)
		return leftrotate(root);
	// Left Right case
	else if (bf > 1 && getbalancefactor(root->left) < 0)
	{
		root->left = leftrotate(root->left);
		return rightrotate(root);
	}
	//Right Left case
	else if (bf < -1 && getbalancefactor(root->right) > 0)
	{
		root->right = rightrotate(root->right);
		return leftrotate(root);
	}
	return root;
}

void SelfBalancedBST::remove(int val)
{
	if (root == NULL)
	{
		std::cout << "Tree is empty!\n";
		return;
	}
	else
		root = _remove(val, root);
	sort_increasing();
	return;
}

SBBSTNode* SelfBalancedBST::_search(int val, SBBSTNode* root)
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

SBBSTNode* SelfBalancedBST::search(int val)
{
	if (root == NULL)
	{
		return NULL;
		std::cout << "Value not found!\n";
	}
	else
		return _search(val, root);
}

void SelfBalancedBST::preorder(SBBSTNode* n)
{
	if (n != NULL)
	{
		std::cout << n->data << " ";
		preorder(n->left);
		preorder(n->right);
	}
}

void SelfBalancedBST::sort_increasing()
{
	preorder(root);
	std::cout << "\n";
}

void SelfBalancedBST::postorder(SBBSTNode* n)
{
	if (n != NULL)
	{
		std::cout << n->data << " ";
		preorder(n->right);
		preorder(n->left);
	}
}

void SelfBalancedBST::sort_decreasing()
{
	postorder(root);
	std::cout << "\n";
}
