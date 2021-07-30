#pragma once
#include <filesystem>
#include <regex>
#include <thread>
#include <chrono>
#include <map>

class FileWatcher
{
private:
	std::map<std::string, std::thread> exprs;
	std::filesystem::path path_to_watch;
	void _register_expr(std::regex expr, void callback(std::filesystem::path));
public:
	FileWatcher(std::filesystem::path watch_path);
	void register_expr(std::string expr, void callback(std::filesystem::path));
};

