#include <stdio.h>
using namespace std;

int getMax(int a, int b) {return a > b? a: b;}
int main(){
    int n;
    scanf("%d", &n);

    int DP[501][501];
    //input (0,0 / 1,0 1,1 / 2,0 2,1 2,2 / ... )
    for (int i=0; i<n; i++){
        for (int j=0; j<=i; j++){
            scanf("%d", &DP[i][j]);
        }
    }

    int max = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<=i; j++){
            //col 0
            if (j==0) DP[i][j] = DP[i-1][0] + DP[i][j];
            //last col
            else if (i==j) DP[i][j] = DP[i-1][j-1] + DP[i][j];
            //inside col
            else DP[i][j] = getMax(DP[i-1][j-1]+DP[i][j], DP[i-1][j]+DP[i][j]);
            //update max
            max = getMax(max, DP[i][j]);
        }
    }
    printf("%d", max);
    return 0;
}

//https://sihyungyou.github.io/baekjoon-1932/
