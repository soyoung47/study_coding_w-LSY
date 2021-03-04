//https://www.acmicpc.net/problem/11053

/***Solution 1: lower_bound***/
//2016kb, 0ms

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, elemt, ind;
	vector<int> a;	//���õ� elemt(����)�� index�� �����.

	cin >> n;

	while (n--)
	{
		cin >> elemt;

		ind = lower_bound(a.begin(), a.end(), elemt) - a.begin();	//����a �� ���Ұ����� ū ���� ���� ���� ��ġ��ȯ

		if (ind == a.size())
			a.push_back(elemt);
		else
			a[ind] = elemt;
	}

	cout << a.size();
}

/***Solution 2: DP***/
//2016kb, 0ms

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, ans = 0;
	cin >> n;

	vector<int> a(n, 0);
	vector<int> dp(n, 0);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[i]);
	}

	cout << ans;
}
