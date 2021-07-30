#include "SingleLL.h"

SingleLL::SingleLL()
{
	head = NULL;
}

void SingleLL::print()
{
	SNode* temp = head;
	std::cout << "The list is: ";
	while (temp != NULL)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << "\n";
}

void SingleLL::add(int val)
{
	SNode* a = new SNode(val);
	if (head == NULL)
	{
		head = a;
		print();
		return;
	}
	SNode* temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = a;
	print();
}

void SingleLL::remove(int val)
{
	if (head == NULL)
	{
		std::cout << "No value in list to be removed!\n";
		return;
	}
	if (head->data == val)
	{
		head = NULL;
		std::cout << "Value removed, the list is now empty!\n";
		return;
	}
	SNode* temp = head;
	while (temp->next->data != val)
	{
		temp = temp->next;
	}
	temp->next = temp->next->next;
	print();
}

std::string SingleLL::search(int val)
{
	SNode* temp = head;
	while (temp != NULL)
	{
		if (temp->data == val)
		{
			return "True";
		}
		temp = temp->next;
	}
	return "False";
}

void SingleLL::sort_increasing()
{
	SNode* trav1 = head;
	SNode* trav2 = NULL;
	if (head == NULL)
	{
		std::cout << "List is empty.\n";
		return;
	}
	else
	{
		while (trav1 != NULL)
		{
			trav2 = trav1->next;
			while (trav2 != NULL)
			{
				if (trav2->data < trav1->data)
				{
					int temp = trav1->data;
					trav1->data = trav2->data;
					trav2->data = temp;
				}
				trav2 = trav2->next;
			}
			trav1 = trav1->next;
		}
	}
	print();
}

void SingleLL::sort_decreasing()
{
	SNode* trav1 = head;
	SNode* trav2 = NULL;
	if (head == NULL)
	{
		std::cout << "List is empty.\n";
		return;
	}
	else
	{
		while (trav1 != NULL)
		{
			trav2 = trav1->next;
			while (trav2 != NULL)
			{
				if (trav2->data > trav1->data)
				{
					int temp = trav1->data;
					trav1->data = trav2->data;
					trav2->data = temp;
				}
				trav2 = trav2->next;
			}
			trav1 = trav1->next;
		}
	}
	print();
}
