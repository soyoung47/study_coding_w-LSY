//https://www.acmicpc.net/problem/2667

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int n, number;	//지도 크기, 단지 번호
vector<int> bldSize;	//단지내 집의 수
vector<string> map(26);
bool visit[26][26] = { false };

void checkHouse(int x, int y)
{
	int cnt = 0;		//집의 수
	
	queue<pair<int, int>> q;
	q.emplace(x, y);
	number++;

	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		if (visit[cur_x][cur_y])	continue;
		visit[cur_x][cur_y] = true;
		cnt++;

		for (int i = 0; i < 4; i++)
		{
			int new_x = cur_x + dx[i];
			int new_y = cur_y + dy[i];

			if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= n)	continue;

			if (!visit[new_x][new_y] && map[new_x][new_y] == '1')
				q.emplace(new_x, new_y);
		}
	}

	bldSize.emplace_back(cnt);
}

int main()
{	
	cin >> n;

	//지도 정보 읽어오기
	for (int i = 0; i < n; i++)
		cin >> map[i];

	//단지 설정
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == '1' && !visit[i][j])
				checkHouse(i, j);
		}
	}

	//단지내 집의 수 오름차순 정렬
	sort(bldSize.begin(), bldSize.end());

	//단지수, 단지내 집의 수 출력
	cout << bldSize.size() << "\n";
	for(int i = 0; i < bldSize.size(); i++)
		cout << bldSize[i] << "\n";
}
