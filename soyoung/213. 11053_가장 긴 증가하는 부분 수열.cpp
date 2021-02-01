//https://www.acmicpc.net/problem/11053
//2016KB, 0ms

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, elemt, ind;
	vector<int> A;	//선택된 elemt(원소)의 index값 저장됨.

	cin >> n;

	while (n--)
	{
		cin >> elemt;

		ind = lower_bound(A.begin(), A.end(), elemt) - A.begin();	//수열A 중 원소값보다 큰 가장 작은 값의 위치반환
	
		if (ind == A.size())
			A.push_back(elemt);
		else
			A[ind] = elemt;
	}

	cout << A.size();
}