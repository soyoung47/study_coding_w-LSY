//Codility_L6-4_Sorting_Triangle[Painless]
//https://app.codility.com/programmers/lessons/6-sorting/triangle/

#include <algorithm>

int solution(vector<int>& A)
{
	sort(A.begin(), A.end());
	if (A.size() < 3) return 0;
	for (int i = 0; i < int(A.size()) - 2; i++)
	{
		if (A[i + 1] > A[i + 2] - A[i]) return 1;
	}
	return 0;
}

//result:
//93%, extreme_arith_overflow1
//https://app.codility.com/demo/results/trainingCAZ7VH-M2G/
//100%, O(N*log(N))
//https://app.codility.com/demo/results/training7VDV9F-6FD/ 

//ref:
//https://siyoon210.tistory.com/128
//https://hwan-shell.tistory.com/102
