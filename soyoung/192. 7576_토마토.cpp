//https://www.acmicpc.net/problem/7576

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int n, m;	//���� ũ��(����, ����)
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int day_tomato(vector<vector<int>>& tomato)
{
	vector<vector<bool>> visit(n, vector<bool>(m, false));
	queue<pair<pair<int, int>, int>> q;	//���� ��ġ(x,y), �����ϼ�
	
	//���� �丶����� ���������� �ϰ�, �丶���� ���� �ľ�
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (tomato[i][j] == -1)	continue;
			if (tomato[i][j] == 1)
				q.push({ { i,j }, 0 });
			total++;
		}
	}

	int x, y, nx, ny, day = 0;
	while (!q.empty())
	{
		x = q.front().first.first;
		y = q.front().first.second;
		day = q.front().second;
		q.pop();

		if (visit[x][y])	continue;

		visit[x][y] = true;
		total--;

		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)	continue;
			if (!visit[nx][ny] && tomato[nx][ny] == 0)
			{
				tomato[nx][ny] = 1;
				q.push({ { nx, ny }, day + 1 });
			}
		}
	}

	//�ּ� ���� �ϼ� ���, �丶�䰡 ��� ���� ���� ��� -1 ���
	if (total != 0)
		return -1;
	else
		return day;
}

int main()
{
	cin >> m >> n;	//����, ����

	//�丶�� ���� ���� �޾ƿ���
	vector<vector<int>> tomato(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> tomato[i][j];	
	}

	int answer = day_tomato(tomato);
	cout << answer;
}