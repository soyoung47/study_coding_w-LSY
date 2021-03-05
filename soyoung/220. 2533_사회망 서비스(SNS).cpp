//https://www.acmicpc.net/problem/2533

/***Solution 2***/
//108308KB, 1592ms

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> edge;
vector<vector<int>> dp;

void go(int cur)
{
	dp[cur][0] = 0, dp[cur][1] = 1;

	for (int next : edge[cur])
	{
		if (dp[next][0] == -1)
		{
			go(next);
			dp[cur][0] += dp[next][1];
			dp[cur][1] += min(dp[next][0], dp[next][1]);
		}
	}
}

int main()
{
	int n, u, v;
	cin >> n;

	edge.resize(n + 1);
	dp.assign(n + 1, vector<int>(2, -1));

	for (int i = 1; i < n; i++)
	{
		cin >> u >> v;
		edge[u].emplace_back(v);
		edge[v].emplace_back(u);
	}

	go(1);

	cout << min(dp[1][0], dp[1][1]);
}


/***Solution 1***/
//113072KB, 1616ms

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> edge;
vector<vector<int>> dp;

//현재 노드, 이전 노드, 선택 여부
int go(int cur, int pre, int state)
{
	int& tmp = dp[cur][state];

	if (tmp != -1)	return tmp;

	int ans = 0, next, goNext1, goNext2;
	if (state == 0)	//현재 노드가 얼리어답터가 아닌 경우
	{
		for (int i = 0; i < edge[cur].size(); i++)
		{
			next = edge[cur][i];
			if (next == pre)	continue;
			ans += go(next, cur, 1);	//인접한 노드: 얼리어답터 O
		}

		return tmp = ans;
	}
	else	//현재 노드가 얼리어답터인 경우
	{
		for (int i = 0; i < edge[cur].size(); i++)
		{
			next = edge[cur][i];
			if (next == pre)	continue;
			
			goNext1 = go(next, cur, 0);
			goNext2 = go(next, cur, 1);
			
			ans += min(goNext1, goNext2);	//인접한 노드: 얼리어답터 O or X
		}

		return tmp = ans + 1;
	}
}

int main()
{	
	int n, u, v;
	cin >> n;

	edge.resize(n + 1);
	dp.assign(n + 1, vector<int>(2, -1));
		
	for (int i = 1; i < n; i++)
	{
		cin >> u >> v;
		edge[u].emplace_back(v);
		edge[v].emplace_back(u);
	}

	cout << min(go(1, 0, 0), go(1, 0, 1));
}