//Codility_L10-4_PrimeAndCompositeNumbers_Peaks[Respectable]
//https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/peaks

int solution(vector<int>& A)
{
	vector<int> Peak;
	for (int i = 1; i<int(A.size()) - 1; i++)
	{
		if (A[i - 1] < A[i] && A[i] > A[i + 1]) Peak.push_back(i);
	}
	if (Peak.size() == 0) return 0;
	for (int i = Peak.size(); i > 0; i--)
	{
		if (A.size() % i == 0)
		{
			int sizeB = A.size() / i;
			int cnt = 0;
			for (int p : Peak)
			{
				if (cnt * sizeB <= p && p < (cnt + 1) * sizeB) cnt++;
			}
			if (cnt == i) return cnt;
		}
	}
}

//result O(N * log(log(N))): https://app.codility.com/demo/results/trainingHP69FC-4SD/
//ref: http://dal4segno.github.io/algorithm/codility-10-primes-and-composite-numbers/
