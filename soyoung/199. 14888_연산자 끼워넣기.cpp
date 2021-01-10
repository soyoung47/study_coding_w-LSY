//https://www.acmicpc.net/problem/14888

/***Solution 2: 2016KB, 0ms***/
#include <iostream>
#include <vector>
using namespace std;

int MIN = 1000000000, MAX = -1000000000;	//�ּ� �����, �ִ� �����
vector<int> arr;	//����

void calculate(int plus, int minus, int multiple, int div, int result, int ind)
{
	if (!plus && !minus && !multiple && !div)
	{
		MIN = min(MIN, result);
		MAX = max(MAX, result);
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
	cout << MAX << "\n" << MIN;
}

//ref:::https://www.acmicpc.net/source/24827287



/***Solution 1: 3856KB, 748ms***/
//next_permutation �Լ� ������� ��ü ����
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

int MIN = 1000000000, MAX = -1000000000;	//�ּ� �����, �ִ� �����
int arr[10] = { 0, };	//����
vector<int> op;	//������ �迭(�ε����� ����:����(1), ����(2), ����(3), ������(4))
unordered_set<string> s;
vector<int> op_comb;	//������ ���� ���� ����

//�����ڿ� ���� ��� ����� ��ȯ(������ �ε���, �� ��)
int cal(char op_ind, int x, int y)
{
	switch (op_ind)
	{
	case '1':	//����
		return x + y;
		break;
	case '2':	//����
		return x - y;
		break;
	case '3':	//����
		return x * y;
		break;
	case '4':	//������
		return x / y;
		break;
	}
}

void combination(int cnt, vector<bool> &select)
{
	int size = op.size();	//n - 1

	//�����ڰ� ��� ���õ� ���
	if (cnt == size)
	{
		//������ ������ ���ڿ��� ����
		string str = "";
		for (int i = 0; i < size; i++)
			str += to_string(op_comb[i]);
		
		//�ߺ�üũ
		if (s.count(str) > 0)	return;
		s.insert(str);

		//������ ������� ������ ���� ������ �� min, max�� ������Ʈ
		int result = arr[0];
		for (int i = 0; i < size; i++)
			result = cal(str[i], result, arr[i + 1]);
		
		MIN = min(MIN, result);
		MAX = max(MAX, result);

		return;
	}

	for (int i = 0; i < size; i++)
	{
		if (select[i])	continue;
		//op[i] ������ ������ ���
		select[i] = true;
		op_comb.emplace_back(op[i]);
		combination(cnt + 1, select);

		//op[i] ������ �������� ���� ���
		select[i] = false;
		op_comb.pop_back();
	}
}

int main()
{
	int n;	//���� ����
	cin >> n;

	//���� arr�� �� �޾ƿ���
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	//������ ���� ���� �޾ƿ���
	int cnt;
	
	for (int i = 0; i < 4; i++)
	{	
		cin >> cnt;
		for(int j=0; j<cnt; j++)
			op.emplace_back(i + 1);
	}
		
	//������ ���� ����
	vector<bool> select(n - 1, false);
	combination( 0, select);

	//���
	cout << MAX << "\n" << MIN;
}