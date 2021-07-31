#pragma once
#include <string>
#include <filesystem>
#include "Utils.h"

class CSVDataParser {
private:
	std::string output_file;
	std::string input_files_dir;
	Utils utils;
	std::vector <std::filesystem::path> working_files;
public:
	CSVDataParser(std::string input_files_dir, std::string output_file);
	void generate(std::vector<std::filesystem::path> files);
	std::map<std::string, std::string> process_file(std::filesystem::path file_path);
	std::vector<std::string> process_line(std::string line);
	std::string compute_value(std::string value, std::string unit);
};
