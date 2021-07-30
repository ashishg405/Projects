#include "FileWatcher.h"
#include <iostream>

FileWatcher::FileWatcher(std::filesystem::path watch_path)
{
	path_to_watch = watch_path;
}

template<class...Types> void f(Types&...);

void FileWatcher::_register_expr(std::regex expr, void callback())
{
	while (true)
	{
		std::filesystem::directory_iterator dir_iter = std::filesystem::directory_iterator(path_to_watch);
		for (const auto& entry : dir_iter)
		{
			if (entry.is_regular_file())
			{
				if (std::regex_match(entry.path().generic_string(), expr))
				{
					callback(entry.path());
					std::filesystem::rename(entry.path(), entry.path() / ".processed");
				}
			}
		}
		std::this_thread::sleep_for(std::chrono::seconds(3));
	}
}

void FileWatcher::register_expr(std::string expr, void callback(Types&...))
{
	std::regex reg_exp(expr);
	std::thread t([this, reg_exp, callback] {this->_register_expr(reg_exp, callback);});
	auto it = exprs.find(expr);
	if (it == exprs.end())
		exprs.insert(std::pair<std::string, std::thread>(expr, std::move(t)));
	else
		std::cout << "The expression " << expr << " already has a thread running!";
}
