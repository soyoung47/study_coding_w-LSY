/*
    Time Complexity: O(N)
    Result:::https://app.codility.com/demo/results/trainingGK78DX-NRD/
*/
#include <algorithm>

int solution(vector<int>& A) {

    int leader = 0;
    int cnt = 0;

    int size = A.size();
    vector<int> c_sum(size, 0);
    vector<int> B = A;

    sort(B.begin(), B.end());
    leader = B[size / 2];

    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (A[i] == leader)  sum++;
        c_sum[i] = sum;
    }

    if (sum < size / 2)    return 0;

    for (int j = 1; j < size; j++)
    {
        if ((j / 2 < c_sum[j - 1]) && ((size - j) / 2 < c_sum[size - 1] - c_sum[j - 1]))
            cnt++;
    }

    return cnt;
}
