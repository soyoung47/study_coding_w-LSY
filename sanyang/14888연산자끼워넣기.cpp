/*
 DFS 완전탐색
 1116KB, 0ms
 */

#include <stdio.h>
#include <algorithm>
using namespace std;
int N, a, s, m, d;
int A[12]; //N:2-11
int maxV = -100000000, minV = 100000000;

//ind만큼 사칙연산수행, 모든 횟수 수행했으면 max, min값 계산 후 return
void DFS(int ind, int add, int sub, int mul, int div, int sum){
    if (ind == N){
        maxV = max(maxV, sum);
        minV = min(minV, sum);
        return;
    }
    if (add<a) DFS(ind+1, add+1, sub, mul, div, sum+A[ind]);
    if (sub<s) DFS(ind+1, add, sub+1, mul, div, sum-A[ind]);
    if (mul<m) DFS(ind+1, add, sub, mul+1, div, sum*A[ind]);
    if (div<d) DFS(ind+1, add, sub, mul, div+1, sum/A[ind]);
}

int main(){
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        scanf("%d", &A[i]);
    }
    //#add, #sub, #mul, #div
    scanf("%d %d %d %d", &a, &s, &m, &d);
    DFS(1,0,0,0,0,A[0]);
    printf("%d\n%d\n", maxV, minV);
    return 0;
}

//ref: https://suriisurii.tistory.com/11
