/*
    Time Complexity: O(N * log(log(N)) + M)
    Result::: https://app.codility.com/demo/results/trainingP3USGY-98B/
*/
#include <math.h>
#include <algorithm>

vector<int> solution(int N, vector<int>& P, vector<int>& Q) {

    int n = N / 2;
    vector<int> ans;

    //find prime (에라토스테네스의 체)
    vector<bool> prime(n+1, true);
    for (int i = 2; i <= sqrt(n); i++)      //i: divisor
    {
        if (!prime[i])   continue;
        for (int j = i * 2; j <= n; j += i) //i제외하고 i배수 제거
        {
            prime[j] = false;
        }
    }

    //find semiprime
    vector<int> semi;
    for (int i = 2; i <= n; i++)
    {
        if (!prime[i])   continue;
        for (int j = i; j <= n; j++)
        {
            if (!prime[j])   continue;
            if (i * j > N) break;
            semi.push_back(i * j);
        }
    }

    sort(semi.begin(), semi.end());

    //count semiprimes in ranges
    vector<int> cnt(N + 1, 0);
    int count = 0;
    int s = 0;
    for (int i = 1; i <= N; i++)
    {
        if (s < semi.size())
        {
            if (i == semi[s])
            {
                count++;
                s++;
            }
        }
        
        cnt[i] = count;
    }

    for (int k = 0; k < P.size(); k++)
    {
        int p = cnt[P[k] - 1];
        int q = cnt[Q[k]];

        ans.push_back(q - p);
    }

    return ans;
}
