//https://www.acmicpc.net/problem/14888

/***solution 2: 2016kb, 0ms***/
//재귀
#include <iostream>
#include <vector>
using namespace std;

int min = 1000000000, max = -1000000000;	//최소 결과값, 최대 결과값
vector<int> arr;	//수열

void calculate(int plus, int minus, int multiple, int div, int result, int ind)
{
	if (!plus && !minus && !multiple && !div)
	{
		min = min(min, result);
		max = max(max, result);
		return;
	}

	if (plus)		//덧셈
		calculate(plus - 1, minus, multiple, div, result + arr[ind], ind + 1);
	if (minus)		//뺄셈
		calculate(plus, minus - 1, multiple, div, result - arr[ind], ind + 1);
	if (multiple)	//곱셈
		calculate(plus, minus, multiple - 1, div, result * arr[ind], ind + 1);
	if (div)		//나눗셈
		calculate(plus, minus, multiple, div - 1, result / arr[ind], ind + 1);
}

int main()
{
	int n;	//수의 개수
	cin >> n;

	//수열 arr의 값 받아오기
	arr.resize(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	//연산자 개수 정보 받아오기
	int plus, minus, multiple, div;
	cin >> plus >> minus >> multiple >> div;

	//모든 경우의 수 확인(연산자 순서)
	calculate(plus, minus, multiple, div, arr[0], 1);

	//출력
	cout << max << "\n" << min;
}

//ref:::https://www.acmicpc.net/source/24827287



/***solution 1: 2016kb, 0ms***/
//순열(next_permutation)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int min_num = 1000000000, max_num = -1000000000;	//최소 결과값, 최대 결과값

//연산자에 따른 계산 결과값 반환(연산자 인덱스, 두 수)
int cal(int op_ind, int x, int y)
{
	switch (op_ind)
	{
	case 0:	//덧셈
		return x + y;
		break;
	case 1:	//뺄셈
		return x - y;
		break;
	case 2:	//곱셈
		return x * y;
		break;
	case 3:	//나눗셈
		return x / y;
		break;
	}
}

int main()
{
	int n;	//수의 개수
	cin >> n;

	//수열 arr의 값 받아오기
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	//연산자 개수 정보 받아오기
	int cnt;
	vector<int> op;	//연산자 배열(인덱스로 저장:덧셈(1), 뺄셈(2), 곱셈(3), 나눗셈(4))
	for (int i = 0; i < 4; i++)
	{
		cin >> cnt;
		for (int j = 0; j < cnt; j++)
			op.emplace_back(i);
	}

	//연산자 순서 조합
	do
	{
		int result = arr[0];

		for (int j = 0; j < n - 1; j++)
			result = cal(op[j], result, arr[j + 1]);

		max_num = max(max_num, result);
		min_num = min(min_num, result);

	} while (next_permutation(op.begin(), op.end()));

	//출력
	cout << max_num << "\n" << min_num;
}