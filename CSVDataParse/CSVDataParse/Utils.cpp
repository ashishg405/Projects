#include "Utils.h"
#include <iostream>

Utils::Utils(){}
void Utils::print_vector(std::vector<std::string> v, std::string name)
{
	std::cout << name << std::endl;
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << " ";
	}
	std::cout << "\n";
}

std::string Utils::trim(std::string s)
{
	std::string out = "";
	int count1 = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ' || s[i] == '\n')
		{
			count1++;
		}
		else
			break;
	}
	int count2 = s.size() - 1;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] == ' ' || s[i] == '\n')
		{
			count2--;
		}
		else
			break;
	}
	for (int i = count1; i <= count2; i++)
	{
		out += s[i];
	}
	return out;
}

void Utils::print_map(std::map<std::string, std::vector<std::string>> m, std::string name)
{
	std::map<std::string, std::vector<std::string>>::iterator it = m.begin();
	while (it != m.end())
	{
		std::cout << it->first << " " << std::endl;
		print_vector(it->second);
		it++;
	}
}

std::vector<std::string> Utils::split(std::string line, char c)
{
	std::vector<std::string> vector;
	for (int i = 0; i < line.size(); i++)
	{
		std::string val = "";
		while (line[i] != c)
		{
			val += line[i];
			i++;
		}
		vector.push_back(val);
	}
	return vector;
}

bool Utils::vector_contains(std::vector<std::string> search_space, std::string element)
{
	for (std::string x : search_space)
	{
		if (x == element)
			return true;
	}
	return false;
}


bool Utils::map_contains(std::map<std::string, std::vector<std::string>> search_space, std::string key)
{
	std::map<std::string, std::vector<std::string>>::iterator it;
	it = search_space.find(key);
	if (it != search_space.end())
		return true;
	else
		return false;
}

bool Utils::map_contains2(std::map<std::string, std::string> search_space, std::string key)
{
	std::map<std::string, std::string>::iterator it;
	it = search_space.find(key);
	if (it != search_space.end())
		return true;
	else
		return false;
}
