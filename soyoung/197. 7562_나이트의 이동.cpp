//https://www.acmicpc.net/problem/7562
//2280KB, 24ms

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2 };
int dy[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };
int main()
{
	int test_case;	//테스트케이스 개수
	cin >> test_case;
	
	for (int t = 0; t < test_case; t++)
	{
		int n;	//체스판의 한 변의 길이
		cin >> n;

		//체스판 만들기(이동횟수 저장)
		vector<vector<int>> chess(n, vector<int>(n, 0));

		//출발점과 도착점 정보 받아오기
		int start_x, start_y, end_x, end_y;
		cin >> start_x >> start_y;
		cin >> end_x >> end_y;

		queue<pair<int, int>> q;	//위치좌표
		q.emplace(start_x, start_y);

		while (!q.empty())
		{
			int x, y, nx, ny;
			x = q.front().first;
			y = q.front().second;
			q.pop();

			if (x == end_x && y == end_y)
			{
				cout << chess[x][y] << "\n";
				break;
			}			

			for (int i = 0; i < 8; i++)
			{
				nx = x + dx[i];
				ny = y + dy[i];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n)	continue;

				if (chess[nx][ny] == 0)
				{
					chess[nx][ny] = chess[x][y] + 1;
					q.emplace(nx, ny);
				}
			}
		}

		chess.clear();
	}
	return 0;
}