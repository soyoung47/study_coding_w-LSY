/*
 총 K번 회전시킨 이후 네 톱니바퀴 점수의 합 출력
 점수의 합: 각 톱니바퀴 12시 방향(덱 첫번째 값)의 극(N:0, S:1)에 따라 점수 달라짐
 회전 여부: 1번톱니 3번째-2번톱니 7번째, 2번톱니 3번째-3번톱니 7번째, 3번톱니 3번째-4번톱니 7번째 비교
 톱니바퀴 개수 늘어날 경우 대비 재귀, pow 사용

 1416KB, 0ms
 */

#include <stdio.h>
#include <deque>
#include <math.h>
using namespace std;

deque<int> gear[4];

void rotate(int gearN, int rotD, int sprD){
    //sprD 0:left, 1:left+right, 2:right
    if (sprD == 0 || sprD == 1){
        if (gearN > 0) //gearN 1,2,3: left spread
            //cur.gear[6], left.gear[2]
            if (gear[gearN].at(6) != gear[gearN-1].at(2))
                //반대방향 회전
                rotate(gearN-1, -1*rotD, 0);
    }
    if (sprD == 1 || sprD == 2){
        if (gearN < 3) //gearN 0,1,2: right spread
            //cur.gear[2], right.geat[6]
            if (gear[gearN].at(2) != gear[gearN+1].at(6))
                //반대방향 회전
                rotate(gearN+1, -1*rotD, 2);
    }
    //Counterclockwise
    if (rotD == -1){
        int tmp = gear[gearN].front();
        gear[gearN].pop_front();
        gear[gearN].emplace_back(tmp);
    }
    //Clockwise
    if (rotD == 1){
        int tmp = gear[gearN].back();
        gear[gearN].pop_back();
        gear[gearN].emplace_front(tmp);
    }
}

int main(){
    int val, ans=0;
    //12시 방향부터 시계방향 순서대로 8개 숫자 (0-7)
    for (int N=0; N<4; N++){
        for (int i=0; i<8; i++){
            scanf("%1d", &val);
            gear[N].emplace_back(val);
        }
    }

    int K;
    int gearN, rotD;
    scanf("%d", &K);
    //K번 회전횟수: 톱니 번호, 방향(1:시계방향, -1:반시계방향)
    for (int i=0; i<K; i++){
        scanf("%d %d", &gearN, &rotD);
        rotate(gearN-1, rotD, 1);
    }
    for (int i=0; i<4; i++){
        ans += gear[i].front()*pow(2,i);
    }
    printf("%d", ans);
    return 0;
}

//ref: https://greenapple16.tistory.com/213
