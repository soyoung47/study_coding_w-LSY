#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<memory.h>
using namespace std;

int N;
long long ans;
long long X[1001], Y[1001];
bool visit[1001];
vector<pair<int, long long>> v[1001];	// [(from/to), cost]

void prim()
{
	priority_queue<pair<long long, int>, vector< pair<long long, int>>, greater<pair<long long, int>>> pq;

	visit[1] = true;

	for (int x = 0; x < v[1].size(); x++)
	{
		int next = v[1][x].first;
		long long next_cost = v[1][x].second;

		pq.push(make_pair(next_cost, next));
	}

	while (!pq.empty())
	{
		int cur = pq.top().second;
		long long cur_cost = pq.top().first;
		pq.pop();

		if (visit[cur])	continue;
		visit[cur] = true;
		ans += cur_cost;

		for (int y = 0; y < v[cur].size(); y++)
		{
			int next = v[cur][y].first;
			long long next_cost = v[cur][y].second;

			pq.push(make_pair(next_cost, next));
		}
	}
}
long long cal(int from, int to)
{
	long long new_x, new_y;

	new_x = X[to] - X[from];
	new_y = Y[to] - Y[from];

	return (new_x * new_x + new_y * new_y);
}
int main(int argc, char** argv)
{
	int test_case;
	int t;
	cin >> t;

	for (test_case = 1; test_case <= t; ++test_case)
	{
		memset(X, 0, sizeof(X));
		memset(Y, 0, sizeof(Y));
		memset(visit, false, sizeof(visit));
		for(int k=0; k<1001; k++)
			v[k].clear();
		ans = 0;
		
		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> X[i];
		for (int j = 0; j < N; j++)
			cin >> Y[j];

		double E;
		cin >> E;

		for (int a = 0; a < N; a++)
		{
			for (int b = 0; b < N; b++)
			{
				long long cost = cal(a, b);
				v[a].push_back(make_pair(b, cost));
				v[b].push_back(make_pair(a, cost));
			}			
		}
		
		prim();

		long long answer = E * ans + 0.5;

		cout << "#" << test_case << " " << answer << "\n";

	}
	return 0;
}