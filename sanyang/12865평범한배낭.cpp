/*
 knapsack algorithm
 40568KB, 36ms
 */
#include <stdio.h>
using namespace std;
int W[101], V[101], dp[101][100001]; //dp size주의

int maxCalc(int a, int b){return a>b? a:b;}

int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    for (int i=1; i<=N; i++){
        scanf("%d %d", &W[i], &V[i]);
    }
    for (int i=1; i<=N; i++){
        for (int j=1; j<=K; j++){
            dp[i][j] = dp[i-1][j];
            if (j-W[i]>=0) dp[i][j] = maxCalc(dp[i][j], dp[i-1][j-W[i]]+V[i]);
        }
    }
    printf("%d", dp[N][K]);
    return 0;
}
