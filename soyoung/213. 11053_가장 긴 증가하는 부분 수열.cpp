//https://www.acmicpc.net/problem/11053
//2016KB, 0ms

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, elemt, ind;
	vector<int> A;	//���õ� elemt(����)�� index�� �����.

	cin >> n;

	while (n--)
	{
		cin >> elemt;

		ind = lower_bound(A.begin(), A.end(), elemt) - A.begin();	//����A �� ���Ұ����� ū ���� ���� ���� ��ġ��ȯ
	
		if (ind == A.size())
			A.push_back(elemt);
		else
			A[ind] = elemt;
	}

	cout << A.size();
}