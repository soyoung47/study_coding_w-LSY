//https://www.acmicpc.net/problem/14888

/***solution 2: 2016kb, 0ms***/
//���
#include <iostream>
#include <vector>
using namespace std;

int min = 1000000000, max = -1000000000;	//�ּ� �����, �ִ� �����
vector<int> arr;	//����

void calculate(int plus, int minus, int multiple, int div, int result, int ind)
{
	if (!plus && !minus && !multiple && !div)
	{
		min = min(min, result);
		max = max(max, result);
		return;
	}

	if (plus)		//����
		calculate(plus - 1, minus, multiple, div, result + arr[ind], ind + 1);
	if (minus)		//����
		calculate(plus, minus - 1, multiple, div, result - arr[ind], ind + 1);
	if (multiple)	//����
		calculate(plus, minus, multiple - 1, div, result * arr[ind], ind + 1);
	if (div)		//������
		calculate(plus, minus, multiple, div - 1, result / arr[ind], ind + 1);
}

int main()
{
	int n;	//���� ����
	cin >> n;

	//���� arr�� �� �޾ƿ���
	arr.resize(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	//������ ���� ���� �޾ƿ���
	int plus, minus, multiple, div;
	cin >> plus >> minus >> multiple >> div;

	//��� ����� �� Ȯ��(������ ����)
	calculate(plus, minus, multiple, div, arr[0], 1);

	//���
	cout << max << "\n" << min;
}

//ref:::https://www.acmicpc.net/source/24827287



/***solution 1: 2016kb, 0ms***/
//����(next_permutation)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int min_num = 1000000000, max_num = -1000000000;	//�ּ� �����, �ִ� �����

//�����ڿ� ���� ��� ����� ��ȯ(������ �ε���, �� ��)
int cal(int op_ind, int x, int y)
{
	switch (op_ind)
	{
	case 0:	//����
		return x + y;
		break;
	case 1:	//����
		return x - y;
		break;
	case 2:	//����
		return x * y;
		break;
	case 3:	//������
		return x / y;
		break;
	}
}

int main()
{
	int n;	//���� ����
	cin >> n;

	//���� arr�� �� �޾ƿ���
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	//������ ���� ���� �޾ƿ���
	int cnt;
	vector<int> op;	//������ �迭(�ε����� ����:����(1), ����(2), ����(3), ������(4))
	for (int i = 0; i < 4; i++)
	{
		cin >> cnt;
		for (int j = 0; j < cnt; j++)
			op.emplace_back(i);
	}

	//������ ���� ����
	do
	{
		int result = arr[0];

		for (int j = 0; j < n - 1; j++)
			result = cal(op[j], result, arr[j + 1]);

		max_num = max(max_num, result);
		min_num = min(min_num, result);

	} while (next_permutation(op.begin(), op.end()));

	//���
	cout << max_num << "\n" << min_num;
}