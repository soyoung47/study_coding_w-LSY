//https://www.acmicpc.net/problem/11054
//2016KB, 0ms

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, ind, ans = 0;
	cin >> n;

	vector<int> A(n, 0);
	vector<int> rA(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
		rA[n - i - 1] = A[i];
	}

	vector<int> inc, dec;	//증가/감소하는 부분 수열
	vector<vector<int>> len(2, vector<int>(n, 0));	//A[n]으로 끝나는 증가/감소하는 부분 수열의 길이

	for (int i = 0; i < n; i++)
	{	
		//증가하는 수열
		ind = lower_bound(inc.begin(), inc.end(), A[i]) - inc.begin();	//배열inc 중 원소값보다 큰 가장 작은 값의 위치반환

		if (ind == inc.size())
			inc.push_back(A[i]);
		else
			inc[ind] = A[i];

		len[0][i] = inc.size();

		//감소하는 수열
		ind = lower_bound(dec.begin(), dec.end(), rA[i]) - dec.begin();	//배열dec 중 원소값보다 큰 가장 작은 값의 위치반환

		if (ind == dec.size())
			dec.push_back(rA[i]);
		else
			dec[ind] = rA[i];

		len[1][n - i - 1] = dec.size();
	}

	for (int i = 0; i < n; i++)
		ans = max(ans, len[0][i] + len[1][i] - 1);

	cout << ans;
}

// 7, 50 48 43 25 40 39 38 : 6
