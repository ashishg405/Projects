#pragma once
#include <filesystem>
#include <regex>
#include <thread>
#include <chrono>
#include <map>
#include <functional>

class FileWatcher
{
private:
	std::map<std::string, std::thread> exprs;
	std::filesystem::path path_to_watch;
	void _register_expr(std::regex expr, std::function<void(std::filesystem::path)> callback);
public:
	FileWatcher(std::filesystem::path watch_path);
	void register_expr(std::string expr, std::function<void(std::filesystem::path)> callback);
};

