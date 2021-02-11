//길이가 N인 모든 2진 수열의 개수를 15746으로 나눈 나머지를 출력
//0, 1, 00 카드
//N3=3(N1+N2), N4=5(N2+N3), N5=8(N3+N4), ... fib
//1000000 너무 크기 때문에 15746으로 나누고 진행

#include <stdio.h>
using namespace std;
#define MAX 1000001
int dp[MAX];
int N;

void sol(){
    dp[0] = 0;
    dp[1] = 1; //1
    dp[2] = 2; //00 11
    for (int i=3; i<=N; i++){
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] = dp[i] % 15746;
    }
    printf("%d", dp[N]);
}

int main(){
    scanf("%d", &N);
    sol();
    return 0;
}

//https://cryptosalamander.tistory.com/82
