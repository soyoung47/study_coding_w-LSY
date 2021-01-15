//https://www.acmicpc.net/problem/9184

/***Soution 2***/
//2052KB, 424ms
//scanf, printf로 변경시 8ms

#include <iostream>
using namespace std;

int dp[21][21][21] = { 0, };

int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	else if (a > 20 || b > 20 || c > 20)
		return w(20, 20, 20);

	int& result = dp[a][b][c];

	//만약 이미 값이 있으면 결과값 return
	if (result)	return result;

	if (a < b && b < c)
		result = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else
		result = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);

	return result;
}

int main()
{
	//테스트 케이스에 따른 재귀함수값 출력
	int a = 0, b = 0, c = 0;
	
	while (1)
	{
		cin >> a >> b >> c;
		//scanf("%d %d %d", &a, &b, &c);

		if (a == -1 && b == -1 && c == -1)	break;

		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
		//printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
	}

	return 0;
}

/***Soution 1***/
//2016KB, 428ms

#include <iostream>
using namespace std;

int main()
{
	//재귀함수 w(a,b,c)의 값 구하기
	int w[21][21][21] = { 0, };

	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			w[0][i][j] = w[i][0][j] = w[i][j][0] = 1;
		}
	}

	for (int x = 1; x < 21; x++)
	{
		for (int y = 1; y < 21; y++)
		{
			for (int z = 1; z < 21; z++)
			{
				if (x < y && y < z)
					w[x][y][z] = w[x][y][z - 1] + w[x][y - 1][z - 1] - w[x][y - 1][z];
				else
					w[x][y][z] = w[x - 1][y][z] + w[x - 1][y - 1][z] + w[x - 1][y][z - 1] - w[x - 1][y - 1][z - 1];
			}
		}
	}

	//테스트 케이스에 따른 재귀함수값 출력
	int a = 0, b = 0, c = 0, ans = 0;

	while (1)
	{
		cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1)	break;

		if (a <= 0 || b <= 0 || c <= 0)
			ans = 1;
		else if (a > 20 || b > 20 || c > 20)
			ans = w[20][20][20];
		else
			ans = w[a][b][c];

		cout << "w(" << a << ", " << b << ", " << c << ") = " << ans << "\n";
	}

	return 0;
}