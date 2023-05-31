#include "Leksems.hpp"
#include <exception>

Token::Token(double num)
{
}

double expresion() {
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
			return left;
		}
		
		t = get_token();
	}
	throw _exception();
}