//https://www.acmicpc.net/problem/2579
//2016KB, 0ms

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> sum;	//각 계단의 게임 점수 합산(dp)
vector<int> step;	//각 계단의 점수

void goUPstep()
{
	sum[1] = step[1];
	sum[2] = step[1] + step[2];
	sum[3] = max(step[1] + step[3], step[2] + step[3]);

	//4번째 계단: [1-3-4], [2-4] 2가지 방법 가능
	for (int i = 4; i <= n; i++)
		sum[i] = max(sum[i - 3] + step[i - 1] + step[i], sum[i - 2] + step[i]);
}

int main()
{
	cin >> n;

	sum.resize(n + 1, 0);
	step.resize(n + 1, 0);

	for (int i = 1; i <= n; i++)
		cin >> step[i];

	goUPstep();	//계단 오르기

	cout << sum[n];
}