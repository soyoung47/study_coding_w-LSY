/*
    Time Complexity: O(N*log(N+M))
    Result::: https://app.codility.com/demo/results/training4YEGTT-B26/
    Reference::: https://blog.naver.com/simjy07/221806586831, http://dal4segno.github.io/algorithm/codility-14-binary-search-algorithm/
*/
using namespace std;
#include <vector>

#include <algorithm>

bool isDivided(int mid, int k, vector<int> &A)
{
    int sum = 0;

    for (int i = 0; i < A.size(); i++)
    {
        sum += A[i];
        if (sum > mid)
        {
            sum = A[i];
            k--;
        }
        if (k < 0) return false;
    }
    return true;
}
int solution(int K, int M, vector<int>& A)
{
    //find sum of array A(MAX) and max element of array A(MIN)
    int sum = 0, max = A[0];
    for (int i = 0; i < A.size(); i++)
    {
        max = (max > A[i]) ? max : A[i];
        sum += A[i];
    }

    int MAX = sum, MIN = max, ans = MAX;
    while (MIN <= MAX)
    {
        int mid = (MIN + MAX) / 2;
        if (isDivided(mid, K - 1, A))
        {
            MAX = mid - 1;
            ans = mid;
        }
        else
            MIN = mid + 1;
    }
    return ans;
}