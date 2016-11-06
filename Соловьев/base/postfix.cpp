#include "postfix.h"
#include "stack.h"
#define max_size 50

string TPostfix::ToPostfix()
{
	int i;//счетчик

	int  len = GetSizeInfix(); // вычисляем размер длины строки

	char result[max_size];

	TStack<char> stack(len); //стек для хранения операция
	int count = 0;//счетчик для postfix

	for (i = 0; i < len; i++)
	{
		if (infix[i] != '+' && infix[i] != '-' && infix[i] != '*' && infix[i] != '/' && infix[i] != '(' && infix[i] != ')')
			result[count++] = infix[i];
		if (infix[i] == '(') stack.Push(infix[i]);
		if (infix[i] == ')')
		{
			while (stack.Top() != '(')
				result[count++] = stack.Pop();
			stack.Pop();
		}
		if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
		{
			if (stack.IsEmpty() || stack.Top() == '(') stack.Push(infix[i]);
			else if (Priort(infix[i]) > Priort(stack.Top())) stack.Push(infix[i]);
			else
			{
				while (!stack.IsEmpty() && Priort(infix[i]) <= Priort(stack.Top()))
					result[count++] = stack.Pop();
				stack.Push(infix[i]);
			}
		}
	}
	while (stack.IsEmpty() != true)
		result[count++] = stack.Pop();

	result[count] = '\0';

	postfix = result;

	return postfix;
}

double TPostfix::Calculate()
{
	int len = GetSizePostfix();

	TStack<double> stack(len);

	double c, c1;
	double k;

	double tmp[max_size];
	char tmp1[max_size];
	int flag;

	for (int i = 0; i < len; i++)
	{
		if (postfix[i] != '+' && postfix[i] != '-' && postfix[i] != '*' && postfix[i] != '/')
		{
			flag = 0;
			tmp1[i] = postfix[i];
			for (int j = 0; j < i; j++)
				if (postfix[i] == tmp1[j])
				{
					flag = 1;
					stack.Push(tmp[j]);
					break;
				}

			if (flag == 0)
			{
				cout << postfix[i] << "=" << " ";
				cin >> k;
				tmp[i] = k;
				stack.Push(k);
			}
		}
		else
		{
			if (postfix[i] == '+')
			{
				c = stack.Pop();
				c1 = stack.Pop();
				stack.Push(c1 + c);
			}
			if (postfix[i] == '-')
			{
				c = stack.Pop();
				c1 = stack.Pop();
				stack.Push(c1 - c);
			}
			if (postfix[i] == '/')
			{
				c = stack.Pop();
				c1 = stack.Pop();
				stack.Push(c1 / c);
			}
			if (postfix[i] == '*')
			{
				c = stack.Pop();
				c1 = stack.Pop();
				stack.Push(c1*c);
			}
		}

	}
	return stack.Pop();
}

int TPostfix::Priort(char c)
{
	if ((c == '/') || (c == '*')) return 2;
	if ((c == '+') || (c == '-')) return 1;
	if (c == '(') return 0;
	return -1;
}