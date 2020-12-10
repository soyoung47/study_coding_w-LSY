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

	//�迭 A ���� �� �������� ����
	vector<int> arr_A(N, 0);

	for (int i = 0; i < N; i++)
		cin >> arr_A[i];

	sort(arr_A.begin(), arr_A.end());

	//M���� X �� A �迭�� �����ϴ��� Ȯ��
	cin >> M;
	vector<int> answer(M, 0);
	for (int i = 0; i < M; i++)
	{
		cin >> X;

		int left = 0, right = N - 1;

		//�̺� Ž��
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

	//���� ���
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

	//N���� ���� ����
	unordered_set<int> A;
	int tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		A.insert(tmp);
	}

	//M���� ���� X�� A�� �����ϴ��� Ȯ��
	cin >> M;
	vector<int> answer(M, 0);
	for (int i = 0; i < M; i++)
	{
		cin >> X;

		if (A.count(X) > 0)
			answer[i] = 1;
	}

	//���� ���
	for (int ans : answer)
		cout << ans << "\n";
}

//�̺� Ž���� �� ���� ����
//https://www.acmicpc.net/board/view/24511