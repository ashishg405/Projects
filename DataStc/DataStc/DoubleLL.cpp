#include "DoubleLL.h"
#include <iostream>

DoubleLL::DoubleLL()
{
	head = NULL;
	tail = NULL;
}

void DoubleLL::print()
{
	if (head == NULL)
		std::cout << "The list is empty!\n";
	else
	{
		DNode* temp = head;
		std::cout << "The list is: ";
		while (temp != NULL)
		{
			std::cout << temp->data << " ";
			temp = temp->next;
		}
		std::cout << "\n";
	}
}

void DoubleLL::printreverse()
{
	if (head == NULL)
		std::cout << "The list is empty!\n";
	else
	{
		DNode* temp = tail;
		std::cout << "The list is: ";
		while (temp != NULL)
		{
			std::cout << temp->data << " ";
			temp = temp->prev;
		}
		std::cout << "\n";
	}
}

void DoubleLL::add(int a)
{
	DNode* n = new DNode(a);
	if (head == NULL)
	{
		head = tail = n;
		print();
		return;
	}
	DNode* temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = n;
	tail = n;
	print();
}

void DoubleLL::remove(int val)
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
	DNode* temp = head;
	while (temp->next->data != val)
	{
		temp = temp->next;
	}
	temp->next = temp->next->next;
	print();
}

std::string DoubleLL::search(int a)
{
	DNode* temp = head;
	while (temp != NULL)
	{
		if (temp->data == a)
		{
			return "True";
		}
		temp = temp->next;
	}
	return "False";
}

void DoubleLL::sort_increasing()
{
	DNode* trav1 = head;
	DNode* trav2 = NULL;
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

void DoubleLL::sort_decreasing()
{
	DNode* trav1 = head;
	DNode* trav2 = NULL;
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