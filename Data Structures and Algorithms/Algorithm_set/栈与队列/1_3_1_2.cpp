#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <map>

using namespace std;

const int N = 1e5 + 10;

map<char, int> prior;
char str[N];
stack<char> ops;
stack<int> nums;

void init()
{
	prior['('] = 0;
	prior['+'] = 1;
	prior['-'] = 1;
	prior['*'] = 2;
	prior['/'] = 2;
}

void eval()
{
	int b = nums.top();
	nums.pop();
	int a = nums.top();
	nums.pop();
	char op = ops.top();
	ops.pop();
	if (op == '+') nums.push(a + b);
	if (op == '-') nums.push(a - b);
	if (op == '*') nums.push(a * b);
	if (op == '/') nums.push(a / b); 
}

int main()
{
	init();
	cin >> str;
	for (int i = 0; str[i] != '\0'; i ++)
	{
		if (str[i] == '(') ops.push('(');
		else if (str[i] == ')')
		{
			while (ops.top() != '(') eval();
			ops.pop();	
		}	
		else if (str[i] >= '0' && str[i] <= '9')
		{
			int num = 0;
			while (str[i] >= '0' && str[i] <= '9')
				num = num * 10 + (str[i ++] - '0');
			nums.push(num);
			i --;
		}
		else
		{
			while (ops.size() && prior[ops.top()] >= prior[str[i]]) eval();
			ops.push(str[i]);
		}
	}
	while (ops.size()) eval();
	cout << nums.top() << endl;
	return 0;
}
