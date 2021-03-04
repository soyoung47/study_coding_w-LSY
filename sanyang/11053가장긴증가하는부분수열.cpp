#include <stdio.h>
using namespace std;

int maxCalc(int a, int b){return a>b? a:b;}

int main(){
    int N, ans = 0;
    int arr[1001]={0,};
    int dp[1001]={0,};
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", &arr[i]);
    for (int i=0; i<N; i++){
        //해당 값보다 작은 값이 없으면 1
        //작은 값이 있으면 dp값 업데이트
        dp[i] = 1;
        for (int j=0; j<i; j++){
            if (arr[j]<arr[i]) dp[i] = maxCalc(dp[i], dp[j]+1);
        }
    }
    //구해진 dp[i] (i값을 마지막으로 하는 최장길이) 중 최대값 출력
    for (int i=0; i<N; i++) ans = maxCalc(ans, dp[i]);
    printf("%d", ans);
    return 0;
}
