//Codility_L11-2_SieveOfEratosthenes_CountSemiprimes[Respectable]
//https://app.codility.com/programmers/lessons/11-sieve_of_eratosthenes/count_semiprimes/

vector<int> makePrimes(int N)
{
	vector<int> primes(N, -1);
	int c = 2;
	while (c * c < N)
	{
		int ii = c * 2;
		while (ii < N)
		{
			primes[ii] = c;
			ii += c;
		}
		c += 1;
	}
	return primes;
}

vector<int> solution(int N, vector<int>& P, vector<int>& Q)
{
	N = N + 1;
	vector<int> primes = makePrimes(N);
	vector<int> prefix(N, 0);
	for (int i = 1; i < N; i++)
	{
		prefix[i] = prefix[i - 1];
		int firstFactor = primes[i];
		int secondFactor = i / firstFactor;
		if (primes[i] != -1 && primes[firstFactor] == -1 && primes[secondFactor] == -1)
			prefix[i] += 1;
	}
	
	vector<int> result;
	for (int i = 0; i<int(P.size()); i++)
		result.push_back(prefix[Q[i]] - prefix[P[i] - 1]);
	return result;
}

//result O(N * log(log(N)) + M): https://app.codility.com/demo/results/trainingH8TGMV-A8R/
//ref: https://codesays.com/2014/solution-to-count-semiprimes-by-codility/
