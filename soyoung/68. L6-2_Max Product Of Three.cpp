/*
    Time Complexity: O(N * log(N))
    Result:::https://app.codility.com/demo/results/trainingGBNYBN-UJJ/
*/
#include <algorithm>

int solution(vector<int>& A) {

    int product1 = 0; // -,-,+
    int product2 = 0; // +,+,+

    sort(A.begin(), A.end());
    product1 = A[0] * A[1];

    sort(A.begin(), A.end(), greater<int>());
    product1 = product1 * A[0];
    product2 = A[0] * A[1] * A[2];

    if (product1 > product2)
        return product1;
    else
        return product2;
}