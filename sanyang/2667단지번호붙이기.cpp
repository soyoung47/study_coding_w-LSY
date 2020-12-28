/*
 <그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 철수는 이 지도를 가지고 연결된 집의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 대각선상에 집이 있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.
 */

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int Map[26][26];
int N = 0, cnt = 0;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
vector<int> v;

void DFS(int i, int j){
    //현재 노드 방문 표시
    Map[i][j] = 0;
    cnt++;
    for (int k=0; k<4; k++){
        //해당 방향 집이 없거나 범위밖인경우 패스
        if (i+dy[k]<0 || i+dy[k]>=N || j+dx[k]<0 || j+dx[k]>=N) continue;
        //해당방향 집이 있는경우 재귀
        else if (Map[i+dy[k]][j+dx[k]]==1) DFS(i+dy[k], j+dx[k]);
    }
}

int main(){
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            scanf("%1d", &Map[i][j]);
        }
    }
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if (Map[i][j]==1){
                cnt=0;
                DFS(i,j);
                v.emplace_back(cnt);
            }
        }
    }
    //집 수 오름차순 정렬
    sort(v.begin(), v.end());
    //총 단지수 출력
    printf("%d\n", (int)v.size());
    //정렬된 집 수 출력
    for (int i=0; i<v.size(); i++) printf("%d\n", v[i]);
    return 0;
}

//ref: https://ssu-gongdoli.tistory.com/9
