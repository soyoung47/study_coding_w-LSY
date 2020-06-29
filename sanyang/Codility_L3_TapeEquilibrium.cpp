//Codility_L3_TimeComplexity_TapeEquilibrium[Painless]
//https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/

int solution(vector<int>& A)
{
	int sum = 0, partSum = 0, max = 100000, tmp = 0;;
	for (int i = 0; i < A.size(); i++) sum += A[i];
	for (int i = 0; i < A.size()-1; i++)
	{
		partSum += A[i];
		int left = sum - partSum;
		tmp = partSum - left;
		if (tmp < 0) tmp *= -1;
		if (tmp < max) max = tmp;
	}
	return max;
}

//result: https://app.codility.com/demo/results/trainingJXE9PK-JTR/
