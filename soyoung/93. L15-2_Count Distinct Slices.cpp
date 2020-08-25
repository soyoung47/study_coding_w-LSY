/*
    Time Complexity: O(N)
    Result::: https://app.codility.com/demo/results/training2MNTBP-RAH/
*/
#include <unordered_map>

int solution(int M, vector<int>& A)
{
    int N = A.size();
    if (N == 1)  return 1;

    int cnt = 0, fwd = 0, end = -1;
    unordered_map<int, int> m;  //value, index
    for (int i = 0; i < N; i++)
    {
        m[A[i]] = i;
        if (i == N - 1 || (m.count(A[i + 1]) > 0 && m[A[i + 1]] >= fwd))
        {
            int size = i - fwd + 1;
            int overlap = end - fwd + 1;
            cnt += (size * (size + 1) - overlap * (overlap + 1)) / 2;
            fwd = m[A[i+1]] + 1;
            end = i;
        }   
    }

    return cnt;
}