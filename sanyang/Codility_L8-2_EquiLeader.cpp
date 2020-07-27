//Codility_L8-2_Leader_EquiLeader[Painless]
//https://app.codility.com/programmers/lessons/8-leader/equi_leader/

#include <algorithm>
#include <map>

int solution(vector<int>& A)
{
	map<int, int> m;
	int maxV = 0, ind = 0, res = 0, cnt = 0;
	
	for (int i = 0; i<int(A.size()); i++)
	{
		m[A[i]] += 1;
		if (maxV < m[A[i]])
		{
			maxV = m[A[i]];
			ind = A[i];
		}
	}
	
	if (maxV < int(A.size()) / 2) return 0;

	for (int i = 0; i<int(A.size()); i++)
	{
		if (A[i] == ind)
		{
			cnt++;
			m[ind]--;
		}
		if (m[ind] > (int(A.size()) - (i + 1)) / 2 && cnt > (i + 1) / 2) res++;
	}
	return res;
}

//res O(N): https://app.codility.com/demo/results/trainingN99EXD-2MH/
//ref: https://hwan-shell.tistory.com/112
