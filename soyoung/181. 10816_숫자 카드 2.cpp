//https://www.acmicpc.net/problem/10816

/***Solution 1: Binary Search***/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
int N, M, X;

int low_bound(int left, int right)
{
	while (left < right)
	{
		int mid = (left + right) / 2;

		if (arr[mid] < X)
			left = mid + 1;
		else
			right = mid;
	}

	return left;
}

int up_bound(int left, int right)
{
	while (left < right)
	{
		int mid = (left + right) / 2;

		if (arr[mid] <= X)
			left = mid + 1;
		else
			right = mid;
	}

	return right;
}

int main()
{
	cin >> N;

	//숫자 카드에 적힌 정수 저장 및 오름차순 정렬
	int tmp = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		arr.emplace_back(tmp);
	}

	sort(arr.begin(), arr.end());


	//M개의 정수 X가 적힌 숫자 카드 개수 확인
	cin >> M;
	vector<int> answer(M, 0);
	for (int i = 0; i < M; i++)
	{
		cin >> X;

		//이분 탐색(STL)
		//answer[i] = upper_bound(arr.begin(), arr.end(), X) - lower_bound(arr.begin(), arr.end(), X);

		//이분 탐색(구현)
		answer[i] = up_bound(0, N) - low_bound(0, N);
	}

	//정답 출력
	for (int ans : answer)
		cout << ans << " ";
}


/***Solution 2: Hash***/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
	int N, M, X;
	cin >> N;

	//숫자 카드에 적힌 정수 저장
	unordered_map<int, int> card;
	int tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		card[tmp]++;
	}

	//M개의 정수 X가 적힌 숫자 카드 개수 확인
	cin >> M;
	vector<int> answer(M, 0);
	for (int i = 0; i < M; i++)
	{
		cin >> X;

		if (card.find(X) != card.end())
			answer[i] = card[X];
	}

	//정답 출력
	for (int ans : answer)
		cout << ans << "\n";
}