//https://www.acmicpc.net/problem/20055

/***Solution 2: 2020KB, 64ms***/
#include <iostream>
#include <deque>
using namespace std;

struct convey
{
	bool robot = false;	//로봇 위치 여부
	int durability;		//내구도
};

int n, k;
int up, down;	//올라가는 위치, 내려가는 위치
int cnt = 0, level = 0;	//내구도가 0인 칸의 개수, 진행 중인 단계
deque<convey> belt;

void rotateBelt()
{
	belt.emplace_front(belt.back());
	belt.pop_back();

	if (belt[down].robot)	//내리는 위치에 로봇이 있는 경우, 내리기
		belt[down].robot = false;
}

void moveRobot()
{
	for (int i = down - 1; i >= up; i--)
	{
		if (!belt[i].robot)	continue;

		int next = i + 1;

		//이동할 칸에 로봇이 없고, 이동할 칸의 내구도가 1이상일때 이동
		if (!belt[next].robot && belt[next].durability >= 1)
		{
			if (next != down)
				belt[next].robot = true;

			belt[i].robot = false;
			belt[next].durability--;
			if (!belt[next].durability)	cnt++;
		}
	}
}

void addRobot()
{
	if (!belt[up].robot && belt[up].durability >= 1)
	{
		belt[up].robot = true;
		belt[up].durability--;

		if (!belt[up].durability)	cnt++;
	}
}

int main()
{
	cin >> n >> k;

	//내구도 정보 받아오기
	belt.resize(2 * n);    //컨베이어 벨트 길이(2n)
	for (int i = 0;i < 2 * n; i++)
		cin >> belt[i].durability;

	//컨베이어 벨트 작동
	up = 0, down = n - 1;
	while (1)
	{
		level++;

		rotateBelt();	//벨트 한칸 회전
		moveRobot();	//컨베이어 벨트 위 로봇 이동
		addRobot();	//로봇 추가

		//내구도 0인 칸 개수 >= k 이면 종료
		if (cnt >= k)	break;
	}

	cout << level;
}


/***Solution 1: 2016KB, 100ms***/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int n, k, size;
	cin >> n >> k;

	//내구도 정보 받아오기
	size = 2 * n;	//컨베이어 벨트 길이(2n)
	vector<int> durability(size, 0);
	for (int i = 0;i < size; i++)
		cin >> durability[i];

	//컨베이어 벨트 작동
	vector<bool> robot(size, false);
	int up = 0, down = n - 1, next;	//올라가는 위치, 내려가는 위치, 로봇이 이동할 위치(현위치+1)
	int cnt = 0, level = 0;	//내구도가 0인 칸의 개수, 진행 중인 단계
	queue<int> q;	//컨베이어 벨트 위의 로봇 위치
	while (1)
	{
		level++;

		//벨트 한칸 회전
		up = (--up + size) % size;
		down = (up + n - 1) % size;

		//컨베이어 벨트 위 로봇 이동(먼저 올라간 로봇부터)
		if (!q.empty())
		{	
			int cur, i = q.size();
			while(i)
			{
				i--;
				
				if (q.empty())	break;
				cur = q.front();
				q.pop();

				//내리는 위치인 경우, 내리기
				if (cur == down)
				{
					robot[down] = false;
					continue;
				}

				next = (cur + 1) % size;

				//이동할 칸에 로봇이 없고, 이동할 칸의 내구도가 1이상일때 이동
				if (!robot[next] && durability[next] >= 1)
				{
					if (next != down)
					{
						robot[next] = true;
						q.emplace(next);
					}

					robot[cur] = false;
					durability[next]--;
					if (!durability[next])	cnt++;
				}
				else
					q.emplace(cur);
			}
		}		

		//로봇 추가
		if (!robot[up] && durability[up] >= 1)
		{
			robot[up] = true;
			q.emplace(up);
			durability[up]--;
			
			if (!durability[up])	cnt++;
		}

		//내구도 0인 칸 개수 >= k 이면 종료
		if (cnt >= k)	break;			
	}

	cout << level;
}