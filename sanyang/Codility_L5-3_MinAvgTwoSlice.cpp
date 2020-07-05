//Codility_L5-3_PrefixSums_MinAvgTwoSlice[Respectable]
//https://app.codility.com/programmers/lessons/5-prefix_sums/min_avg_two_slice/

int solution(vector<int>& A)
{
	int start = 0;
	double minAvg = 100000;

	for (int i = 0; i<int(A.size()) - 1; i++)
	{
		double avg = double((A[i] + A[i + 1])) / 2;
		if (avg < minAvg)
		{
			minAvg = avg;
			start = i;
		}
	}
	for (int i = 0; i<int(A.size()) - 2; i++)
	{
		double avg = double((A[i]+A[i+1]+A[i+2]))/3;
		if (avg < minAvg)
		{
			minAvg = avg;
			start = i;
		}
	}
	return start;
}

//result:
//https://app.codility.com/demo/results/training8PAUKS-4UN/ 60%
//https://app.codility.com/demo/results/trainingTEX7RT-Z9E/ 100%
//ref: https://nukeguys.tistory.com/175
