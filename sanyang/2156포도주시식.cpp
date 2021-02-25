#include <stdio.h>
using namespace std;
int calcMax(int a, int b){return a>b? a:b;}

int main(){
    int arr[10001]={0,};
    int dp[10001]={0,};
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%d", &arr[i]);
    dp[0]=0;
    dp[1]=arr[1];
    dp[2]=arr[1]+arr[2];
    for (int i=3; i<=n; i++){
        //한개씩 뛰어넘는경우
        dp[i] = calcMax(dp[i-3]+arr[i-1]+arr[i], dp[i-2]+arr[i]);
        //둘다 뛰어넘는경우 고려
        dp[i] = calcMax(dp[i-1],dp[i]);
    }
    printf("%d", dp[n]);
    return 0;
}
