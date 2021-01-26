//https://www.acmicpc.net/problem/1463
//5924ms, 4ms

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int checkCount(int n)
{
	if (n == 1)	return 0;

	vector<int> v(n + 1, 0);
	v[2] = v[3] = 1;

	for (int i = 4; i <= n; i++)
	{
		v[i] = v[i - 1] + 1;

		if (i % 3 == 0)
			v[i] = min(v[i], v[i / 3] + 1);
		if (i % 2 == 0)
			v[i] = min(v[i], v[i / 2] + 1);
	}

	return v[n];
}

int main()
{
	int n;
	cin >> n;

	cout << checkCount(n);
}