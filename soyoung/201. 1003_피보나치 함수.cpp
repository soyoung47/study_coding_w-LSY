//https://www.acmicpc.net/problem/1003
//2016KB, 4ms

#include <iostream>
using namespace std;

int main()
{
	//��µǴ� 0�� 1�� ���� ���ϱ�
	int zero[41] = { 0 }, one[41] = { 0 };
	zero[0] = 1, one[1] = 1;
	for (int i = 2; i <= 40; i++)
	{
		zero[i] = zero[i - 1] + zero[i - 2];
		one[i] = one[i - 1] + one[i - 2];
	}

	//�׽�Ʈ ���̽� ���� ��µǴ� 0�� 1�� ���� ���
	int test_case, n = 0;
	cin >> test_case;

	for (int t = 0; t < test_case; t++)
	{
		cin >> n;

		cout << zero[n] << " " << one[n] << "\n";
	}

	return 0;
}