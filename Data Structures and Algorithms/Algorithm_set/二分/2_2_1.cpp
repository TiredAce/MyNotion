#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

typedef pair<int, int> PII;

int n;
map<int, PII> mp;

int main()
{
    cin >> n;
    for (int i = 0; i * i<= n; i ++)
    {
        for (int j = i; j * j<= n; j ++)
        {
            if (mp.find(i * i + j * j) == mp.end()) mp[i * i + j * j] = {i, j};
        }
    }
    for (int i = 0; i * i * 4 <= n; i ++)
    {
        for (int j = i; j * j * 3 <= n; j ++)
        {
            if (mp.find(n - i * i - j * j) != mp.end())
            {
                auto t = mp[n - i * i - j * j];
                cout << i << " " << j << " " << t.first << " " << t.second << endl;
                return 0;
            }
        }
    }
}
