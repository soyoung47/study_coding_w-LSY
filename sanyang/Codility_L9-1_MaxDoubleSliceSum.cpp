//Codility_L9-1_MaximumSliceProblem_MaxDoubleSliceSum[Respectable]
//https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_double_slice_sum/

#include <algorithm>

int solution(vector<int>& A)
{
	if (int(A.size()) == 3) return 0;
	int len = int(A.size()), res = 0;
	vector<int> left_max(len);
	vector<int> right_max(len);
	for (int i = 1; i < len - 1; i++)
		left_max[i] = max(left_max[i - 1] + A[i], 0);
	for (int i = len - 1; i > 1; i--)
		right_max[i - 1] = max(right_max[i] + A[i - 1], 0);
	for (int i = 1; i < len - 1; i++)
		res = max(left_max[i - 1] + right_max[i + 1], res);
	return res;
}

//result O(N): https://app.codility.com/demo/results/training2GE86N-688/
//ref: https://hwan-shell.tistory.com/124
