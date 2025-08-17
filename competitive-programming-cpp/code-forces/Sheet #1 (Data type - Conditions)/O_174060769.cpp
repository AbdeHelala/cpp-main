#include<bits/stdc++.h>
using namespace std;
int
main ()
{
  string equation;
  cin >> equation;
  int operInd;
  char charOPerator;
  string num1, num2;
  int num1INT, num2INT;
 
  for (int i = 0; i <= equation.size () - 1; i++)
    {
      if (equation[i] == '+' || equation[i] == '-' || equation[i] == '*'
	  || equation[i] == '/')
	{
	  operInd = i;
	  charOPerator = equation[i];
	  break;
	}
    }
  num1 = equation.substr (0, operInd);
  num2 = equation.substr (operInd + 1);
  stringstream ss1;
  ss1 << num1;
  ss1 >> num1INT;
  stringstream ss2;
  ss2 << num2;
  ss2 >> num2INT;
 
  switch (charOPerator)
    {
    case '+':
      cout << num1INT + num2INT << endl;
      break;
    case '-':
      cout << num1INT - num2INT << endl;
      break;
    case '*':
      cout << num1INT * num2INT << endl;
      break;
    case '/':
      cout << num1INT / num2INT << endl;
      break;
 
    }
 
  return 0;
}