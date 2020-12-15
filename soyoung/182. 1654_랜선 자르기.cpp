//https://www.acmicpc.net/problem/1654

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int K, N;
	cin >> K >> N;

	vector<long long> lan(K, 0);
	for (int i = 0; i < K; i++)
		cin >> lan[i];

	//이분탐색(랜선길이)
	//랜선의 최대값이 0인 경우, min = 0이면 런타임 에러 발생(mid = 0 /2 가 되기 때문에)
	long long min = 1, max = *max_element(lan.begin(), lan.end()), mid, answer = 0;

	while (min <= max)
	{
		mid = (min + max) / 2;

		//자른 랜선 개수 확인
		int cnt = 0;
		for (long long l : lan)	cnt += l / mid;

		if (cnt < N)
			max = mid - 1;
		else
		{
			min = mid + 1;
			answer = answer > mid ? answer : mid;
		}
	}

	cout << answer;
}