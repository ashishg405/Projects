#pragma once
#include <vector>
#include <string>
#include <map>

class Utils
{
public:
	Utils();
	void print_vector(std::vector<std::string> v, std::string name = "name");
	std::string trim(std::string s);
	void print_map(std::map<std::string, std::vector<std::string>> m, std::string name = "map");
	std::vector<std::string> split(std::string line, char c);
	bool vector_contains(std::vector<std::string> search_space, std::string element);
	bool map_contains(std::map<std::string, std::vector<std::string>> search_space, std::string key);
	bool map_contains2(std::map<std::string, std::string> search_space, std::string key);
};

