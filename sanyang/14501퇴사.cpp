/*
 DP 문제
 N+1날에 퇴사: N일까지 근무
 i번째 날 일하는 경우: F[i] = F[i+T]+P
 i번째 날 일안하는 경우: F[i] = F[i+1]
 1116KB, 0ms
 */
#include <stdio.h>
using namespace std;
int N, ans;
int T[16], P[16], DP[16];

int max(int a, int b){return a>b?a:b;}

int main(){
    scanf("%d", &N);
    for (int i=1; i<=N; i++){
        scanf("%d %d", &T[i], &P[i]);
    }
    for (int i=N; i>=1; i--){
        //일수가 최대일수 안넘어가는지 확인
        //최대일수 안넘어가는 경우에, 일 하는 경우와 안하는 경우 나눠 계산
        if (i+T[i] > N+1) DP[i] = DP[i+1];
        else DP[i] = max(DP[i+1], DP[i+T[i]]+P[i]);
    }
    printf("%d", DP[1]);
    return 0;
}

//ref: https://yabmoons.tistory.com/519
