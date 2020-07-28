/*
    [solution 2]
    Time Complexity: O(N)
    Result:::https://app.codility.com/demo/results/training2BFGM9-ECB/
    Reference:::
*/
int solution(vector<int>& A) {

    int size = A.size();
    int maxEnd = -1000000;
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        maxEnd = (maxEnd > sum + A[i]) ? maxEnd : sum + A[i];
        sum = (0 > sum + A[i]) ? 0 : sum + A[i];
    }

    return maxEnd;
}

/*
    [solution 1]
    Time Complexity: O(N)
    Result:::https://app.codility.com/demo/results/trainingXF6PKU-ZMH/
    Reference:::https://codility.com/media/train/7-MaxSlice.pdf
*/
int solution(vector<int>& A) {

    int size = A.size();
    int slice = 0;
    int max_sum = -1000000;

    for (int i = 0; i < size; i++)
    {
        slice = (-1000000 > slice + A[i]) ? -1000000 : slice + A[i];
        slice = (slice > A[i]) ? slice : A[i];
        max_sum = (max_sum > slice) ? max_sum : slice;
    }

    return max_sum;
}
