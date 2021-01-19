//https://www.acmicpc.net/problem/1904
//5924KB, 8ms

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	//���� �� �ִ� 2�� ������ ����( 00, 1 Ÿ�� �̿�)
	vector<int> tile(n + 1, 1);

	for (int i = 2; i <= n; i++)
		tile[i] = (tile[i - 1] + tile[i - 2]) % 15746;

	cout << tile[n];
}
