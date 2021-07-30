#pragma once
#include "DNode.h"
#include <iostream>
#include "DataStc.h"

class DoubleLL : DataStc {
private:
	DNode* head;
	DNode* tail;
public:
	DoubleLL();
	void add(int val);
	void remove(int k);
	std::string search(int val);
	void sort_increasing();
	void sort_decreasing();
	void print();
	void printreverse();
};

