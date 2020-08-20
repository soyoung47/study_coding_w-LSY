//Codility_L12-1_EuclideanAlgorithm_ChocolatesByNumbers[Painless]
//https://app.codility.com/programmers/lessons/12-euclidean_algorithm/chocolates_by_numbers/

#include <vector>

int GCD(int N, int M)
{
    if (N % M == 0) return M;
    else return GCD(M, N % M);
}

int solution(int N, int M)
{
    int valGCD = GCD(N, M);
    return N / valGCD;
}

//result O(log(N + M)): https://app.codility.com/demo/results/trainingPNJM5E-AHT/
