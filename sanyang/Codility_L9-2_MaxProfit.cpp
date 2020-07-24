//Codility_L9-2_MaximumSliceProblem_MaxProfit[Painless]
//https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_profit/

#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int>& A)
{
	if (int(A.size()) <= 1) return 0;
	int minV = A[0];
	int profit = 0, maxProfit = 0;
	for (int i = 1; i<int(A.size()); i++)
	{
		if (A[i] < minV) minV = A[i];
		profit = A[i] - minV;
		if (profit > maxProfit) maxProfit = profit;
	}
	if (maxProfit <= 0) return 0;
	else return maxProfit;
}

//result O(N): https://app.codility.com/demo/results/trainingYKPDX8-J8J/
