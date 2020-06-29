//Codility_L4_CountingElements_PermCheck[Painless]
//https://app.codility.com/programmers/lessons/4-counting_elements/perm_check/

#include <algorithm>

int solution(vector<int>& A)
{
	int ans = 0, cnt = 0;
	sort(A.begin(), A.end());
	if (A[0] == 1)
	{
		for (int i = 0; i < A.size() - 1; i++)
		{
			if (A[i + 1] - A[i] == 1) cnt++;
		}
		if (cnt == A.size() - 1) ans = 1;
	}
	return ans;
}

//result: https://app.codility.com/demo/results/training2GCBF9-24W/
