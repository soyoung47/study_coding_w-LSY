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

		ind = lower_bound(v.begin(), v.end(), port) - v.begin();
	
		if (ind == v.size())
			v.push_back(port);
		else
			v[ind] = port;
	}

	cout << v.size();

}