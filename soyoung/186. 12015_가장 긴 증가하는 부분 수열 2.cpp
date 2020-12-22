//https://www.acmicpc.net/problem/12015

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, Ai, ind;	//���� A�� ũ��, ���� A�� ����, index��
	vector<int> sub_A;	//�κ� ����
	
	cin >> N;

	while (N--)
	{
		cin >> Ai;

		ind = lower_bound(sub_A.begin(), sub_A.end(), Ai) - sub_A.begin();

		if (ind == sub_A.size())
			sub_A.emplace_back(Ai);
		else
			sub_A[ind] = Ai;
	}

	cout << sub_A.size();
}

//BOJ_2352_�ݵ�ü ����