#pragma once
#include <iostream>
#include "DataStc.h"
#include <vector>

class Array : DataStc {
private:
	int* arr;
	int size;
	int tail;
public:
	Array(int given_size);
	void print();
	void add(int a);
	void remove(int b);
	std::string search(int c);
	void sort_increasing();
	void sort_decreasing();
	void extend(std::vector<int> v);
};

