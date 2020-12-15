#include <stdio.h>
#include <algorithm>
#include <climits> //max
using namespace std;

int main(){
    int K, N;
    long long Ks[10001];
    long long maxL = 0;
    scanf("%d %d", &K, &N);
    for (int i=0; i<K; i++){
        scanf("%lld", &Ks[i]);
    }

    long long min = 0;
    long long max = LLONG_MAX;

    while (min <= max){
        long long avg = (min+max)/2;
        int res = 0;
        //중간 길이로 현재 선을 나누면 잘린 랜선 갯수가 총 몇개인지 합산
        for (int i=0; i<K; i++) res += Ks[i] / avg;
        //구해야 하는 갯수보다 많음: 너무 짧게 자름 -> 더 길게
        if (res >= N){
            min = avg + 1;
            if (avg > maxL) maxL = avg;
        }
        //구해야 하는 갯수보다 적음: 너무 길게 자름 -> 더 짧게
        else if (res < N) max = avg - 1;
    }

    printf("%lld\n", maxL);

    return 0;
}

//ref: https://wootool.tistory.com/114
