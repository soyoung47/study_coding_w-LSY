//https://www.acmicpc.net/problem/10844
//2016KB, 0ms

#include <iostream>
#include <vector>
using namespace std;

#define NUM 1000000000

int main()
{
	int n;
	cin >> n;

	vector<vector<long long>> v(n + 1, vector<long long>(10, 0));

	v[1][0] = 0;
	for (int i = 1; i <= 9; i++)
		v[1][i] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
				v[i][j] = v[i - 1][j + 1] % NUM;
			else if(j==9)
				v[i][j] = v[i - 1][j - 1] % NUM;
			else
				v[i][j] = (v[i - 1][j - 1] + v[i - 1][j + 1]) % NUM;
		}
	}

	long long ans = 0;
	for (int i = 0; i < 10; i++)
		ans += v[n][i];

	cout << ans % NUM;
}

//배열 v, long long이 아닌 int도 가능