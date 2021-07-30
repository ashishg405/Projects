#include "CSVDataParser.h"
#include "Utils.h"
#include<iostream>

void print(std::string x)
{
	std::cout << x << "\n";
}

int main()
{
	//CSVDataParser test = CSVDataParser::CSVDataParser("C:\\Users\\Asus\\Desktop\\Imp\\Intern work 2\\Tool_Databse_file", "C:\\Users\\Asus\\source\\repos\\CSVDataParse\\output.txt");
	//test.generate();
	int x = 5;
	std::cout << x << " " << &x << "\n";
	int* a = &x;
	std::cout << a << " " << *a << "\n";
	*a = 10;
	std::cout << x << " " << &x << "\n";
	std::cout << a << " " << *a << "\n";
	std::string y = "abc";
	std::string* ptr = &y;
	std::cout << ptr << " " << *ptr << "\n";
	std::cout << print << " " << &print;
	void (*abc) (std::string) = &print; //This is same as doing int *x;
	//abc = print;
	(*abc)("qqq");
	return 0;
}