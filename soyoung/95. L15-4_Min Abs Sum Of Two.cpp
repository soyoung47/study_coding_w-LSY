/*
    Time Complexity: O(N * log(N))
    Result::: https://app.codility.com/demo/results/trainingWYN4NK-A9A/
*/
#include <map>

int solution(vector<int>& A)
{
    int N = A.size();
    if (N == 1)  return abs(A[N - 1] * 2);

    //Insert array A into map
    map<int, int> m;
    bool plus = false, minus = false;
    for (int i = 0; i < N; i++)
    {
        //isPlus
        if (A[i] >= 0)
        {
            if (m[A[i]] == -1)   return 0;
            m[A[i]] = 1;
            plus = true;
        }
        //isMinus
        else
        {
            if (m[abs(A[i])] == 1)   return 0;
            m[abs(A[i])] = -1;
            minus = true;
        }
    }

    //Find minimum bas sum of two
    int min = 2000000001;
    if (plus && minus)
    {
        pair<int, int> fwd = { 0,0 };

        for (auto iter : m)
        {
            if (iter.second * fwd.second < 0)
            {
                int sum = abs(iter.first - fwd.first);
                min = (min < sum) ? min : sum;
            }

            fwd = iter;
        }
    }
    else //all plus : min of + elements, all minus : max of - elements
    {
        auto iter = m.begin();
        return iter->first * 2;
    }

    return min;
}