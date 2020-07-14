//Codility_L6-3_Sorting_NumberOfDiscIntersections[Respectable]
//https://app.codility.com/programmers/lessons/6-sorting/number_of_disc_intersections/

int solution(vector<int>& A)
{
	int sum = 0;
	vector<int> start(A.size(), 0);
	vector<int> end(A.size(), 0);
	for (int i = 0; i<int(A.size()); i++)
	{
		if (i < A[i]) start[0]++;
		else start[i - A[i]]++;
		if (i + A[i] >= A.size()) end[A.size() - 1]++;
		else end[i + A[i]]++;
	}
	int active = 0;
	for (int i = 0; i < int(A.size()); i++)
	{
		sum += active * start[i] + (start[i] * (start[i] - 1)) / 2;
		if (sum > 10000000) return -1;
		active += start[i] - end[i];
	}
	return sum;
}

//result (100%, O(N*log(N)) or O(N)):
//https://app.codility.com/demo/results/trainingCUC566-PWT/ 

//ref: https://stackoverflow.com/questions/4801242/algorithm-to-calculate-number-of-intersecting-discs
