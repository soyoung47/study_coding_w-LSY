//P: 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, ...
//P>=4: P[N]=P[N-3]+P[N-2]
//값이 크게 증가하므로 long long 자료형 사용
#include <stdio.h>
using namespace std;
int T, N;
long long dp[101] = {0,1,1,1,};

long long sol(int N){
    if (N<3) return dp[N];
    else if (dp[N]==0) dp[N] = sol(N-3)+sol(N-2);
    return dp[N];
}

int main(){
    scanf("%d", &T);
    for (int tc=0; tc<T; tc++){
        scanf("%d", &N);
        sol(N);
        //lld: signed long long
        printf("%lld\n", dp[N]);
    }
    return 0;
}
