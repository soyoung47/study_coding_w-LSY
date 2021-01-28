#include <stdio.h>
using namespace std;

int getMax(int a, int b) { return a>b? a:b; }

int main(){
    int N;
    scanf("%d", &N);
    int arr[301] = {0};
    int dp[301] = {0};
    for (int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }
    dp[0] = arr[0];
    //0+1(1,1), 1(2)
    dp[1] = getMax(arr[0]+arr[1], arr[1]);
    //0+2(1,2), 1+2(2,1)
    dp[2] = getMax(arr[0]+arr[2], arr[1]+arr[2]);

    for (int i=3; i<N; i++){
        dp[i] = getMax(dp[i-2]+arr[i], dp[i-3]+arr[i-1]+arr[i]);
    }
    printf("%d", dp[N-1]);
    return 0;
}
