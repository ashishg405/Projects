#include "DataStc.h"
#include "Array.h"

int main() {
	DataStc* a = (DataStc*)new Array(10);
	std::vector<int> v = { 1,2,3 };
	a->extend(v);
	a->sort_increasing();
}