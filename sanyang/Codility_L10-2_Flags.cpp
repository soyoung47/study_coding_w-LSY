//Codility_L10-2_PrimeAndCompositeNumbers_Flags[Respectable]
//https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/flags/

int solution(vector<int>& A)
{
	vector<int> Peak;
	for (int i = 1; i<int(A.size()) - 1; i++)
	{
		if (A[i - 1] < A[i] && A[i] > A[i + 1]) Peak.push_back(i);
	}
	if (Peak.size() < 2) return Peak.size();
	for (int i = 2; i <= Peak.size(); i++)
	{
		int flag = 1;
		int current = Peak[0];
		for (int j = 1; j < Peak.size(); j++)
		{
			if (flag >= i) break;
			if (Peak[j] - current >= i)
			{
				flag++;
				current = Peak[j];
			}
		}
		if (flag < i) return i - 1;
	}
	return Peak.size();
}

//result O(N): https://app.codility.com/demo/results/training8J4A3R-N6K/
//ref: http://dal4segno.github.io/algorithm/codility-10-primes-and-composite-numbers/
