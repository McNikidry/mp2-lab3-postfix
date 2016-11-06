#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include "stack.h"
#include<iostream>

using namespace std;


class TPostfix
{
	string infix;
	string postfix;
public:
	TPostfix(string s)
	{
		infix = s;
		postfix = s;//�������������� ��������
	}
	string GetInfix() { return infix; }
	string GetPostfix() { return postfix; }
	int GetSizeInfix() { return infix.length(); }
	int GetSizePostfix(){ return postfix.length(); }
	string ToPostfix();
	double Calculate(); // ���� ����������, ���������� �� ����������� �����
	int Priort(char c); // ������ ������� ������� ��� ���������� ����������� 
};

#endif
