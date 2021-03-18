/*
  1896KB, 12ms
*/
#include <stdio.h>
using namespace std;
int nums[100001];
int dp[100001];

int maxCalc(int a, int b){return a>b? a:b;}

int main(){
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%d", &nums[i]);
        dp[i] = nums[i];
    }
    int maxS = dp[0];
    for (int i=1; i<n; i++){
        dp[i] = maxCalc(dp[i], dp[i-1]+nums[i]);
        if (dp[i]>maxS) maxS = dp[i];
    }
    printf("%d", maxS);
    return 0;
}
