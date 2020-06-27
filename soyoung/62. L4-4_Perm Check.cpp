//time complexity: O(N) or O(N * log(N))
//https://app.codility.com/demo/results/training6JGJS6-BBR/

#include <algorithm>

int solution(vector<int>& A) {

    sort(A.begin(), A.end());

    for (int i = 1; i <= A.size(); i++)
    {
        if (A[i - 1] != i)
            return 0;
    }

    return 1;
}