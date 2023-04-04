#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

const int N = 1e5 + 10;

char str[N], n;

int cal(int a, int b, char op)
{
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '/') return a / b;
    if (op == '*') return a * b;
}

int suf_cal(char str[])
{
    stack<int> st;
    for (int i = 0; str[i] != '\0'; i ++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            int num = 0;
            while (str[i] >= '0' && str[i] <= '9') 
				num = num * 10 + (str[i ++] - '0');
            i --;
            st.push(num);
        }
        else if (str[i] == ' ') continue;
        else
        {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            st.push(cal(a, b, str[i]));
        }
    }
    return st.top();
}


int main()
{
    cin.get(str, N).get();
    int ans = suf_cal(str);
    cout << ans << endl;
    return 0;
}
