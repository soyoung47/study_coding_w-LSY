//https://www.acmicpc.net/problem/9461
//2016KB, 4ms

#include <iostream>
using namespace std;

long long triangle[101] = { 0 };

int main()
{
	int test_case, n, k=4;
	cin >> test_case;

	for (int i = 0; i < 4; i++)
		triangle[i] = 1;

	for (int t = 0; t < test_case; t++)
	{
		cin >> n;

		for (int i = k; i <= n; i++)
			triangle[i] = triangle[i - 2] + triangle[i - 3];

		if (n >= 4)
			k = n + 1;

		cout << triangle[n] << "\n";
	}
	
}