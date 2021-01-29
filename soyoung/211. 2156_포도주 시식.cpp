//https://www.acmicpc.net/problem/2156
//2516KB, 4ms

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> wine;

int drink()
{
	//선택함(0), 선택안함(1)
	vector<vector<int>> sum(n + 1, vector<int>(2, 0));
	sum[1][0] = sum[2][1] = wine[1];
	sum[2][0] = wine[1] + wine[2];

	for (int i = 3; i <= n; i++)
	{
		sum[i][0] = max(sum[i - 2][1] + wine[i - 1] + wine[i], sum[i - 2][0] + wine[i]);
		sum[i][1] = max(sum[i - 1][0], sum[i - 1][1]);
	}

	return max(sum[n][0], sum[n][1]);
}

int main()
{
	cin >> n;

	wine.resize(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> wine[i];

	if (n == 1)
		cout << wine[n];
	else
		cout << drink();
}