//https://www.acmicpc.net/problem/1260

#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, V;
vector<int> edge[1001];
bool visit[1001] = { false };

void DFS(int ind)
{
	visit[ind] = true;
	cout << ind << " ";

	for (int i = 0; i < edge[ind].size(); i++)
	{
		int next = edge[ind][i];
		if (visit[next])	continue;
		DFS(next);
	}
}

void BFS()
{	
	queue<int> q;
	q.push(V);

	while (!q.empty())
	{
		int ind = q.front();
		q.pop();

		if (visit[ind])	continue;
		
		visit[ind] = true;
		cout << ind << " ";

		for (int i = 0; i < edge[ind].size(); i++)
		{
			int next = edge[ind][i];
			if (!visit[next])
			{	q.push(next);	}
		}
	}
}

int main()
{	
	cin >> N >> M >> V;

	//간선 정보 입력 받기
	int a, b;;
	for (int i = 0; i < M; i++)
	{	
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	for (int i = 0; i < 1001; i++)
		sort(edge[i].begin(), edge[i].end());

	//DFS와 BFS 출력
	DFS(V);

	cout << "\n";	
	memset(visit, false, sizeof(visit));

	BFS();
}