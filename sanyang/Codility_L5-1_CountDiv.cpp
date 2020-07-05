//Codility_L5-1_PrefixSums_CountDiv[Respectable]
//https://app.codility.com/programmers/lessons/5-prefix_sums/count_div/

int solution(int A, int B, int K)
{
    int ans = B/K - A/K;
    if ((A%K)==0) ans++;
    return ans;
}

//result: https://app.codility.com/demo/results/training4R69UF-A8B/
