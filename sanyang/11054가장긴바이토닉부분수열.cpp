//증가하는부분수열과 동일하게 증가수열, 감소수열 만든 후 합-1 계산
//for문 두 번 따로 돌 필요 없이 index 

#include <stdio.h>
using namespace std;
#define MAX 1001
int arr[MAX];
int dpI[MAX]; //increasing dp
int dpD[MAX]; //decreasing dp

//int Max(int a, int b){return a>b? a:b;}

int main(){
    int N, ans=0;
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", &arr[i]);
    for (int i=0; i<N; i++){
        dpI[i]=1;
        dpD[N-i-1]=1; //index 주의
        for (int j=0; j<i; j++){
            if (arr[i]>arr[j] && dpI[i]<dpI[j]+1) dpI[i]=dpI[j]+1;
            if (arr[N-i-1]>arr[N-j-1] && dpD[N-i-1]<dpD[N-j-1]+1)
                dpD[N-i-1]=dpD[N-j-1]+1;
        }
    }
    for (int i=0; i<N; i++){
        //ans = Max(ans, dpI[i]+dpD[i]-1);
        if (ans<dpI[i]+dpD[i]-1) ans=dpI[i]+dpD[i]-1;
    }
    printf("%d", ans);
    return 0;
}

//ref: https://sihyungyou.github.io/baekjoon-11054/
