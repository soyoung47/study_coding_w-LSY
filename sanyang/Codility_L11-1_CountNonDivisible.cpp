//Codility_L11-1_SieveOfEratosthenes_CountNonDivisible[Respectable]
//https://app.codility.com/programmers/lessons/11-sieve_of_eratosthenes/count_non_divisible/

vector<int> solution(vector<int>& A)
{
	int sizeA = int(A.size());
	vector<int> elem(2 * sizeA + 1, 0);

	for (int a : A) elem[a]++;

	vector<int> count;
	for (int a : A)
	{
		int div = 0;
		for (int i = 1; i * i <= a; i++)
		{
			if (a % i == 0)
			{
				div += elem[i];
				if (a / i != i) div += elem[a / i];
			}
		}
		count.push_back(sizeA - div);
	}
	return count;
}

//result O(N * log(N)): https://app.codility.com/demo/results/trainingSCQS8K-TS3/
//ref: http://dal4segno.github.io/algorithm/codility-11-sieve-of-eratosthenes/
