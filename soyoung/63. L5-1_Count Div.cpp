//time complexity: O(1)
//https://app.codility.com/demo/results/training4PEZMD-PTS/
int solution(int A, int B, int K) {

    int cnt = (B / K) - (A / K);

    if (A == 0)
        return cnt + 1;
    else if (A < K)
        return cnt;
    else
    {
        if (A % K != 0)
            return cnt;
        else
            return cnt + 1;
    }
}