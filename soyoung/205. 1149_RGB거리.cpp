//https://www.acmicpc.net/problem/1149
//2016KB, 0ms


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	//비용 정보 받아오기
	vector<vector<int>> cost(n, vector<int>(3, 0));
	for (int i = 0; i < n; i++)
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

	vector<vector<int>> sum(n, vector<int>(3, 0));	//최종 비용
	sum = cost;

	//0~n번째 집에 칠할 색상에 따른 최소비용 구하기
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			switch (j)
			{
			case 0:
				sum[i][j] += min(sum[i - 1][1], sum[i - 1][2]);
				break;
			case 1:
				sum[i][j] += min(sum[i - 1][0], sum[i - 1][2]);
				break;
			case 2:
				sum[i][j] += min(sum[i - 1][0], sum[i - 1][1]);
				break;
			}
		}
	}
	
	cout << *min_element(sum[n - 1].begin(), sum[n - 1].end());
}