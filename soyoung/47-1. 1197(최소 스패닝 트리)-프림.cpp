#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int V, E, ans;
vector<pair<int, int>> v[100001];
bool visit[10001];

void prim()
{
	visit[1] = true;

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

	//1번부터 시작
	int size = v[1].size();
	for (int k = 0; k < size; k++)
	{
		int next = v[1][k].first;
		int next_cost = v[1][k].second;

		pq.push(make_pair(next_cost,next));
	}

	//프림 알고리즘
	while (!pq.empty())
	{
		int cur = pq.top().second;
		int cur_cost = pq.top().first;
		pq.pop();

		if (visit[cur])	continue;

		visit[cur] = true;
		ans += cur_cost;

		//다음 정점 우선순위큐에 push
		int size = v[cur].size();
		for (int a = 0; a < size; a++)
		{
			int next = v[cur][a].first;
			int next_cost = v[cur][a].second;

			pq.push(make_pair(next_cost, next));
		}
	}
}
int main()
{
	ans = 0;

	cin >> V >> E;

	int from, to, cost;
	for (int i = 0; i < E; i++)
	{
		cin >> from >> to >> cost;
		v[from].push_back(make_pair(to, cost));
		v[to].push_back(make_pair(from, cost));
	}

	prim();

	cout << ans;
}