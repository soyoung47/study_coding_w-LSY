//https://www.acmicpc.net/problem/2110

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, C;	//N: ���� ����, C: ������ ����
	cin >> N >> C;

	vector<long long> house(N, 0);	///�� ��ġ �迭
	for (int i = 0; i < N; i++)
		cin >> house[i];

	sort(house.begin(), house.end());

	long long start = 0, end = house.back() - house[0], mid, max = 0;

	while (start <= end)
	{
		mid = (start + end) / 2;

		//������ ��ġ
		int cnt = 1;
		long long prev = house[0];
		for (int i = 1; i < house.size(); i++)
		{
			if (house[i] - prev >= mid)
			{
				cnt++;
				prev = house[i];
			}
		}

		if (cnt >= C)
		{
			start = mid + 1;
			max = max > mid ? max : mid;
		}	
		else
			end = mid - 1;
	}

	cout << max;
}