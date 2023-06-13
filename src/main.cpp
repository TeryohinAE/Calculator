#include <iostream>
#include <exception>
#include "Leksems.hpp"
#include <Windows.h>
int main()
{
	try
	{
		SetConsoleOutputCP(1251);
		SetConsoleCP(1251);

		for (bool i = true; i == true; exit(i))
		{
			std::cout << "Введите пример для решения, при этом закончите его символом равно,\n" <<
			"точкой с запятой или английской буквой \"q\"" << std::endl;
			std::cout << expression() << std::endl;
		}

		return 0;
	}
	catch (_exception& e) {
		std::cerr << e.name << std::endl;
		std::cin.get();
		return 1;
	}
	catch (...) {
		std::cerr << "unknow error\n";
		std::cin.get();
		return 2;
	}
}