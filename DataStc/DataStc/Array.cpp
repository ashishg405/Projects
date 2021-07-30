#include <iostream>
#include "Array.h"

	Array::Array(int given_size)
	{
		arr = new int[given_size];
		size = given_size;
		tail = -1;
		std::cout << "Created a new Array of size: " << size << "\n";
	}

	void Array::print()
	{
		std::cout << "Current array is: ";
		for (int i = 0; i < tail + 1; i++)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << "\n";
	}

	void Array::add(int a)
	{
		if (tail == size - 1)
		{
			std::cout << "Maximum capacity has been reached!\nDoubling the size!\n";
			size *= 2;
			int* new_arr = new int[size];
			for (int i = 0; i < tail + 1; i++)
			{
				new_arr[i] = arr[i];
			}
			arr = new_arr;
		}
		arr[++tail] = a;
		print();
	}

	void Array::remove(int b)
	{
		for (int j = b; j < tail; j++)
		{
			arr[j] = arr[j + 1];
		}
		tail--;
		print();
	}

	std::string Array::search(int c)
	{
		for (int i = 0; i < tail + 1; i++)
		{
			if (arr[i] == c)
			{
				return "true";
			}
		}
		return "false";
		std::cout << "\n";
	}


	void Array::sort_increasing()
	{
		for (int i = 0; i < tail; i++)
		{
			int flag = 0;
			for (int j = 0; j < tail - i; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
					flag = 1;
				}
			}
			if (flag == 0)
				break;
		}
		print();
	}

	void Array::sort_decreasing()
	{
		for (int i = 0; i < tail; i++)
		{
			int flag = 0;
			for (int j = 0; j < tail - i; j++)
			{
				if (arr[j] < arr[j + 1])
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
					flag = 1;
				}
			}
			if (flag == 0)
				break;
		}
		print();
	}

	void Array::extend(std::vector<int> v)
	{
		for (int x : v)
		{
			add(x);
		}
	}