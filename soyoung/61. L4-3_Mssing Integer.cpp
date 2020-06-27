//time complexity: O(N) or O(N * log(N))
//https://app.codility.com/demo/results/trainingF666CB-BQV/

#include <algorithm>

int solution(vector<int>& A) {

    sort(A.begin(), A.end());

    int k = 1;

    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] < k)  continue;

        if (A[i] == k)
            k++;
        else
            return k;
    }

    return k;
}
