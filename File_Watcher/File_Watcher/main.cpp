#include "FileWatcher.h"
#include <iostream>

int main()
{
	FileWatcher *a = new FileWatcher(std::filesystem::path("C:\\Users\\Asus\\Desktop\\Imp\\Intern work 2\\Tool_Databse_file"));
	std::string abcd ("(.*)\.csv");
	a->register_expr(abcd, [](std::filesystem::path x) {std::cout << x << " csv\n"; });
	std::this_thread::sleep_for(std::chrono::seconds(1000));
	return 0;
}
