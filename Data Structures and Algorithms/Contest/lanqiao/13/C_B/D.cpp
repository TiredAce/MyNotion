#include <iostream>
#include <algorithm>

using namespace std;

int n;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		cout << max(2 * (i - 1), 2 * (n - i)) << endl;
	}
	return 0;
}
