//https://www.acmicpc.net/problem/3190
//2020KB, 0ms

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct position {
	int x;
	int y;
};

struct direction {
	int t;
	char c;
};

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int n, k, l, dir = 0, t = 0;
vector<vector<int>> board;
deque<direction> direct;
deque<position> snake;

void go()
{
	int nx, ny, ex, ey;

	while (1)
	{
		t++;

		/*** 이동 ***/
		nx = snake.front().x + dx[dir];
		ny = snake.front().y + dy[dir];

		//벽 or 자기자신의 몸과 부딪히면 GAME OVER
		if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] < 0)	break;

		snake.push_front({ nx, ny });

		if (board[nx][ny] == 0)
		{
			ex = snake.back().x;
			ey = snake.back().y;

			snake.pop_back();

			board[ex][ey] = 0;
		}

		board[nx][ny] = -1;

		//방향 변환
		if (!direct.empty() && direct.front().t == t)
		{
			if (direct.front().c == 'D')
				dir = (dir + 1) % 4;
			else
				dir = (dir + 3) % 4;
			direct.pop_front();
		}
	}

	return;
}

int main()
{
	cin >> n;
	cin >> k;

	//보드 초기화
	board.assign(n, vector<int>(n, 0));

	//사과 위치 정보 받아오기
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		board[x - 1][y - 1] = 1;
	}

	cin >> l;
	for (int i = 0; i < l; i++)
	{
		int x;
		char ch;
		cin >> x >> ch;
		direct.push_back({ x, ch });
	}

	snake.push_front({ 0, 0 });
	board[0][0] = -1;
	go();

	cout << t;
}