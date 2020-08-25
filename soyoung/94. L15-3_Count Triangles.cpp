/*
    Time Complexity: O(N**2)
    Result::: https://app.codility.com/demo/results/trainingX7K5QM-ADC/
    Reference::: https://app.codility.com/demo/results/trainingMJ4X6H-P9M/
*/

#include <algorithm>

int solution(vector<int>& A)
{
    int N = A.size();
    if (N < 3)   return 0;

    sort(A.begin(), A.end());

    if (A[0] + A[1] > A[N - 1])    return N * (N - 1) * (N - 2) / 6;

    int cnt = 0;
    for (int a = 0; a < N - 2; a++)
    {
        for (int b = a + 1; b < N - 1; b++)
        {
            for (int c = b + 1; c < N; c++)
            {
                if (A[a] > A[c] - A[b])
                    cnt++;
                else
                    break;
            }
        }
    }

    return cnt;
}