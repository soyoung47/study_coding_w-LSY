/*
    Time Complexity: O(log(N + M))
    Result::: https://app.codility.com/demo/results/trainingMUVMJM-B7M/
*/
#include <vector>
#include <math.h>
#include <algorithm>

int solution(int N, int M) {

    int gcf = 0;
    int min = M;

    if (N < M)  min = N;

    //Find divisor(min의 약수)
    vector<int> div;
    for (int i = 1; i <= sqrt(min); i++)
    {
        if (min % i == 0)
        {
            div.push_back(i);
            if (i != sqrt(min))
                div.push_back(min / i);
        }
    }
    sort(div.begin(), div.end());

    //Find Greatest common factor (최대공약수)
    for (int i = div.size() - 1; i >= 0; i--)
    {
        if (N % div[i] == 0 && M % div[i] == 0)
        {
            gcf = div[i];
            break;
        }
    }

    return N / gcf;
}
