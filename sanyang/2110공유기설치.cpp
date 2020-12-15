#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int N, C;
    scanf("%d %d", &N, &C);
    long long Xs[200001];
    for (int i=0; i<N; i++){
        scanf("%lld", &Xs[i]);
    }
    //집 좌표 정렬
    sort(Xs,Xs+N);
    long long min = 0;
    long long max = 1000000000;
    //C개 설치했을 때 인접한 두 공유기 사이 최대 거리
    long long maxDist = 0;
    
    while (min<=max){
        long long avg = (min+max)/2;
        long long dist = 1, idx2 = 0;
        int cnt = 1;
        for (int i=0; i<N; i++){
            //avg보다 공유기 사이 거리가 크면
            if (Xs[i] - Xs[idx2] >= avg){
                //대수 추가, 다음인덱스 업데이트
                idx2 = i;
                cnt++;
            }
        }
        //공유기 설치대수가 C보다 크거나 같으면 (C대수만큼 설치되면)
        if (cnt >= C){
            //최대거리 가능성 있으므로 업데이트
            maxDist = avg;
            min = avg + 1;
        }
        //공유기 설치대수가 C대가 안되면: 거리 너무 멈 -> 최대거리 축소
        else if (dist < C){
            max = avg - 1;
        }
    }
    
    printf("%lld\n", maxDist);
    return 0;
}
