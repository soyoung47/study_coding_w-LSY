//Codility_L3-2_TimeComplexity_PermMissingElem[Painless]
//https://app.codility.com/programmers/lessons/3-time_complexity/

#include <algorithm>

int solution(vector<int>& A)
{
	int ans = 0;
	int maxV = A.size() + 1;
	int Asum = 0, Rsum = 0;
	for (int i = 1; i <= maxV; i++)	Asum += i;
	for (int i = 0; i < A.size(); i++)	Rsum += A[i];
	ans = Asum - Rsum;
	return ans;
}

//result: https://app.codility.com/demo/results/training5BGZZ3-32F/ 
