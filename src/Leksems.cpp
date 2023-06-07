#include "Leksems.hpp"
#include <exception>
#include"MyStreams.hpp"







double expression() {
	double left = term();
	Token t = get_token();

	while (t.type == '+' || t.type == '-')
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
			throw _exception();
		}
		t = get_token();
	}
	return left;
}



double term() {
	double left = primary();
	Token t = get_token();
	
	while (t.type == '*' || t.type == '/')
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
			throw _exception();
		}
		t = get_token();
	}
	return left;
}



double primary() {
	Token t = get_token();

	switch (t.type)
	{
	case '(': 
	{
		double d = expression();
		t = get_token;
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