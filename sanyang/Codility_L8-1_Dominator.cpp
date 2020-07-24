//Codility_L8-1_Leader_Dominator[Painless]
//https://app.codility.com/programmers/lessons/8-leader/dominator/

#include <map>
#include <algorithm>

int solution(vector<int>& A)
{
	map<int, int> m;
	int maxCnt = 0, maxKey = 0;
	if (A.empty()) return -1;
	for (int i = 0; i<int(A.size()); i++)
	{
		if (m.find(A[i]) == m.end())	 m.insert(pair <int, int>(A[i], 1));//val, cnt (key, val)
		else m[A[i]] += 1;
		if (m[A[i]] > maxCnt)
		{
			maxCnt = m[A[i]];
			maxKey = i;
		}
	}
	if (maxCnt > (int(A.size() / 2))) return maxKey;
	else return -1;
}

//result O(N*log(N)) or O(N): https://app.codility.com/demo/results/trainingNTA3E6-YA8/
