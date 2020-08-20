//Codility_L12-2_EuclideanAlgorithm_CommonPrimeDivisors[Respectable]
//https://app.codility.com/programmers/lessons/12-euclidean_algorithm/common_prime_divisors/

#include <vector>

int GCD(int N, int M)
{
    if (N % M == 0) return M;
    else return GCD(M, N % M);
}

bool samePD(int N, int M)
{
    int gcd;
    while ((gcd = GCD(N, M)) != 1) N /= gcd;
    return N == 1;
}

int solution(vector<int> &A, vector<int> &B)
{
    int cnt = 0;
    for (int i=0; i<int(A.size()); i++)
    {
        if (samePD(A[i], B[i]) && samePD(B[i], A[i])) cnt++;
    }
    return cnt;
}

//result O(Z * log(max(A) + max(B))**2): https://app.codility.com/demo/results/trainingQ5CB52-H9Y/
