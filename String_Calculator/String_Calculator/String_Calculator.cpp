#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
using namespace std;

float number()
{
	int res = 0;
	for (;;)
	{
		char c = cin.get();
		if (c >= '0' && c <= '9')
			res = res * 10 + c - '0';
		else
		{
			cin.putback(c);
			return res;
		}
	}
}

float expr();

float dug()
{
	char c = cin.get();
	if (c == '(')
	{
		float x = expr();
		cin.get();
		return x;
	}
	else
	{
		cin.putback(c);
		return number();
	}
}

float factor()
{
	float x = dug();
	for (;;)
	{
		char c = cin.get();
		switch (c)
		{
		case '*':
			x *= dug();
			break;
		case '/':
			x /= dug();
			break;
		default:
			cin.putback(c);
			return x;
		}
	}
}

float expr()
{
	float x = factor();
	for (;;)
	{
		char c = cin.get();
		switch (c)
		{
		case '+':
			x += factor();
			break;
		case '-':
			x -= factor();
			break;
		default:
			cin.putback(c);
			return x;
		}
	}
}


int main()
{
	cout << "Example: ";
	float res = expr();
	cout << "Result: " << res << endl;
}
