#include "FileWatcher.h"
#include <iostream>

FileWatcher::FileWatcher(std::filesystem::path watch_path)
{
	path_to_watch = watch_path;
}

void FileWatcher::_register_expr(std::regex expr, std::function<void(std::filesystem::path)> callback)
{
	std::map<std::filesystem::path, int> store_path;
	while (true)
	{
		std::filesystem::directory_iterator dir_iter = std::filesystem::directory_iterator(path_to_watch);
		for (const auto& entry : dir_iter)
		{
			if (entry.is_regular_file())
			{
				if (std::regex_match(entry.path().generic_string(), expr))
				{
					auto it = store_path.find(entry.path());
					if (it == store_path.end())
					{
						store_path[entry.path()] = 1;
						callback(entry.path());
					}
				}
			}
		}
		std::this_thread::sleep_for(std::chrono::seconds(3));
	}
}

void FileWatcher::register_expr(std::string expr, std::function<void(std::filesystem::path)> callback)
{
	std::regex reg_exp(expr);
	auto it = exprs.find(expr);
	if (it == exprs.end())
	{
		std::thread t([this, reg_exp, callback] {this->_register_expr(reg_exp, callback); });
		exprs.insert(std::pair<std::string, std::thread>(expr, std::move(t)));
	}
	else
		std::cout << "The expression " << expr << " already has a thread running!";
}
