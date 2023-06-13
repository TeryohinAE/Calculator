#include "Leksems.hpp"
#include <exception>
#include"MyStreams.hpp"
#include <iostream>
#include <algorithm>


Token_stream ts;





void exit(bool& i)
{
	bool j = false;
	while (j == false)
	{
		std::cout << "Вы хотите продолжить? (yes/no)" << std::endl;
		std::string answer;
		std::cin >> answer;
		std::transform(answer.begin(), answer.end(), answer.begin(), tolower);

		if (answer == "no") {
			i = false;
			j = true;
		}
		else if (answer == "yes") {
			i = true;
			j = true;
			ts.clear_buffer();
		}
		else
			std::cout << "Неправильный ответ, введите ответ снова" << std::endl;
	}
}







double expression() {
	double left = term();
	Token t = ts.get();

	while (true)
	{
		switch (t.type)
		{
		case '+':
			left += term();
			break;

		case '-':
			left -= term();
			break;

		default:
			ts.putback(t);
			return left;
		}
		t = ts.get();
	}
	throw _exception();
}



double term() {
	double left = primary();
	Token t = ts.get();
	
	while (true)
	{
		switch (t.type)
		{
		case '*':
			left *= primary();
			break;

		case '/': {
			double d = primary();
			if (d == 0)
				_exception();
			left /= d;
			break;
		}

		default:
			ts.putback(t);
			return left;
		}
		t = ts.get();
	}
	throw _exception();
}



double primary() {
	Token t = ts.get();

	switch (t.type)
	{
	case '(': 
	{
		double d = expression();
		t = ts.get();
		if (t.type != ')')
			throw _exception();
		return d;
	}

	case NUM:
		return t.value;

	default:
		throw _exception();
	}
}