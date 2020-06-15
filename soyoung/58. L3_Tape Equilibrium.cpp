//time complexity : O(N)

int solution(vector<int>& A) {

    int min = 110000000;
    vector<int> sum_A;
    int N = A.size();

    //sum array A
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += A[i];
        sum_A.push_back(sum);
    }

    //check difference
    for (int p = 1; p < N; p++)
    {
        int diff = abs(sum_A[N - 1] - sum_A[p - 1] * 2);

        if (min > diff)
            min = diff;
    }

    return min;
}
