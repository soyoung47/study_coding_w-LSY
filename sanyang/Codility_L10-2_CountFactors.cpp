//Codility_L10-2_PrimgAndCompositeNumbers_CountFactors
//https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/count_factors/

int solution(int N)
{
	int cnt = 0;
	int i = 1;
	while (i*i < (unsigned int)N)
	{
		if (N % i == 0)	cnt += 2;
		i++;
	}
	if (i * i == N)	cnt++;
	return cnt;
}

//result 92% (int): https://app.codility.com/demo/results/training8RAFXD-MHM/
//results 100% (unsigned int): https://app.codility.com/demo/results/training8RAFXD-MHM/
