//Codility_L9-3_MaximumSliceProblem_MaxSliceSum[Painless]
//https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_slice_sum/

#define minV -1000000
#include <algorithm>

int solution(vector<int>& A)
{
	int maxSlice = 0, maxEnd = minV;
	for (int i = 0; i<int(A.size()); i++)
	{
		maxEnd = max(maxEnd, maxSlice + A[i]);
		maxSlice = max(0, maxSlice + A[i]);
	}
	return maxEnd;
}

//res: https://app.codility.com/demo/results/trainingTMPUQ4-MUG/
//ref1: https://codility.com/media/train/7-MaxSlice.pdf
//ref2: https://nukeguys.tistory.com/188
