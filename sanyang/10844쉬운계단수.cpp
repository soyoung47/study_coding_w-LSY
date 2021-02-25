#include <stdio.h>
#define mod 1000000000
using namespace std;
//첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력

int main(){
    //1<=N<=100
    int dp[101][10] = {0,};
    int N;
    long long sum=0;
    scanf("%d", &N);
    //1자리수일때 1~9
    for (int i=1; i<=9; i++) dp[1][i]=1;
    //2자리수 이상일때
    for (int i=2; i<=N; i++){
        for (int j=0; j<=9; j++){
            //0이 들어가는 경우는 ~10으로 1에서오는경우
            if (j==0) dp[i][j]=dp[i-1][j+1];
            //9가 들어가는 경우는 8에서 오는경우
            else if (j==9) dp[i][j]=dp[i-1][j-1];
            //이전단계 양쪽에서 오는경우
            else dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%mod;
        }
    }
    //모든 값을 더해야 계단수 합
    for (int i=0; i<=9; i++) sum+=dp[N][i];
    printf("%lld", sum%mod);
    return 0;
}

//https://jaemin8852.tistory.com/161
