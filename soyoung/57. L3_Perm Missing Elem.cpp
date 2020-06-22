//time complexity : O(N) or O(N * log(N))
//https://app.codility.com/demo/results/training54N9UQ-PTX/
#include <algorithm>

int solution(vector<int>& A) {
    //A = {1, ... , N+1}

    sort(A.begin(), A.end());

    for (int i = 1; i <= A.size(); i++)
    {
        if (A[i - 1] != i)
            return i;
    }

    //A: empty or {1};
    return A.size() + 1;

}