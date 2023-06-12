#include <iostream>
#include <exception>
#include "Leksems.hpp"
#include <Windows.h>
using namespace std;
int main()
{
	try
	{
		SetConsoleOutputCP(1251);
		SetConsoleCP(1251);

		for (bool i = true; i == true; exit(i))
		{
			cout << expression() << endl;
		}

		return 0;
	}
	catch (_exception& e) {
		cerr << e.name << endl;
		cin.get();
		return 1;
	}
	catch (...) {
		cerr << "unknow error\n";
		cin.get();
		return 2;
	}
}