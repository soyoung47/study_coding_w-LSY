//https://www.acmicpc.net/problem/1932
//3996KB, 44ms

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, tmp;
	cin >> n;

	//���� �ﰢ�� ���� �޾ƿ���
	vector<vector<int>> triangle(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
			cin >> triangle[i][j];
	}

	//���� �� ���ϱ�
	vector<vector<int>> sum(n, vector<int>(n, 0));
	sum = triangle;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			sum[i + 1][j] = max(sum[i + 1][j], sum[i][j] + triangle[i + 1][j]);	//�밢�� ���� �Ʒ�
			sum[i + 1][j + 1] = max(sum[i + 1][j + 1], sum[i][j] + triangle[i + 1][j + 1]);	//�밢�� ������ �Ʒ�
		}
	}

	//����� �ִ� �� ���
	cout << *max_element(sum[n - 1].begin(), sum[n - 1].end());
}
