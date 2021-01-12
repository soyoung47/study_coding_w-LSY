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
			if (group[next] == 0)	//�湮�� ���� ���� �����̸�, ���ݰ� �ٸ� �׷����� ����
			{
				group[next] = -group[cur];
				q.emplace(next);
			}
			else if (group[next] == group[cur])	//�湮�� ���� �ִ� ������ ���, ���ݰ� ���� �׷��̶�� �̺� �׷����� �ƴ�
				return false;
		}
	}

	return true;
}

int main()
{
	int k;	//�׽�Ʈ ���̽� ����
	cin >> k;

	for (int t = 0; t < k; t++)
	{
		int v, e;	//�׷����� ���� ����, ���� ����
		cin >> v >> e;

		group.resize(v + 1, 0);	//�׷�: 1, -1

		//�׷����� ���� �޾ƿ���
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