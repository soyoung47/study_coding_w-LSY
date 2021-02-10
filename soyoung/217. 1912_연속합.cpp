//https://www.acmicpc.net/problem/1912
//2016KB, 24ms

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, num;
	cin >> n;

	int sum = 0, max = -1000;

	while (n--)
	{
		cin >> num;

		sum = (sum + num) > num ? (sum + num) : num;
		max = max > sum ? max : sum;
	}

	cout << max;
}

//for¹®: 2016KB, 28ms
//while¹®: 2016KB, 24ms
