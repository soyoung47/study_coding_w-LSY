/*
    [solution 2]
    Time Complexity: O(log(N + M))
    Result::: https://app.codility.com/demo/results/trainingMBU9NM-U8M/
    Reference::: https://codility.com/media/train/10-Gcd.pdf
*/

//Find Greatest common divisor (최대공약수)
int gcd(int a, int b)
{
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

int solution(int N, int M) {

    return N / gcd(N, M);
}


/*
    [solution 1]
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