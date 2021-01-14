/*
N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다. 당신은 (1, 1)에서 (N, M)의 위치까지 이동하려 하는데, 이때 최단 경로로 이동하려 한다. 최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데, 이때 시작하는 칸과 끝나는 칸도 포함해서 센다.

만약에 이동하는 도중에 한 개의 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 한 개 까지 부수고 이동하여도 된다.

한 칸에서 이동할 수 있는 칸은 상하좌우로 인접한 칸이다.

맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.
*/

#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 1001
int N, M;
queue<int> q[3]; //y, x, wall
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int ans = 0;
bool arr[MAX][MAX] = { {0,} }; //0, 1
int v[MAX][MAX][2] = {0}; //y, x, wall

void BFS() {
    v[1][1][1] = 1;
    q[0].emplace(1);
    q[1].emplace(1);
    q[2].emplace(1);
    while (!q[0].empty()) {
        int y = q[0].front();
        int x = q[1].front();
        int w = q[2].front();
        q[0].pop();
        q[1].pop();
        q[2].pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            //범위 확인
            if (ny >= 1 && ny <= N && nx >= 1 && nx <= M){
                if (arr[ny][nx] == 0 && v[ny][nx][w] == 0) {
                    q[0].emplace(ny);
                    q[1].emplace(nx);
                    q[2].emplace(w);
                    v[ny][nx][w] = v[y][x][w] + 1;
                }
                else if (arr[ny][nx] == 1 && w == 1) {
                    v[ny][nx][w - 1] = v[y][x][w] + 1;
                    q[0].emplace(ny);
                    q[1].emplace(nx);
                    q[2].emplace(0);
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    int tmp;
    for (int n = 1; n <= N; n++) {
        for (int m = 1; m <= M; m++) {
            scanf("%1d", &tmp);
            if (tmp==1) arr[n][m]=1;
        }
    }
    BFS();
    //조건확인, ans값 설정
    if (v[N][M][1] == 0 && v[N][M][0] == 0) ans = -1;
    else if (v[N][M][1] != 0 && v[N][M][0] != 0) ans = min(v[N][M][0], v[N][M][1]);
    else {
        if (v[N][M][1] == 0) ans = v[N][M][0];
        else if (v[N][M][1] != 0) ans = v[N][M][1];
    }
    printf("%d", ans);
    return 0;
}


//https://gusdnr69.tistory.com/73
