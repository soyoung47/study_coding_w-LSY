/*
    Time Complexity: O(L)
    Result::: https://app.codility.com/demo/results/trainingRHKRK8-R43/
*/

#include <math.h>

vector<int> solution(vector<int>& A, vector<int>& B) {

    int size = A.size();

    //Ladder N = 0,1,2
    vector<int> ladder(size + 1, 0);
    ladder[1] = 1, ladder[2] = 2;

    //Find Max elements in array A
    int max = 1;
    for (int i = 0; i < size; i++)
        max = (max > A[i]) ? max : A[i];

    //Fill Array Ladder(Fibonacci)
    for (int i = 3; i <= max; i++)
    {
        ladder[i] = ladder[i - 1] + ladder[i - 2];
    }

    //return Result(ladder) % 2^B[i]
    vector<int> ans;
    for (int i = 0; i < size; i++)
    {
        int cnt = ladder[A[i]];
        int answer = cnt % (unsigned int)pow(2, B[i]);
        ans.push_back(answer);
    }

    return ans;
}