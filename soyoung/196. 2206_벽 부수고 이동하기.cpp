//https://www.acmicpc.net/problem/2206
//13760KB, 112ms

#include <iostream>
#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;

int n, m;	//맵의 크기(세로, 가로)
int map[1001][1001];	//맵
int dist[1001][1001][2] = { 0, };	//이동거리(벽을 부순 개수에 따라)
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int move()
{
	queue<tuple<int, int, int>> q;	//위치(x,y), 부순 벽의 개수
	q.emplace(0, 0, 0);	//시작점(문제: 1,1), 부순 벽의 개수(0)
	dist[0][0][0] = 1;

	while (!q.empty())
	{
		int x, y, nx, ny, wall;
		tie(x, y, wall) = q.front();
		q.pop();

		//최단 경로 반환
		if (x == n - 1 && y == m - 1)
			return dist[x][y][wall];

		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)	continue;

			//통로를 지날 때 경로 업데이트(벽을 부쉈는지에 대한 여부 상관없이)
			if (map[nx][ny] == 0 && dist[nx][ny][wall] == 0)
			{
				dist[nx][ny][wall] = dist[x][y][wall] + 1;
				q.emplace(nx, ny, wall);
			}
			//벽을 부순 적이 없을 때, 벽을 지나며 부수고 이동 경로를 구한적이 없는 경우: 벽을 부수고 지날 때 경로 업데이트
			if (wall == 0 && map[nx][ny] == 1 && dist[nx][ny][wall + 1] == 0)
			{
				dist[nx][ny][wall + 1] = dist[x][y][wall] + 1;
				q.emplace(nx, ny, wall + 1);
			}
		}
	}

	//불가능하면 -1 반환
	return -1;
}

int main()
{
	cin >> n >> m;

	//맵의 정보 받아오기
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf("%1d", &map[i][j]);
	}

	//최단 경로 검색
	int answer = move();
	cout << answer;
}