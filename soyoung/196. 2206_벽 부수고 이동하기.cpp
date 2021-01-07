//https://www.acmicpc.net/problem/2206

#include <iostream>
#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;

int n, m;	//���� ũ��(����, ����)
int map[1001][1001];	//��
int dist[1001][1001][2];	//�̵��Ÿ�(���� �μ� ������ ����)
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int move()
{
	queue<tuple<int, int, int>> q;	//��ġ(x,y), �μ� ���� ����
	q.emplace(0, 0, 0);	//������(����: 1,1), �μ� ���� ����(0)
	dist[0][0][0] = 1;

	while (!q.empty())
	{
		int x, y, nx, ny, wall, cnt;
		x = get<0>(q.front());
		y = get<1>(q.front());
		wall = get<2>(q.front());
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)	continue;

			//��θ� ���� �� ��� ������Ʈ(���� �ν������� ���� ���� �������)
			if (map[nx][ny] == 0 && dist[nx][ny][wall] == 0)	
			{
				dist[nx][ny][wall] = dist[x][y][wall] + 1;
				q.emplace(nx, ny, wall);
			}
			//���� �μ� ���� ���� ��, ���� ������ �μ��� �̵� ��θ� �������� ���� ���: ���� �μ��� ���� �� ��� ������Ʈ
			if (wall == 0 && map[nx][ny] == 1 && dist[nx][ny][wall+1] == 0)	
			{
				dist[nx][ny][wall+1] = dist[x][y][wall] + 1;
				q.emplace(nx, ny, wall + 1);
			}
		}		
	}
	
	//�ִ� ��� ��ȯ, �Ұ����ϸ� -1 ��ȯ
	int a = n - 1, b = m - 1;	//������(n-1, m-1)
	if (dist[a][b][0] != 0 && dist[a][b][1] != 0)	//���� �μ��� �ʾ��� ���� �ν��� ���� ��� ��
		return min(dist[a][b][0], dist[a][b][1]);
	else if (dist[a][b][0] != 0)	//���� �μ��� �ʾ��� ���� ����� �ִٸ�, ��ȯ
		return dist[a][b][0];
	else if (dist[a][b][1] != 0)	//���� �ν��� ���� ����� �ִٸ�, ��ȯ
		return dist[a][b][1];
	else
		return -1;
}

int main()
{
	cin >> n >> m;

	//���� ���� �޾ƿ���
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf("%1d", &map[i][j]);
	}

	//�ִ� ��� �˻�
	int answer = move();	
	cout << answer;
}