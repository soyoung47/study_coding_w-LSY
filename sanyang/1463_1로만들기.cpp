#include <stdio.h>
using namespace std;
int dp[1000001]={0,};

int calcMin(int a, int b){return a<b? a:b;}

int main(){
    int N;
    scanf("%d", &N);
    for (int i=2; i<=N; i++){
        //2, 3으로 안나눠지는경우 이전값+1
        dp[i]=dp[i-1]+1;
        //2, 3으로 나눠지는경우, 이전단계 값+1
        if (i%2==0) dp[i]=calcMin(dp[i], dp[i/2]+1);
        if (i%3==0) dp[i]=calcMin(dp[i], dp[i/3]+1);
    }
    printf("%d", dp[N]);
    return 0;
}
