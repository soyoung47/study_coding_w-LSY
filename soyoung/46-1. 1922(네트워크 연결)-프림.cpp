#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int N, M, ans;
bool visit[1001];
vector<pair<int, int>> v[100001];

void prim()
{
	//cost 오름차순
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	//1번부터 시작
	visit[1] = true;

	for (int a = 0; a < v[1].size(); a++)
	{
		int next = v[1][a].first;
		int next_cost = v[1][a].second;

		pq.push(make_pair(next_cost, next));
	}

	while (!pq.empty())
	{
		int cur = pq.top().second;
		int cur_cost = pq.top().first;
		pq.pop();

		if (visit[cur])	continue;

		visit[cur] = true;
		ans += cur_cost;

		for (int b = 0; b < v[cur].size(); b++)
		{
			int next = v[cur][b].first;
			int next_cost = v[cur][b].second;
			
			pq.push(make_pair(next_cost, next));
		}
	}
}
int main()
{
	ans = 0;
	cin >> N;
	cin >> M;

	int from, to, cost;
	for (int i = 0; i < M; i++)
	{
		cin >> from >> to >> cost;
		v[from].push_back(make_pair(to, cost));
		v[to].push_back(make_pair(from, cost));
	}

	prim();

	cout << ans;
}