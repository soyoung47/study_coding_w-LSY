/*
    Time Complexity: O(N)
    Result:::https://app.codility.com/demo/results/trainingT7JM5T-T6N/
*/
int solution(vector<int>& A) {

    int size = A.size();
    int min = 444444;
    int profit = 0;

    if (size < 2) return profit;

    for (int i = 0; i < size; i++)
    {
        min = (min < A[i]) ? min : A[i];
        profit = (profit > A[i] - min) ? profit : A[i] - min;
    }

    return profit;
}