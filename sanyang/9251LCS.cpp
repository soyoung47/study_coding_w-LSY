/*
 LCS(Longest Common Subsequence): 최장 공통 부분 수열
 5032KB, 4ms
 */
#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;
char s1[1001], s2[1001];
int dp[1001][1001];

int maxCalc(int a, int b){return a>b? a:b;}

int main(){
    //%s에는 &생략
    scanf("%s %s", s1, s2);
    int s1size = (int)strlen(s1);
    int s2size = (int)strlen(s2);
    for (int i=1; i<=s1size; i++){
        for (int j=1; j<=s2size; j++){
            if (s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = maxCalc(dp[i-1][j], dp[i][j-1]);
        }
    }
    printf("%d", dp[s1size][s2size]);
    return 0;
}
