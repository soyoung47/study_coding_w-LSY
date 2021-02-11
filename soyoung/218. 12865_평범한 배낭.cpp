//https://www.acmicpc.net/problem/12865

//Solution 1:::42000KB, 44ms
//ref:::https://blog.naver.com/qlcslfl/221655290683

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, k;	//물건 개수, 제한 무게
	cin >> n >> k;

	vector<vector<int>> pack(n + 1, vector<int>(k + 1, 0));
	int w, v;
	for (int i = 1; i <= n; i++)
	{
		cin >> w >> v;

		for (int j = 1; j <= k; j++)
		{
			if (j >= w)
				pack[i][j] = max(pack[i - 1][j], pack[i - 1][j - w] + v);
			else
				pack[i][j] = pack[i - 1][j];
		}
	}

	cout << pack[n][k];
}

/**********************************************************************************/

//Solution 2:::2408KB, 16ms
//ref:::https://www.acmicpc.net/source/25942784

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, k, ans = 0;	//물건 개수, 제한 무게, 가치합 최대값
	cin >> n >> k;

	vector<int> pack(k + 1, 0);
	int w, v;
	for (int i = 1; i <= n; i++)
	{
		cin >> w >> v;

		for (int j = k; j >= w; j--)
		{
			pack[j] = max(pack[j], pack[j - w] + v);
			ans = max(ans, pack[j]);
		}
	}

	cout << ans;
}

 