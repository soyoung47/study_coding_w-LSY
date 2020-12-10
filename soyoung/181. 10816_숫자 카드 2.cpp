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

	//���� ī�忡 ���� ���� ���� �� �������� ����
	vector<int> a(N, 0);
	for (int i = 0; i < N; i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	//M���� ���� X�� ���� ���� ī�� ���� Ȯ��
	cin >> M;
	vector<int> answer(M, 0);
	for (int i = 0; i < M; i++)
	{
		cin >> X;
		
		//�̺� Ž��(STL)
		//answer[i] = upper_bound(a.begin(), a.end(), X) - lower_bound(a.begin(), a.end(), X);
		
		//�̺� Ž��
		answer[i] = upper_bound(0, N - 1, X, a) - lower_bound(0, N - 1, X, a);
	}

	//���� ���
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

	//���� ī�忡 ���� ���� ����
	unordered_map<int, int> card;
	int tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		card[tmp]++;
	}

	//M���� ���� X�� ���� ���� ī�� ���� Ȯ��
	cin >> M;
	vector<int> answer(M, 0);
	for (int i = 0; i < M; i++)
	{
		cin >> X;

		if (card.find(X) != card.end())
			answer[i] = card[X];
	}

	//���� ���
	for (int ans : answer)
		cout << ans << "\n";
}