//Codility_L4-3_CountingElements_MissingInteger[Respectable]
//https://app.codility.com/programmers/lessons/4-counting_elements/missing_integer/

int solution(vector<int>& A)
{
	int N = A.size();
	vector<int> counter(N + 1);

	for (int i = 0; i < N; i++)
	{
		if ((A[i] > 0) && (A[i] <= N + 1)) counter[A[i] - 1] = 1;
	}
	for (int i = 0; i < N + 1; i++)
	{
		if (!(counter[i])) return i + 1;
	}
}

//result: https://app.codility.com/demo/results/trainingF53GA9-PR4/
//ref: https://sites.google.com/a/student.liu.se/h-sedghamiz/c-optimized-programming/missing-integer
