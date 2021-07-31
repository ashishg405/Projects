#include "CSVDataParser.h"
#include <fstream>
#include <sstream>
#include <map>
#include <iterator>
#include <iostream>
#include <vector>
#include <set>
#include "FileWatcher.h"
#include <functional>

namespace fs = std::filesystem;

CSVDataParser::CSVDataParser(std::string _input_files_dir, std::string _output_file)
{
	FileWatcher *a = new FileWatcher(fs::path(_input_files_dir));
	std::string start("(.*)\.(csv)");
	std::string end("(.*)\.(done)");
	a->register_expr(start, [this](fs::path disc_file) {std::cout << "File discovered! " << disc_file << "\n"; this->working_files.push_back(disc_file); std::cout << "File processed! " << disc_file << "\n"; });
	a->register_expr(end, [this](fs::path disc_file) {std::cout << "File discovered! " << disc_file << "\n"; this->generate(this->working_files); });
	output_file = _output_file;
	input_files_dir = _input_files_dir;
	utils = Utils::Utils();
}

std::string CSVDataParser::compute_value(std::string value, std::string unit)
{
	if (unit == "inch")
	{
		std::stringstream convert(value);
		float x, y;
		convert >> x;
		y = x * 25.4;
		std::ostringstream str;
		str << y;
		std::string updated_value_mm = str.str();
		return updated_value_mm;
	}
	else
		return value;
}

std::vector<std::string> CSVDataParser::process_line(std::string line)
{
	auto temp_line = utils.trim(line);
	std::cout << "Line trimmed" << "\n";
	return utils.split(temp_line, ';');
	std::cout << "Line split" << "\n";
}


std::map<std::string, std::string> CSVDataParser::process_file(std::filesystem::path file_path)
{
	std::cout << "Processing File" << file_path << "\n";
	std::ifstream ifs(file_path);
	std::string first_line;
	std::getline(ifs, first_line, '\n');
	std::string second_line;
	std::getline(ifs, second_line, '\n');
	std::string third_line;
	std::getline(ifs, third_line, '\n');

	auto headers = process_line(first_line);
	auto values = process_line(second_line);
	auto units = process_line(third_line);

	std::cout << "Processed rows" << file_path << "\n";

	while (units.size() < headers.size())
	{
		units.push_back("empty");
	}
	while (values.size() < headers.size())
	{
		values.push_back("empty");
	}
	std::map<std::string, std::string> data_entry;
	std::cout << headers.size() << " " << values.size() << " " << units.size() << "\n";
	for (int i = 0; i < headers.size(); i++)
	{
		data_entry[headers[i]] = compute_value(values[i], units[i]);
	}
	std::cout << "Processed File" << "\n";
	return data_entry;	
}

void CSVDataParser::generate(std::vector<fs::path> files)
{
	std::cout << "input_files_dir " << input_files_dir << "\n";
	std::map<std::string, std::vector<std::string>> tool_categories_map;
	std::set<std::string> union_headers;
	std::vector<std::map<std::string, std::string>> data_entries;
	for (auto& entry : files)
	{
		auto data_entry = process_file(entry);
		data_entries.push_back(data_entry);
		auto it = data_entry.begin();
		while (it != data_entry.end())
		{
			union_headers.insert(it->first);
			it++;
		}
	}
	std::cout << "Collected Union Headers" << "\n";
	for (auto header : union_headers)
	{
		std::cout << "Processing header " << header << "\n";
		if (!utils.map_contains(tool_categories_map, header))
			tool_categories_map[header] = std::vector<std::string>();
		for (auto data_entry : data_entries)
		{
			if (utils.map_contains2(data_entry, header))
				tool_categories_map[header].push_back(data_entry[header]);
			else
				tool_categories_map[header].push_back("Not Applicable");
		}
	}
	std::ofstream output;
	output.open(output_file);
	for (auto header:union_headers)
	{
		output << header << ";";
	}
	output << "\n";
	for (int j = 0; j < data_entries.size(); j++)
	{
		for (auto header:union_headers)
		{
			output << tool_categories_map[header][j] << ";";
		}
		output << "\n";
	}
	output.close();
}
