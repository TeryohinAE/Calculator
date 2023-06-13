#pragma once


#define NUM 8						//Используется для обозначения что данная лексема является числом


struct Token
{
	Token();
	Token(char symbol);
	Token(double num);

	char type = '0';
	double value = 0;
};


class Token_stream {
public:
	Token_stream();
	
	Token get();
	void putback(Token t);
	void clear_buffer();

private:
	bool full {false};
	Token buffer;
};