//https://www.acmicpc.net/problem/1012

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void searchGroup(int x, int y, vector<vector<int>>& cabbage, vector<vector<bool>>& visit)
{
	int w = cabbage.size();
	int h = cabbage[0].size();

	queue<pair<int, int>> q;
	q.emplace(x, y);

	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		if (visit[cur_x][cur_y])	continue;
		visit[cur_x][cur_y] = true;

		for (int i = 0; i < 4; i++)
		{
			int new_x = cur_x + dx[i];
			int new_y = cur_y + dy[i];

			if (new_x < 0 || new_x >= w || new_y < 0 || new_y >= h)	continue;
			
			if (!visit[new_x][new_y] && cabbage[new_x][new_y] == 1)
				q.emplace(new_x, new_y);
		}
	}
}

int main()
{
	int testcase;	//test case ����
	cin >> testcase;
	
	for (int t = 0; t < testcase; t++)
	{
		int m, n, k, x, y, cnt = 0;
		cin >> m >> n >> k;

		vector<vector<int>> cabbage(n, vector<int>(m, 0));	//���� ��ġ
		vector<vector<bool>> visit(n, vector<bool>(m, false));

		//���� ��ġ ���� �Է¹ޱ�
		for (int i = 0; i < k; i++)
		{
			cin >> x >> y;
			cabbage[y][x] = 1;
		}

		//���� �׷� ����(BFS)
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (!visit[i][j] && cabbage[i][j] == 1)
				{
					searchGroup(i, j, cabbage, visit);
					cnt++;
				}					
			}
		}

		//�ʿ��� ������������ ���� ���
		cout << cnt << "\n";
	}
}