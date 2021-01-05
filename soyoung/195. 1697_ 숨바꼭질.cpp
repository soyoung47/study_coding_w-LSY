//https://www.acmicpc.net/problem/1697

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