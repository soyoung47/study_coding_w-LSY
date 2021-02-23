//https://www.acmicpc.net/problem/2248
//2016KB, 0ms

#include <iostream>
#include <vector>
using namespace std;

string ans = "";
vector<vector<int>> v;

void findBinary(int n, int l, long long ind)
{
	if (n == 0)	return;
	if (l == 0)
	{
		for (int i = 0; i < n; i++)
			ans += '0';
		return;
	}

	long long cnt = v[l][n - 1];

	if (cnt >= ind)
	{
		ans += '0';
		findBinary(n - 1, l, ind);
	}
	else
	{
		ans += '1';
		findBinary(n - 1, l - 1, ind - cnt);
	}

	return;
}

int main()
{
	int n, l;
	long long ind;
	cin >> n >> l >> ind;

	//1의 개수: v[i][j] (i = i개 이하의 1 개수, j = 자릿수)
	v.assign(l + 1, vector<int>(n + 1, 1));

	for (int i = 1; i <= l; i++)
	{
		for (int j = 1; j <= n; j++)
			v[i][j] = v[i - 1][j - 1] + v[i][j - 1];	//앞에 '1' 붙이는 경우 + '0' 붙이는 경우
	}

	findBinary(n, l, ind);

	cout << ans;
}


//(bit operation)ref:::https://kylog.tistory.com/6
//int countOne(int num)
//{
//	int cnt = 0;
//	while (num != 0)
//	{
//		num &= num - 1;
//		cnt++;
//	}
//
//	return cnt;
//}