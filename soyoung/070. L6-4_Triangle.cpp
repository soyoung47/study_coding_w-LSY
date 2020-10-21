/*
    [solution 2]
    Time Complexity: O(N*log(N))
    Result:::https://app.codility.com/demo/results/trainingRFPHPV-5DV/
    Reference:::https://medium.com/@molchevsky/best-solutions-for-codility-lessons-lesson-6-sorting-770f931b65ad
*/
#include <algorithm>

int solution(vector<int>& A) {

    //triangular triplet : N >= 3
    if (A.size() < 3)    return 0;

    sort(A.begin(), A.end());

    for (int i = 0; i < A.size() - 2; i++)
    {
        //A[P] + A[Q] > A[R]
        if (A[i] > A[i + 2] - A[i + 1])
            return 1;
    }

    return 0;
}

/*
    [solution 1]
    Time Complexity: O(N*log(N))
    Result:::https://app.codility.com/demo/results/training2G87FN-89Q/
*/
#include <algorithm>

int solution(vector<int>& A) {

    //triangular triplet : N >= 3
    if (A.size() < 3)    return 0;

    sort(A.begin(), A.end());

    for (int i = 0; i < A.size() - 2; i++)
    {
        //A[P], A[Q], A[R] > 0
        if (A[i] <= 0) continue;

        long long P = (long long)A[i];
        long long Q = (long long)A[i + 1];
        long long R = (long long)A[i + 2];

        if ((2 * Q > R) && (P + Q > R))
            return 1;
    }

    return 0;
}
