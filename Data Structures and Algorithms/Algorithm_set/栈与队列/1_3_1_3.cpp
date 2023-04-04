#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <vector>
#include <map>

using namespace std;

const int N = 1e5 + 10;

map<char, int> prior;
char str[N];
char ans[N];
stack<char> ops;
stack<int> nums;
int idx = 0;

void init()
{
    prior['('] = 0;
    prior['+'] = 1;
    prior['-'] = 1;
    prior['*'] = 2;
    prior['/'] = 2;
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
            while (ops.top() != '(')
            {
                ans[idx ++] = ops.top();
                ops.pop();
            }
            ops.pop();
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            while (str[i] >= '0' && str[i] <= '9') ans[idx ++] = str[i ++];
            i --;
        }
        else
        {
            while (ops.size() && prior[ops.top()] >= prior[str[i]])
            {
                char op = ops.top();
                ops.pop();
                ans[idx ++] = op;
            }
            ops.push(str[i]);
        }
    }
    while (ops.size())
    {
        ans[idx ++] = ops.top();
        ops.pop();
    }
    for (int i = 0; str[i] != '\0'; i ++) cout << ans[i] << " ";
    return 0;
}
