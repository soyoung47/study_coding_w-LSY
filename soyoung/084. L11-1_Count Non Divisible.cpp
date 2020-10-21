/*
    Time Complexity: O(N * log(N))
    Result::: https://app.codility.com/demo/results/trainingTBHMCP-HNE/
    Reference::: http://dal4segno.github.io/algorithm/codility-11-sieve-of-eratosthenes/
*/
#include <algorithm>

vector<int> solution(vector<int>& A) {

    int size = A.size();
    vector<int> ans;
    vector<int> num(size * 2 + 1, 0);

    //Count elements
    for (int i = 0; i < size; i++)
    {
        num[A[i]]++;
    }

    //Count Non Divisors
    for (int i = 0; i < size; ++i)
    {
        int elemt = A[i];
        int divisor = 0;
        for (int j = 1; j * j <= elemt; ++j)
        {
            if (elemt % j == 0)
            {
                divisor += num[j];
                if (elemt / j != j)
                {
                    divisor += num[elemt / j];
                }
            }
        }

        ans.push_back(size - divisor);
    }

    return ans;
}