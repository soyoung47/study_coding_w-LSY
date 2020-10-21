#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, port, ind;
	vector<int> v;

	cin >> n;

	while (n--)
	{
		cin >> port;

		ind = lower_bound(v.begin(), v.end(), port) - v.begin();	//v배열 중 port값보다 큰 가장 작은 값의 위치반환
	
		if (ind == v.size())
			v.push_back(port);
		else
			v[ind] = port;
	}

	cout << v.size();

}