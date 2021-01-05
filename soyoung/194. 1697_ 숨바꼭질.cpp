//https://www.acmicpc.net/problem/1697

#include <iostream>
#include <unordered_set>
#include <queue>
#include <utility>
using namespace std;

int n, k;	//����, ������ ��ġ

//�����̰� �̵��� ���� ��ġ
int move(int ind, int x)	//�̵� ��� index, ���� ��ġ x
{
	switch (ind) {
	case 0:	//�ڷ� 1ĭ �ȱ�
		return x - 1;
		break;
	case 1:	//������ 1ĭ �ȱ�
		if (x < k)
			return x + 1;
		else
			return -1;
		break;
	case 2:	//�����̵�
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

	//�����̰� ������ ã�� �� �ִ� ���� ���� �ð� ���ϱ�(BFS)
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