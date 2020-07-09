//Codility_L6-1_Sorting_Distinct[Painless]
//https://app.codility.com/programmers/lessons/6-sorting/distinct/

int solution(vector<int>& A)
{
	int arr[20000001] = { 0 };
	int cnt = 0;
	for (int i = 0; i<int(A.size()); i++)
	{
		if (arr[A[i] + 1000000] == 0)
		{
			arr[A[i] + 1000000] = 1;
			cnt++;
		}
	}
	return cnt;
}

//result(100%): https://app.codility.com/demo/results/trainingXYJZ7G-HKY/
