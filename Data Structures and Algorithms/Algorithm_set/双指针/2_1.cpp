#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
string str;

int main()
{
	cin >> n >> str;
	int ans = 0;
	str = " "+ str;
	for (int i = 1; i <= n; i ++)
	{
		if (str[i] != 'x') continue;
		else
		{
			int j = i + 1;
			while (j <= n && str[j] == 'x') j ++;
			ans += max(0, j - i - 2);
			i = j;
		}
	}
	cout << ans << endl;
	return 0;
}
