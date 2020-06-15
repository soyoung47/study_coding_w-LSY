//#5987. SW달리기
#include <iostream>
#include <memory.h> memset(Pos, 0, sizeof(Pos));
#define MAX 16
using namespace std;
int Pos[MAX];
int T, N, M;
long long dp[(1 << 16)]; //1*2^16 = 65536

long long dfs(int flag)
{
	if (flag == (1 << N) - 1) return 1;
	if (dp[flag] == 0)
	{
		for (int i = 0; i < N; i++)
		{
			if ((flag & (1 << i)) == 0)
			{
				if ((flag & Pos[i]) == Pos[i])
				{
					dp[flag] += dfs(flag | (1 << i));
				}
			}
		}
	}
	return dp[flag];
}

int main()
{
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N >> M; //N:#people, M:#lines
		memset(Pos, 0, sizeof(Pos));
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < M; i++)
		{
			int x, y;
			cin >> x >> y;
			x--; //index in array
			y--;
			Pos[x] |= (1 << y); // 1*2^y 0000 | 0010 = 0010 = 2
		}
		dfs(0);
		cout << '#' << tc << ' ' << dp[0] << endl;
	}

	return 0;
}

/*
ref: https://boycoding.tistory.com/163 (bitwise operators)
ex) M:3 N:2
1) 1 2
P[0]: 0000 -> 0010 (1*2^2) = 2
2) 1 3
P[0]: 0010 -> 0110(1*2^3) = 6
*/
