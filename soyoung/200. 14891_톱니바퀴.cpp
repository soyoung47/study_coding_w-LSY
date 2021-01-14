//https://www.acmicpc.net/problem/14891
//2212KB, 0ms

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

deque<int>	d[5];	//톱니바퀴
vector<int> rt(5, 5);	//톱니바퀴의 회전 방향 (시계 1, 반시계 -1, 정지 0, 정해지지 않음(초기화) 5)
//네 톱니바퀴의 점수 합 구하기
int cal_score()
{
	int score = 0;

	for (int i = 1; i <= 4; i++)
		score += d[i].front() * (int)pow(2, i - 1);

	return score;
}

//톱니바퀴 회전
void rotation(int no)
{
	//앞쪽의 톱니바퀴와 비교 + 회전방향 정하기
	int ind = no;
	while(ind > 1)
	{
		//서로 다른 극인 경우 다른 방향으로 회전, 같은 극이면 회전하지 않음
		if (d[ind - 1].at(2) != d[ind].at(6) && rt[ind] != 0)
			rt[ind - 1] = rt[ind] * -1;
		else
			rt[ind - 1] = 0;

		ind--;
	}

	//뒤쪽의 톱니바퀴와 비교 + 회전방향 정하기
	ind = no;
	while (ind < 4)
	{
		//서로 다른 극인 경우 다른 방향으로 회전, 같은 극이면 회전하지 않음
		if (d[ind].at(2) != d[ind + 1].at(6) && rt[ind] != 0)
			rt[ind + 1] = rt[ind] * -1;
		else
			rt[ind + 1] = 0;

		ind++;
	}

	//톱니바퀴 상태 업데이트
	for (int i = 1; i <= 4; i++)
	{
		if (rt[i] == 1)	//시계 방향
		{
			d[i].emplace_front(d[i].back());
			d[i].pop_back();
		}
		else if(rt[i] == -1)	//반시계 방향
		{
			d[i].emplace_back(d[i].front());
			d[i].pop_front();
		}

		rt[i] = 5;
	}
}

int main()
{
	//톱니바퀴의 상태 정보 받아오기
	for (int i = 1; i <= 4; i++)
	{	
		d[i].assign(8, 0);
		for (int j = 0; j < 8; j++)
			scanf("%1d", &d[i].at(j));
	}

	int k, no, r_state;	//회전 횟수, 톱니바퀴 번호, 회전 방향(시계 1, 반시계 -1)
	cin >> k;

	//톱니바퀴 회전
	for (int i = 0; i < k; i++)
	{
		cin >> no >> r_state;

		//톱니바퀴 회전
		rt[no] = r_state;	//방향 업데이트
		rotation(no);
	}

	cout << cal_score();

	return 0;
}