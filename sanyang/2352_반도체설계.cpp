//#2352. Semiconductor Design (Longeset Increasing Subsequence)
//https://www.acmicpc.net/submit/2352/20085488
#include <iostream>
#include <algorithm>
#define MAX 40001
using namespace std;
int arr[MAX];
int LIS[MAX];


int main(int argc, char** argv)
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	LIS[1] = arr[1];
	int size = 1;
	int tmp = 0;
	for (int i = 2; i <= n; i++)
	{
		if (LIS[size] < arr[i])
		{
			size++;
			LIS[size] = arr[i];
			continue;
		}
		tmp = lower_bound(LIS + 1, LIS + size + 1, arr[i]) - LIS;
		LIS[tmp] = arr[i];
	}

	cout << size;

	return 0;
}

//ref: 
//https://dyngina.tistory.com/16
//https://kiung9085.tistory.com/48
