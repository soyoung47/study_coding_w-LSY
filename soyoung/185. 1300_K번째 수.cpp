//https://www.acmicpc.net/problem/1300

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	long long N, k;	//N: 배열의 크기, k: index
	
	cin >> N >> k;

	long long start = 1, end = N * N, mid, answer = 1;

	while (start <= end)
	{
		mid = (start + end) / 2;

		//mid와 같거나 작은 원소 개수 구하기 = mid의 index값
		long long cnt = 0;
		for (long long i = 1; i <= N; i++)
		{
			cnt += min(N, mid / i);
			//REF:::https://kyu9341.github.io/algorithm/2020/03/13/algorithm1300/
		}

		//mid의 index값과 k(index)값 비교
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