#pragma once
#include "SNode.h"
#include <iostream>
#include "DataStc.h"

class SingleLL : DataStc {
private:
	SNode* head;
public:
	SingleLL();
	void add(int val);
	void print();
	void remove(int val);
	std::string search(int val);
	void sort_increasing();
	void sort_decreasing();
};

