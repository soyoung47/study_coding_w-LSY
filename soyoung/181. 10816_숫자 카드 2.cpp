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

	//���� ī�忡 ���� ���� ���� �� �������� ����
	int tmp = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		arr.emplace_back(tmp);
	}

	sort(arr.begin(), arr.end());


	//M���� ���� X�� ���� ���� ī�� ���� Ȯ��
	cin >> M;
	vector<int> answer(M, 0);
	for (int i = 0; i < M; i++)
	{
		cin >> X;

		//�̺� Ž��(STL)
		//answer[i] = upper_bound(arr.begin(), arr.end(), X) - lower_bound(arr.begin(), arr.end(), X);

		//�̺� Ž��(����)
		answer[i] = up_bound(0, N) - low_bound(0, N);
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