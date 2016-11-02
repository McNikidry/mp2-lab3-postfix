#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include "stack.h"
#include<iostream>

using namespace std;

struct priority
{
	int pr;
	char name;
};

class TPostfix
{
	string infix;
	string postfix;
public:
	TPostfix(string s)
	{
		infix = s;
		postfix = s;//инициализируем постфикс
	}
	string GetInfix() { return infix; }
	string GetPostfix() { return postfix; }
	int GetSizeInfix() { return infix.length(); }
	int GetSizePostfix(){ return postfix.length(); }
	string ToPostfix();
	double Calculate(); // Ввод переменных, вычисление по постфиксной форме
	int Priort(char c); // вместо таблицы функция для вычисления приоритетов 
};

#endif
