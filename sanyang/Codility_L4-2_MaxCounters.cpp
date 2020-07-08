//Codility_L4-2_CountingElements_MaxCounters[Respectable]
//https://app.codility.com/programmers/lessons/4-counting_elements/max_counters/

vector<int> solution(int N, vector<int>& A)
{
	vector<int> counter(N, 0);
	int max = 0, tmpMax = 0;
	for (int i = 0; i<int(A.size()); i++)
	{
		if (A[i] > N) max = tmpMax;
		else
		{
			if (counter[A[i] - 1] < max) counter[A[i] - 1] = max;
			counter[A[i] - 1]++;
			if (counter[A[i] - 1] > tmpMax) tmpMax = counter[A[i] - 1];
		}
	}
	if (max > 0)
	{
		for (int i = 0; i<int(counter.size()); i++)
		{
			if (counter[i] < max) counter[i] = max;
		}
	}
	return counter;
}

//result: https://app.codility.com/demo/results/trainingRN2ZMX-4NZ/ 100%
//ref: https://stroot.tistory.com/93#recentEntries
