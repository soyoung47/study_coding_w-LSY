/*
    Time Complexity: O(N * log(N))
    Result::: https://app.codility.com/demo/results/trainingARKJ3N-7N2/
    Reference::: http://dal4segno.github.io/algorithm/codility-13-fibonacci-numbers/
*/

#include <algorithm>
#include <queue>

int solution(vector<int>& A) {

    int N = A.size();

    //Fill Array fib (Fibonacci)
    vector<int> fib = { 0, 1 };
    for (int i = 2; fib.back() <= N + 1; i++)
    {
        fib.push_back(fib[i - 1] + fib[i - 2]);
    }
    reverse(fib.begin(), fib.end());

    //BFS: find minimum number of jump count
    vector<bool> visit(N, false);
    queue<pair<int, int>> leaves;   //current position, jump count
    leaves.push(make_pair(-1, 0));  //start : -1

    while (!leaves.empty())
    {
        pair<int, int> leaf = leaves.front();
        leaves.pop();

        for (int i = 0; i < fib.size(); i++)
        {
            int cur = leaf.first + fib[i];
            if (cur == N)
                return leaf.second + 1;
            else if (cur < N && A[cur] == 1 && !visit[cur])
            {
                leaves.push(make_pair(cur, leaf.second + 1));
                visit[cur] = true;
            }
        }
    }

    return -1;
}