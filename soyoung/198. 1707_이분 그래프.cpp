//https://www.acmicpc.net/problem/1707
//6232KB, 800ms

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> group;
vector<vector<int>> graph;
bool check(int start, int v)
{
	queue<int> q;
	q.emplace(start);
	group[start] = 1;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int next : graph[cur])
		{
			if (group[next] == 0)	//방문한 적이 없는 정점이면, 지금과 다른 그룹으로 지정
			{
				group[next] = -group[cur];
				q.emplace(next);
			}
			else if (group[next] == group[cur])	//방문한 적이 있는 정점인 경우, 지금과 같은 그룹이라면 이분 그래프가 아님
				return false;
		}
	}

	return true;
}

int main()
{
	int k;	//테스트 케이스 개수
	cin >> k;

	for (int t = 0; t < k; t++)
	{
		int v, e;	//그래프의 정점 개수, 간선 개수
		cin >> v >> e;

		group.resize(v + 1, 0);	//그룹: 1, -1

		//그래프의 정보 받아오기
		graph.resize(v + 1);
		for (int i = 0; i < e; i++)
		{
			int a, b;
			cin >> a >> b;

			graph[a].emplace_back(b);
			graph[b].emplace_back(a);
		}

		bool answer = true;
		for (int i = 1; i <= v; i++)
		{
			if (!answer)	break;

			if (group[i] == 0)
				answer = check(i, v);
		}

		cout << (answer ? "YES" : "NO") << "\n";

		graph.clear();
		group.clear();
	}

	return 0;
}