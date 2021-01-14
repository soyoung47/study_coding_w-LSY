/*
체스판 위에 한 나이트가 놓여져 있다. 
나이트가 한 번에 이동할 수 있는 칸은 아래 그림에 나와있다. 
나이트가 이동하려고 하는 칸이 주어진다. 
나이트는 몇 번 움직이면 이 칸으로 이동할 수 있을까?
*/

#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 301
int dx[] = {-1,-2,-2,-1,1,2,2,1};
int dy[] = {-2,-1,1,2,2,1,-1,-2};
bool arr[MAX][MAX] = { {0,} }; //chk
int v[MAX][MAX] = { {0,} }; //cnt
queue<pair<int, int>> q;
int L, curX, curY, destX, destY, ans; //current, destination

void BFS() {
    memset(arr, 0, sizeof(arr));
    memset(v, 0, sizeof(v));
    q.emplace(make_pair(curX, curY));
    v[curX][curY] = 0;
    arr[curX][curY] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == destX && y == destY) ans = v[x][y];
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < L && ny >= 0 && ny < L) {
                if (arr[nx][ny] == 0) {
                    q.emplace(nx, ny);
                    arr[nx][ny] = 1;
                    v[nx][ny] = v[x][y] + 1;
                }
            }
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int tc = 0; tc < T; tc++) {
        scanf("%d %d %d %d %d", &L, &curX, &curY, &destX, &destY);
        BFS();
        printf("%d\n", ans);
    }
    return 0;
}

//https://kyu9341.github.io/algorithm/2020/02/27/algorithm7562/
