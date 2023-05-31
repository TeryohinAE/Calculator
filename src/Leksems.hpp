#pragma once
struct Token
{
	Token(char symbol);
	Token(double num);

	char type;
	double value;
};
double expresion();