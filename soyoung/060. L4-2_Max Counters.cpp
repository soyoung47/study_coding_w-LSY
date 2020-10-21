//time complexity: O(N+M)
//https://app.codility.com/demo/results/training749ZC4-GNV/

vector<int> solution(int N, vector<int>& A) {

    vector<int> ans(N, 0);
    int max_cnt = 0;
    int base = 0;

    int size = A.size();
    for (int i = 0; i < size; i++)
    {
        int k = A[i] - 1;
        if (k == N)
        {
            base = max_cnt;
        }
        else
        {
            if (ans[k] < base)
                ans[k] = base + 1;
            else
                ans[k]++;

            if (max_cnt < ans[k])
                max_cnt = ans[k];
        }
    }

    for (int j = 0; j < N; j++)
    {
        if (ans[j] < base)
            ans[j] = base;
    }

    return ans;
}