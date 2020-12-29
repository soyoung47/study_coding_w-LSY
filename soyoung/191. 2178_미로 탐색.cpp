//https://www.acmicpc.net/problem/2178

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int n, m;	// n x m 미로 크기
vector<string> maze;	//미로
bool visit[101][101] = { false };

int escape()
{
	queue<pair<pair<int, int>, int>> q;
	q.push({ { 0, 0 }, 1 });	//좌표(x,y), 이동 칸수

	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (x == n - 1 && y == m - 1)
			return cnt;

		if (visit[x][y])	continue;
		visit[x][y] = true;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)	continue;

			if (!visit[nx][ny] && maze[nx][ny] == '1')
				q.push({ {nx, ny}, cnt + 1 });
		}
	}
}

int main()
{	
	cin >> n >> m;

	//미로 정보 입력 받기
	string str = "";
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		maze.emplace_back(str);
	}

	//미로 찾기
	int min = escape();
	cout << min;
}