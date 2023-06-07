#include "MyStreams.hpp"
#include <exception>
#include <iostream>






Token::Token() {}

Token::Token(char symbol) {
	type = symbol;
}

Token::Token(double num) {
	type = NUM;
	value = num;
}






Token_stream::Token_stream() {}

Token Token_stream::get() {
	if (full) {											//Проверка буфера и вывод из него, если он полный
		full == false;
		return buffer;
	}

	char ch;
	std::cin >> ch;

	switch (ch)
	{
	case ';': case 'q':									//Символы для выхода
		return Token{ ch };

	case '(': case ')': case '+':						//Символы мат операций
	case '-': case '*': case '/':
		return Token{ ch };

	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		std::cin.putback(ch);
		double val;
		std::cin >> val;
		return Token{ val };
	}

	default:
		throw _exception();
	}
}

void Token_stream::putback(Token t) {
	if (full == false)
		throw _exception();
	buffer = t;
	full = true;
}