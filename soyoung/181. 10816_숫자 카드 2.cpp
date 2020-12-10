//https://www.acmicpc.net/problem/10816

/***Solution 1: Binary Search***/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lower_bound(int left, int right, int x, vector<int> arr)
{
	while (left < right)
	{
		int mid = (left + right) / 2;

		if (arr[mid] < x)
			left = mid;
		else
			right = mid - 1;
	}

	return left;
}

int upper_bound(int left, int right, int x, vector<int> arr)
{
	while (left < right)
	{
		int mid = (left + right) / 2;

		if (arr[mid] <= x)
			left = mid + 1;
		else
			right = mid;
	}

	return right;
}

int main()
{
	int N, M, X;
	cin >> N;

	//숫자 카드에 적힌 정수 저장 및 오름차순 정렬
	vector<int> a(N, 0);
	for (int i = 0; i < N; i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	//M개의 정수 X가 적힌 숫자 카드 개수 확인
	cin >> M;
	vector<int> answer(M, 0);
	for (int i = 0; i < M; i++)
	{
		cin >> X;
		
		//이분 탐색(STL)
		//answer[i] = upper_bound(a.begin(), a.end(), X) - lower_bound(a.begin(), a.end(), X);
		
		//이분 탐색
		answer[i] = upper_bound(0, N - 1, X, a) - lower_bound(0, N - 1, X, a);
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