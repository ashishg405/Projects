#pragma once
#include <string>
#include <filesystem>
#include "Utils.h"

class CSVDataParser {
private:
	std::string output_file;
	std::string input_files_dir;
	Utils utils;
public:
	void test(std::filesystem::path p);
	CSVDataParser(std::string input_files_dir, std::string output_file);
	void generate(std::vector<std::filesystem::path> files);
	std::vector<std::string> split(std::string, char);
	void print(std::vector<std::string> v);
	std::map<std::string, std::string> process_file(std::filesystem::path file_path);
	std::vector<std::string> process_line(std::string line);
	std::string compute_value(std::string value, std::string unit);
};
