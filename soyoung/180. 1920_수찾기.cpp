//https://www.acmicpc.net/problem/1920

/***Solution 1: Binary Search***/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N, M, X;
	cin >> N;

	//배열 A 저장 및 오름차순 정렬
	vector<int> arr_A(N, 0);

	for (int i = 0; i < N; i++)
		cin >> arr_A[i];

	sort(arr_A.begin(), arr_A.end());

	//M개의 X 중 A 배열에 존재하는지 확인
	cin >> M;
	vector<int> answer(M, 0);
	for (int i = 0; i < M; i++)
	{
		cin >> X;

		int left = 0, right = N - 1;

		//이분 탐색
		while (left <= right)
		{
			int mid = (left + right) / 2;

			if (arr_A[mid] < X)
				left = mid + 1;
			else if (arr_A[mid] > X)
				right = mid - 1;
			else
			{
				answer[i] = 1;
				break;
			}
		}
	}

	//정답 출력
	for (int ans : answer)
		cout << ans << "\n";
}

/***Solution 2: Hash***/
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main()
{
	int N, M, X;
	cin >> N;

	//N개의 정수 저장
	unordered_set<int> A;
	int tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		A.insert(tmp);
	}

	//M개의 정수 X중 A에 존재하는지 확인
	cin >> M;
	vector<int> answer(M, 0);
	for (int i = 0; i < M; i++)
	{
		cin >> X;

		if (A.count(X) > 0)
			answer[i] = 1;
	}

	//정답 출력
	for (int ans : answer)
		cout << ans << "\n";
}

//이분 탐색이 더 빠른 이유
//https://www.acmicpc.net/board/view/24511