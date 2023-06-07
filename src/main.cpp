#include <iostream>
#include <exception>
#include "Leksems.hpp"
using namespace std;
int main()
{
	try{
		while (cin)
		{
			cout << expression() << endl;
		}
		cin.get();
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