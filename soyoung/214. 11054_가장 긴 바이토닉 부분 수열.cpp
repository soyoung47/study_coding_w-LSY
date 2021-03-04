//https://www.acmicpc.net/problem/11054

/***solution 2: dp***/
//2016kb, 4ms
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, ans = 0;
	cin >> n;

	vector<int> a(n, 0);
	vector<int> inc(n, 0);
	vector<int> dec(n, 0);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++)
	{
		inc[i] = dec[n - i - 1] = 1;

		for (int j = 0; j < i; j++)
		{
			//�����ϴ� ����
			if (a[i] > a[j])
				inc[i] = max(inc[i], inc[j] + 1);

			//�����ϴ� ����
			if (a[n - i - 1] > a[n - j - 1])
				dec[n - i - 1] = max(dec[n - i - 1], dec[n - j - 1] + 1);
		}
	}

	for (int i = 0; i < n; i++)
		ans = max(ans, inc[i] + dec[i] - 1);

	cout << ans;
}


//***solution 1: lower_bound***/
//2016kb, 0ms

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, ind, ans = 0;
	cin >> n;

	vector<int> a(n, 0);
	vector<int> ra(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		ra[n - i - 1] = a[i];
	}

	vector<int> inc, dec;	//����/�����ϴ� �κ� ����
	vector<vector<int>> len(2, vector<int>(n, 0));	//a[n]���� ������ ����/�����ϴ� �κ� ������ ����

	for (int i = 0; i < n; i++)
	{
		//�����ϴ� ����
		ind = lower_bound(inc.begin(), inc.end(), a[i]) - inc.begin();	//�迭inc �� ���Ұ����� ū ���� ���� ���� ��ġ��ȯ

		if (ind == inc.size())
			inc.push_back(a[i]);
		else
			inc[ind] = a[i];

		len[0][i] = inc.size();

		//�����ϴ� ����
		ind = lower_bound(dec.begin(), dec.end(), ra[i]) - dec.begin();	//�迭dec �� ���Ұ����� ū ���� ���� ���� ��ġ��ȯ

		if (ind == dec.size())
			dec.push_back(ra[i]);
		else
			dec[ind] = ra[i];

		len[1][n - i - 1] = dec.size();
	}

	for (int i = 0; i < n; i++)
		ans = max(ans, len[0][i] + len[1][i] - 1);

	cout << ans;
}

// 7, 50 48 43 25 40 39 38 : 6
