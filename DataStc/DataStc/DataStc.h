#pragma once
#include<iostream>
#include <vector>
class DataStc {
public: 
    DataStc();
    virtual void extend(std::vector<int> v);
    virtual void add(int k);
    virtual void remove(int k);
    virtual void sort_increasing();
    virtual void sort_decreasing();
};