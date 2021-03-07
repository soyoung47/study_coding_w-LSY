/*
모든 TC통과하고 틀렸습니다 나와서 원인을 못찾았는데 후에 찾은 원인:
13번째 줄 L값을 저장하는 change[]를 101에서 10001로 변경하여 해결
1308KB, 0MB
*/

#include <stdio.h>
#include <queue>
using namespace std;
//뱀의 머리쪽이 추가되고, 꼬리쪽이 사라지므로 queue로 구현: 머리<-[ ]<-꼬리
queue<pair<int, int>> snake; //board [row][col]
int N, K;
int map[102][102];
int change[10001];
//4 directions: right, down, left, up
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int main(){
    int L=0, a, b;
    int nextDir = 0; //default direction: right
    scanf("%d", &N); //size of board: N
    scanf("%d", &K); //num of apple: K
    for (int i=0; i<K; i++){ //pos of K apples
        scanf("%d %d", &a, &b);
        map[a-1][b-1] = 2; //empty: 0, snake: 1, apple: 2
    }
    scanf("%d", &L); //num of changing direction: L
    int x=0;
    char c;
    for (int i=0; i<L; i++){
        scanf("%d %c", &x, &c); //left: 'L', right: 'D'
        if (c=='L') change[x]=3;
        else if (c=='D') change[x]=1;
    }
    map[0][0]=1;
    snake.emplace(0,0);

    //뱀 머리가 벽에 부딪히거나, 몸에 닿으면 종료
    //턴이 없으면 직진: 진행방향으로+1, 꼬리-1
    //사과 먹으면 길이증가: 진행방향으로+1, 꼬리 변화0
    int sec, nx, ny;
    for (sec=1;; sec++){
        nx = snake.back().first + dx[nextDir];
        ny = snake.back().second + dy[nextDir];
        if (nx<0 || nx>=N || ny<0 || ny >= N || (map[nx][ny]==1)) break;
        //empty or apple: head+1
        if (map[nx][ny]==0){ //empty: tail-1
            map[snake.front().first][snake.front().second]=0;
            snake.pop();
        }
        map[nx][ny]=1;
        snake.emplace(nx, ny);
        nextDir = (nextDir + change[sec])%4; //다음 이동방향
    }
    printf("%d", sec);
    return 0;
}
