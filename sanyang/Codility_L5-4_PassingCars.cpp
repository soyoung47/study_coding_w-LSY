//Codility_L5-4_PrefixSums_PassingCars[Painless]
//https://app.codility.com/programmers/lessons/5-prefix_sums/passing_cars/

int solution(vector<int>& A)
{
	int cnt = 0, cnt_zero = 0;
	for (int i = 0; i<int(A.size()); i++)
	{
		if (A[i] == 0) cnt_zero++;
		if (A[i] == 1) cnt += cnt_zero;
		if (cnt > 1000000000) return -1;
	}
	return cnt;
}

//result: https://app.codility.com/demo/results/trainingG8SMR2-GZM/ 100%
//ref: https://a1010100z.tistory.com/53
