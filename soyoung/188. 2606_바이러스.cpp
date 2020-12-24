//https://www.acmicpc.net/problem/2606

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> computer[101];
vector<bool> visit(101, false);
int cnt = -1;	//바이러스 걸리게 되는 컴퓨터의 수

void DFS(int cur)
{
	visit[cur] = true;
	cnt++;

	for (int i = 0; i < computer[cur].size(); i++)
	{
		int next = computer[cur][i];
		if (!visit[next])
			DFS(next);
	}
}

void BFS()
{
	//1번 컴퓨터부터 시작
	queue<int> q;
	q.push(1);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (visit[cur])	continue;

		visit[cur] = true;
		cnt++;

		for (int i = 0; i < computer[cur].size(); i++)
		{
			int next = computer[cur][i];
			if (!visit[next])
				q.push(next);
		}
	}
}

int main()
{
	int n, m;	//컴퓨터의 수(n), 컴퓨터 쌍의 수(m)
	cin >> n;
	cin >> m;

	//네트워크 상에서 직접 연결된 컴퓨터 번호 쌍 입력받기
	int a, b;	
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		computer[a].emplace_back(b);
		computer[b].emplace_back(a);
	}

	//바이러스 걸리는 컴퓨터의 수 출력
	//1. BFS
	BFS();
	
	//2. DFS
	DFS(1);

	cout << cnt;
}