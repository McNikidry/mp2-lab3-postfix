#include <iostream>
#include <string>
#include "postfix.h"

using namespace std;

int main()
{
  string expression;
  TPostfix postfix;
  double res;

  setlocale(LC_ALL, "Russian");
  //cout << "������� �������������� ���������: ";
  //cin >> expression;
  //cout << expression << endl;
  cout << "�������������� ���������: " << postfix.GetInfix() << endl;
  postfix.ToPostfix();
  cout << "����������� �����: " << postfix.GetPostfix() << endl;
  res = postfix.Calculate();
  cout << res << endl;

  return 0;
}
