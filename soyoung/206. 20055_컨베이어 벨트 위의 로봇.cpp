//https://www.acmicpc.net/problem/20055

/***Solution 2: 2020KB, 64ms***/
#include <iostream>
#include <deque>
using namespace std;

struct convey
{
	bool robot = false;	//�κ� ��ġ ����
	int durability;		//������
};

int n, k;
int up, down;	//�ö󰡴� ��ġ, �������� ��ġ
int cnt = 0, level = 0;	//�������� 0�� ĭ�� ����, ���� ���� �ܰ�
deque<convey> belt;

void rotateBelt()
{
	belt.emplace_front(belt.back());
	belt.pop_back();

	if (belt[down].robot)	//������ ��ġ�� �κ��� �ִ� ���, ������
		belt[down].robot = false;
}

void moveRobot()
{
	for (int i = down - 1; i >= up; i--)
	{
		if (!belt[i].robot)	continue;

		int next = i + 1;

		//�̵��� ĭ�� �κ��� ����, �̵��� ĭ�� �������� 1�̻��϶� �̵�
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

	//������ ���� �޾ƿ���
	belt.resize(2 * n);    //�����̾� ��Ʈ ����(2n)
	for (int i = 0;i < 2 * n; i++)
		cin >> belt[i].durability;

	//�����̾� ��Ʈ �۵�
	up = 0, down = n - 1;
	while (1)
	{
		level++;

		rotateBelt();	//��Ʈ ��ĭ ȸ��
		moveRobot();	//�����̾� ��Ʈ �� �κ� �̵�
		addRobot();	//�κ� �߰�

		//������ 0�� ĭ ���� >= k �̸� ����
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

	//������ ���� �޾ƿ���
	size = 2 * n;	//�����̾� ��Ʈ ����(2n)
	vector<int> durability(size, 0);
	for (int i = 0;i < size; i++)
		cin >> durability[i];

	//�����̾� ��Ʈ �۵�
	vector<bool> robot(size, false);
	int up = 0, down = n - 1, next;	//�ö󰡴� ��ġ, �������� ��ġ, �κ��� �̵��� ��ġ(����ġ+1)
	int cnt = 0, level = 0;	//�������� 0�� ĭ�� ����, ���� ���� �ܰ�
	queue<int> q;	//�����̾� ��Ʈ ���� �κ� ��ġ
	while (1)
	{
		level++;

		//��Ʈ ��ĭ ȸ��
		up = (--up + size) % size;
		down = (up + n - 1) % size;

		//�����̾� ��Ʈ �� �κ� �̵�(���� �ö� �κ�����)
		if (!q.empty())
		{	
			int cur, i = q.size();
			while(i)
			{
				i--;
				
				if (q.empty())	break;
				cur = q.front();
				q.pop();

				//������ ��ġ�� ���, ������
				if (cur == down)
				{
					robot[down] = false;
					continue;
				}

				next = (cur + 1) % size;

				//�̵��� ĭ�� �κ��� ����, �̵��� ĭ�� �������� 1�̻��϶� �̵�
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

		//�κ� �߰�
		if (!robot[up] && durability[up] >= 1)
		{
			robot[up] = true;
			q.emplace(up);
			durability[up]--;
			
			if (!durability[up])	cnt++;
		}

		//������ 0�� ĭ ���� >= k �̸� ����
		if (cnt >= k)	break;			
	}

	cout << level;
}