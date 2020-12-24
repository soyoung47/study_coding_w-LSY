//https://www.acmicpc.net/problem/2606

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> computer[101];
vector<bool> visit(101, false);
int cnt = -1;	//���̷��� �ɸ��� �Ǵ� ��ǻ���� ��

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
	//1�� ��ǻ�ͺ��� ����
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
	int n, m;	//��ǻ���� ��(n), ��ǻ�� ���� ��(m)
	cin >> n;
	cin >> m;

	//��Ʈ��ũ �󿡼� ���� ����� ��ǻ�� ��ȣ �� �Է¹ޱ�
	int a, b;	
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		computer[a].emplace_back(b);
		computer[b].emplace_back(a);
	}

	//���̷��� �ɸ��� ��ǻ���� �� ���
	//1. BFS
	BFS();
	
	//2. DFS
	DFS(1);

	cout << cnt;
}