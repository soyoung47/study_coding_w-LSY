//https://www.acmicpc.net/problem/2565

/***Solution 2: DP***/
//2016kb, 0ms

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main()
{
	int n, to, from, ind, pos, ans = 0;
	cin >> n;

	vector<pair<int, int>> pole;	//전봇대 연결 정보(a 전봇대, b 전봇대)
	vector<int> dp(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> from >> to;
		pole.emplace_back(from, to);
	}

	sort(pole.begin(), pole.end());

	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;

		for (int j = 0; j < i; j++)
		{
			if (pole[i].second > pole[j].second)
				dp[i] = max(dp[i], dp[j] + 1);
		}

		ans = max(ans, dp[i]);
	}

	cout << n - ans;
}


/***Solution 1: lower_bound***/
//2016kb, 0ms

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main()
{
	int n, to, from, ind, pos, ans = 0;
	cin >> n;

	vector<pair<int, int>> pole;	//전봇대 연결 정보(a 전봇대, b 전봇대)
	vector<int> select;	//선택된 b 전봇대 위치 번호

	for (int i = 0; i < n; i++)
	{
		cin >> from >> to;
		pole.emplace_back(from, to);
	}

	sort(pole.begin(), pole.end());

	for (int i = 0; i < n; i++)
	{
		pos = pole[i].second;
		ind = lower_bound(select.begin(), select.end(), pos) - select.begin();

		if (ind == select.size())
			select.emplace_back(pos);
		else
			select[ind] = pos;
	}

	cout << n - select.size();
}