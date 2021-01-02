//https://www.acmicpc.net/problem/7569

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

#define MAX 101

int n, m, h;	//상자의 세로, 가로, 개수
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int dz[2] = { 1, -1 };
int	tomato[MAX][MAX][MAX] = { 0 };
bool visit[MAX][MAX][MAX] = { false };
queue<tuple<int, int, int, int>> q;	//상자 위치(x,y,z), 보관일수

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

		//같은 상자에서 상하좌우
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

		//위, 아래의 상자에서
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

	//최소 보관 일수 출력, 토마토가 모두 익지 않은 경우 -1 출력
	if (total != 0)
		return -1;
	else
		return day;
}

int main()
{
	cin >> m >> n >> h;

	//전체 토마토 상태 정보 받아오기
	int tmp = 0, total = 0;
	for (int z = 0; z < h; z++)
	{
		for (int x = 0; x < n; x++)
		{
			for (int y = 0; y < m; y++)
			{
				cin >> tmp;
				tomato[x][y][z] = tmp;

				//익은 토마토들을 시작점으로 하고, 토마토의 개수 파악
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