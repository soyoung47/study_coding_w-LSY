/*
    Time Complexity: O(N)
    Result:::https://app.codility.com/demo/results/trainingT76BMA-XZ4/
*/
int solution(vector<int>& A) {

    int N = A.size();
    vector<double> sum(1);
    double a = 0;
    for (int i = 0; i <= N; i++)
    {
        a += A[i];
        sum.push_back(a);
    }

    double min = 999999999;
    int ans = N + 1;

    //slice 2
    for (int p = 0; p < N - 1; p++)
    {
        double avg = (sum[p + 2] - sum[p]) / 2;
        if (min > avg)
        {
            min = avg;
            ans = p;
        }
    }

    //slice 3
    for (int p = 0; p < N - 2; p++)
    {
        double avg = (sum[p + 3] - sum[p]) / 3;
        if (min > avg)
        {
            min = avg;
            ans = p;
        }
    }

    return ans;
}
