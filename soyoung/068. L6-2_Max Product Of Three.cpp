/*
    [solution 2]
    Time Complexity: O(N * log(N))
    Result:::https://app.codility.com/demo/results/trainingMT525W-C24/
*/
#include <algorithm>

int solution(vector<int>& A) {

    int product1 = 0; // -,-,+
    int product2 = 0; // +,+,+
    int size = A.size();

    sort(A.begin(), A.end());
    product1 = A[0] * A[1] * A[size-1];
    product2 = A[size - 1] * A[size - 2] * A[size - 3];

    return (product1 > product2) ? product1 : product2;
}

/*
    [solution 1]
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
