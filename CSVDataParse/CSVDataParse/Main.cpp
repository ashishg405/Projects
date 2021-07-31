#include "CSVDataParser.h"
#include "Utils.h"
#include <iostream>
#include <thread>
#include <chrono>

void print(std::string x)
{
	std::cout << x << "\n";
}

int main()
{
	CSVDataParser test = CSVDataParser::CSVDataParser("C:\\Users\\Asus\\Desktop\\Imp\\Intern work 2\\GG", "C:\\Users\\Asus\\source\\repos\\CSVDataParse\\output.txt");
	std::this_thread::sleep_for(std::chrono::seconds(10000));
	return 0;
}