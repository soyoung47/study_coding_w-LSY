//https://www.acmicpc.net/problem/7569

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

#define MAX 101

int n, m, h;	//������ ����, ����, ����
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int dz[2] = { 1, -1 };
int	tomato[MAX][MAX][MAX] = { 0 };
bool visit[MAX][MAX][MAX] = { false };
queue<tuple<int, int, int, int>> q;	//���� ��ġ(x,y,z), �����ϼ�

int day_tomato(int total)
{
	int x, y, z, nx, ny, nz, day = 0;
	while (!q.empty())
	{
		x = get<0>(q.front());
		y = get<1>(q.front());
		z = get<2>(q.front());
		day = get<3>(q.front());
		q.pop();

		if (visit[x][y][z])	continue;

		visit[x][y][z] = true;
		total--;

		//���� ���ڿ��� �����¿�
		for (int j = 0; j < 4; j++)
		{
			nx = x + dx[j];
			ny = y + dy[j];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)	continue;
			if (!visit[nx][ny][z] && tomato[nx][ny][z] == 0)
			{
				tomato[nx][ny][z] = 1;
				q.emplace(nx, ny, z, day + 1);
			}
		}

		//��, �Ʒ��� ���ڿ���
		for (int i = 0; i < 2; i++)
		{
			nz = z + dz[i];
			if (nz < 0 || nz >= h)	continue;
			if (!visit[x][y][nz] && tomato[x][y][nz] == 0)
			{
				tomato[x][y][nz] = 1;
				q.emplace(x, y, nz, day + 1);
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
	cin >> m >> n >> h;

	//��ü �丶�� ���� ���� �޾ƿ���
	int tmp = 0, total = 0;
	for (int z = 0; z < h; z++)
	{
		for (int x = 0; x < n; x++)
		{
			for (int y = 0; y < m; y++)
			{
				cin >> tmp;
				tomato[x][y][z] = tmp;

				//���� �丶����� ���������� �ϰ�, �丶���� ���� �ľ�
				if (tmp == -1)	continue;
				if (tmp == 1)
					q.emplace(x, y, z, 0);
				total++;
			}
		}
	}

	int answer = day_tomato(total);
	cout << answer;

}