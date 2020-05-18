#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long max_w, ans;
int W[100001];

int main()
{
	ans = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> W[i];

	//내림차순
	sort(W, W + N, greater<int>());

	for (int j = 0; j < N; j++)
	{
		max_w = W[j] * (j + 1);
		if (max_w > ans)
			ans = max_w;
	}

	cout << ans;
}