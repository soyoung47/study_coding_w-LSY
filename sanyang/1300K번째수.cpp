/*
 세준이는 크기가 N×N인 배열 A를 만들었다. 배열에 들어있는 수 A[i][j] = i×j 이다. 이 수를 일차원 배열 B에 넣으면 B의 크기는 N×N이 된다. B를 오름차순 정렬했을 때, B[k]를 구해보자.

 배열 A와 B의 인덱스는 1부터 시작한다.
 */

#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int N, k;
    scanf("%d %d", &N, &k);
    int minV = 0, maxV = k, avg = 0, answer = 0;
    while (minV <= maxV){
        avg = (minV+maxV)/2;
        int cnt = 0;
        //각 행에서 avg/i 또는 N 값중 작은 값을 카운트에 추가
        //k보다 작거나 같은 수의 갯수 카운트가 k의 인덱스
        for (int i=1; i<=N; i++) cnt += min(avg/i, N);
        //k가 cnt보다 크거나 같으면 -> maxV 업데이트,
        //같은 경우 정답이 될 수 있으므로 ans 업데이트
        if (cnt >= k) {
            answer = avg;
            maxV = avg - 1;
        }
        //k보다 cnt가 작으면 -> minV 업데이트
        else if (cnt < k) {
            minV = avg + 1;
        }
    }

    printf("%d\n", answer);
    return 0;
}

//ref: https://kyunstudio.tistory.com/168
//ref: https://kyu9341.github.io/algorithm/2020/03/13/algorithm1300/

