/*
    Time Complexity: O(sqrt(N))
    Result:::https://app.codility.com/demo/results/training74RU83-44G/
*/
#include <math.h>

int solution(int N) {

    int perimeter = 0;
    int min = 2 * (1 + N);

    for (int i = 2; i <= sqrt(N); i++)
    {
        if (N % i == 0)
        {
            perimeter = 2 * (i + N/i);
            min = (min < perimeter) ? min : perimeter;
        }
    }

    return min;
}
