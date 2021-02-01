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

	vector<int> inc, dec;	//����/�����ϴ� �κ� ����
	vector<vector<int>> len(2, vector<int>(n, 0));	//A[n]���� ������ ����/�����ϴ� �κ� ������ ����

	for (int i = 0; i < n; i++)
	{	
		//�����ϴ� ����
		ind = lower_bound(inc.begin(), inc.end(), A[i]) - inc.begin();	//�迭inc �� ���Ұ����� ū ���� ���� ���� ��ġ��ȯ

		if (ind == inc.size())
			inc.push_back(A[i]);
		else
			inc[ind] = A[i];

		len[0][i] = inc.size();

		//�����ϴ� ����
		ind = lower_bound(dec.begin(), dec.end(), rA[i]) - dec.begin();	//�迭dec �� ���Ұ����� ū ���� ���� ���� ��ġ��ȯ

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
