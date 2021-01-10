//https://www.acmicpc.net/problem/14888

/***Solution 2: 2016KB, 0ms***/
#include <iostream>
#include <vector>
using namespace std;

int MIN = 1000000000, MAX = -1000000000;	//최소 결과값, 최대 결과값
vector<int> arr;	//수열

void calculate(int plus, int minus, int multiple, int div, int result, int ind)
{
	if (!plus && !minus && !multiple && !div)
	{
		MIN = min(MIN, result);
		MAX = max(MAX, result);
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
	cout << MAX << "\n" << MIN;
}

//ref:::https://www.acmicpc.net/source/24827287



/***Solution 1: 3856KB, 748ms***/
//next_permutation 함수 사용으로 대체 가능
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

int MIN = 1000000000, MAX = -1000000000;	//최소 결과값, 최대 결과값
int arr[10] = { 0, };	//수열
vector<int> op;	//연산자 배열(인덱스로 저장:덧셈(1), 뺄셈(2), 곱셈(3), 나눗셈(4))
unordered_set<string> s;
vector<int> op_comb;	//연산자 순서 조합 저장

//연산자에 따른 계산 결과값 반환(연산자 인덱스, 두 수)
int cal(char op_ind, int x, int y)
{
	switch (op_ind)
	{
	case '1':	//덧셈
		return x + y;
		break;
	case '2':	//뺄셈
		return x - y;
		break;
	case '3':	//곱셈
		return x * y;
		break;
	case '4':	//나눗셈
		return x / y;
		break;
	}
}

void combination(int cnt, vector<bool> &select)
{
	int size = op.size();	//n - 1

	//연산자가 모두 선택된 경우
	if (cnt == size)
	{
		//연산자 조합을 문자열로 변경
		string str = "";
		for (int i = 0; i < size; i++)
			str += to_string(op_comb[i]);
		
		//중복체크
		if (s.count(str) > 0)	return;
		s.insert(str);

		//연산자 순서대로 수열의 값을 연산한 뒤 min, max값 업데이트
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
		//op[i] 연산자 선택한 경우
		select[i] = true;
		op_comb.emplace_back(op[i]);
		combination(cnt + 1, select);

		//op[i] 연산자 선택하지 않은 경우
		select[i] = false;
		op_comb.pop_back();
	}
}

int main()
{
	int n;	//수의 개수
	cin >> n;

	//수열 arr의 값 받아오기
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	//연산자 개수 정보 받아오기
	int cnt;
	
	for (int i = 0; i < 4; i++)
	{	
		cin >> cnt;
		for(int j=0; j<cnt; j++)
			op.emplace_back(i + 1);
	}
		
	//연산자 순서 조합
	vector<bool> select(n - 1, false);
	combination( 0, select);

	//출력
	cout << MAX << "\n" << MIN;
}