//https://www.acmicpc.net/problem/1697

/***Soluion 2: 2280KB, 0ms***/
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define MAX 100001

int main()
{
	int n, k;	//수빈, 동생의 위치
	cin >> n >> k;

	bool visit[MAX] = { false, };
	queue<pair<int, int>> q;	//수빈의 현재위치, 소요시간
	q.emplace(n, 0);

	//수빈이가 동생을 찾을 수 있는 가장 빠른 시간 구하기(BFS)
	int cur, time = 0, next;
	while (!q.empty())
	{
		cur = q.front().first;
		time = q.front().second;
		q.pop();

		if (visit[cur])	continue;
		visit[cur] = true;

		if (cur == k)    break;

		//수빈의 이동
		next = cur - 1;	//뒤로 1칸 걷기
		if (next >= 0 && !visit[next])
			q.emplace(next, time + 1);

		next = cur + 1;	//앞으로 1칸 걷기
		if (next < MAX && !visit[next])
			q.emplace(next, time + 1);

		next = cur * 2;	//순간이동(현재 위치의 2배에 해당하는 위치로 이동)
		if (next < MAX && !visit[next])
			q.emplace(next, time + 1);
	}

	cout << time;

	return 0;
}



/***Soluion 1: 7136KB, 24ms***/
#include <iostream>
#include <unordered_set>
#include <queue>
#include <utility>
using namespace std;

int n, k;	//수빈, 동생의 위치

//수빈이가 이동한 후의 위치
int move(int ind, int x)	//이동 방법 index, 현재 위치 x
{
	switch (ind) {
	case 0:	//뒤로 1칸 걷기
		return x - 1;
		break;
	case 1:	//앞으로 1칸 걷기
		if (x < k)
			return x + 1;
		else
			return -1;
		break;
	case 2:	//순간이동
		if (x < k)
			return 2 * x;
		else
			return -1;
		break;
	}
}
int main()
{
	cin >> n >> k;

	queue<pair<int, int>> q;
	q.emplace(n, 0);
	unordered_set<int> s;

	//수빈이가 동생을 찾을 수 있는 가장 빠른 시간 구하기(BFS)
	int cur, time = 0, next;
	while (!q.empty())
	{
		cur = q.front().first;
		time = q.front().second;
		q.pop();

		if (s.count(cur) > 0)	continue;
		s.insert(cur);

		if (cur == k)    break;

		for (int i = 0; i < 3; i++)
		{
			next = move(i, cur);

			if (next < 0)    continue;
			if (s.count(next) == 0)
				q.emplace(next, time + 1);
		}
	}

	cout << time;
}