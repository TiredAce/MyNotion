## [Codeforces Round #843 (Div. 2)](https://codeforces.com/contest/1775)

>[A1. Gardener and the Capybaras](#A1)

<h3 id = "A1"> A1. Gardener and the Capybaras</h3>

**题意**：给定一个字符串`S`，字符串由字符`a`和`b`组成，要求将字符串`S`切割为三段`A`、`B`、`C`，满足$a \le b$ 且$c \le b$，或满足$a \ge b$ 且$c \ge b$。

输入字符串，要求输出切割方案，如果切割不了输出`:`。

**思路**：考虑字典序最小的情况为`a`，因此只要`B`字符串为`a`，那么就能保证`A`和`C`一定大于等于字符串`B`。如果`B`无法为`a`，那么也就是说明字符串中间一段不存在字符`a`，那么只要让`A`等于开头的字符，`C`等于末尾的字符就能保证满足条件。

**Code（C++）**

```c++
inline void sol1()
{
    string str;
    cin >> str;
    int t = -1;
    for (int i = 1; i < str.size() - 1; i ++)
    {
    	if (str[i] == 'a')
    	{
    		t = i;
    		break;
    	}
    }
    if (t == -1)
    {
    	cout << str[0] << " ";
    	for (int i = 1; i < str.size() - 1; i ++) cout << str[i];
    	cout << " " << str[str.size() - 1] << endl;
    }
    else
    {
    	for (int i = 0; i < t; i ++) cout << str[i];
    	cout << " a ";
    	for (int i = t + 1; i < str.size(); i ++) cout << str[i];
    	cout << endl;
    }
}
```

<h3 id = "A2" > A2. Gardener and the Capybaras (hard version) </h3>

