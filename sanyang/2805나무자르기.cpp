#include <stdio.h>
using namespace std;

int main(){
    long long N, M, maxH = 0;
    scanf("%lld %lld", &N, &M);
    long long Hs[1000001];
    for (int i=0; i<N; i++){
        scanf("%lld", &Hs[i]);
    }
    long long min = 0;
    long long max = 1000000000;
    while (min <= max){
        long long avg = (min+max)/2;
        long long sum = 0;
        for (int i=0; i<N; i++){
            if (Hs[i] > avg) sum += Hs[i]-avg;
        }
        //나무 너무 많음 -> 높이 높이기
        if (sum >= M){
            min = avg+1;
            //찾던 값이면 maxH 할당
            //if (avg > maxH) maxH = avg;
            maxH = avg;
        }
        //나무 너무 적음 -> 높이 낮추기
        else if (sum < M) max = avg-1;
    }

    printf("%lld\n", maxH);

    return 0;
}
