/*
    Time Complexity: O(sqrt(N))
    Result:::https://app.codility.com/demo/results/trainingPQNDRZ-RAV/
*/
#include <math.h>

int solution(int N) {

    int cnt = 0;

    for (int i = 1; i <= sqrt(N); i++)
    {
        if (N % i == 0)
        {
            cnt += 2;
            if (N / i == i)
                cnt--;
        }
    }

    return cnt;
}
