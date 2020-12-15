//https://www.acmicpc.net/problem/2805

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<long long> h_tree(N, 0);
	for (int i = 0; i < N; i++)
		cin >> h_tree[i];

	//이분탐색
	long long low = 1, high = *max_element(h_tree.begin(), h_tree.end()), mid, max = 0;

	while (low <= high)
	{
		mid = (low + high) / 2;

		//절단 후 나무 길이
		long long cnt = 0;
		for (long long h : h_tree)
			cnt += (h - mid) > 0 ? (h - mid) : 0;

		if (cnt < M)
			high = mid - 1;
		else
		{
			low = mid + 1;
			max = max > mid ? max : mid;
		}	
	}

	cout << max;
}
