#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> solution(string& S, vector<int>& P, vector<int>& Q)
{
	int lenS = S.size();
	int numQ = P.size();
	vector<int> ans(numQ, 0);
	vector<int> sumA(lenS, 0);
	vector<int> sumC(lenS, 0);
	vector<int> sumG(lenS, 0);
	vector<int> sumT(lenS, 0);

	for (int i = 0; i < lenS; i++)
	{
		switch (S[i])
		{
		case 'A':
			sumA[i]++;
			break;
		case 'C':
			sumC[i]++;
			break;
		case 'G':
			sumG[i]++;
			break;
		case 'T':
			sumT[i]++;
			break;
		}
	}

	for (int i = 1; i < lenS; i++)
	{
		sumA[i] += sumA[i - 1];
		sumC[i] += sumC[i - 1];
		sumG[i] += sumG[i - 1];
		sumT[i] += sumT[i - 1];
	}

	for (int i = 0; i < numQ; i++)
	{
		if (Q[i] == P[i])
		{
			if (S[P[i]] == 'T') ans[i] = 4;
			else if (S[P[i]] == 'G') ans[i] = 3;
			else if (S[P[i]] == 'C') ans[i] = 2;
			else if (S[P[i]] == 'A') ans[i] = 1;
		}
		else
		{
			if (sumT[Q[i]] - sumT[P[i]] > 0) ans[i] = 4;
			if (sumG[Q[i]] - sumG[P[i]] > 0) ans[i] = 3;
			if (sumC[Q[i]] - sumC[P[i]] > 0) ans[i] = 2;
			if (sumA[Q[i]] - sumA[P[i]] > 0) ans[i] = 1;
		}
	}
	return ans;
}

int main()
{
	string S = "CAGCCTA";
	vector<int> P = { 2,5,0 };
	vector<int> Q = { 4,5,6 };
	solution(S, P, Q);
	return 0;
}
