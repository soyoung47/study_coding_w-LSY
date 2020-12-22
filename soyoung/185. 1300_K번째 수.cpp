//https://www.acmicpc.net/problem/1300

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	long long N, k;	//N: �迭�� ũ��, k: index
	
	cin >> N >> k;

	long long start = 1, end = N * N, mid, answer = 1;

	while (start <= end)
	{
		mid = (start + end) / 2;

		//mid�� ���ų� ���� ���� ���� ���ϱ� = mid�� index��
		long long cnt = 0;
		for (long long i = 1; i <= N; i++)
		{
			cnt += min(N, mid / i);
			//REF:::https://kyu9341.github.io/algorithm/2020/03/13/algorithm1300/
		}

		//mid�� index���� k(index)�� ��
		if (cnt >= k)
		{
			end = mid - 1;
			answer = mid;
		}	
		else
			start = mid + 1;
	}

	cout << answer;
} 