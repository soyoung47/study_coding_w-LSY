#include <string>
#include <vector>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
	//m,n: 1~100
	int check[101][101];
	
	//init check as 1
	for (int j = 1; j <= n; j++)
		for (int i = 1; i <= m; i++)
			check[j][i] = 1;

	//물웅덩이 처리
	for (int i = 0; i < puddles.size(); i++) {
		//check->물웅덩이->0
		check[puddles[i][1]][puddles[i][0]] = 0;
		//물웅덩이 x,y가 1이면 해당 라인 0
		if (puddles[i][0] == 1) {
			for (int j = puddles[i][1]; j <= n; j++)
				check[j][1] = 0;
		}
		if (puddles[i][1] == 1) {
			for (int j = puddles[i][0]; j <= m; j++)
				check[1][j] = 0;
		}
	}

	//물웅덩이 없는 경우, (좌+우 경우의수)
	for (int i = 2; i <= m; i++) {
		for (int j = 2; j <= n; j++) {
			if (check[j][i] != 0)
				check[j][i] = (check[j - 1][i] + check[j][i - 1]) % 1000000007;
		}
	}
	return check[n][m];
}

//ref: https://greenapple16.tistory.com/47
