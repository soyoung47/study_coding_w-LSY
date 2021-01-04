#include <stdio.h>
#include <queue>
using namespace std;
int N, M;
int arr[100][100]={0,};
int visit[100][100]={0,};
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void BFS(int i, int j){
    queue<pair<int, int>> q;
    visit[i][j] = 1;
    q.emplace(i, j);
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k=0; k<4; k++){
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (nx>=0 && nx<N && ny>=0 && ny<M){
                if (visit[nx][ny]==0 && arr[nx][ny]==1){
                    q.emplace(nx,ny);
                    visit[nx][ny] = visit[x][y]+1;
                }
            }
        }
    }
}

int main(){
    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            scanf("%1d", &arr[i][j]);
        }
    }
    BFS(0,0);
    printf("%d\n", visit[N-1][M-1]);
    return 0;
}

/*
 최단거리를 찾아야 할 때는 무조건 BFS를 사용하자.
 DFS를 사용하는경우 시간초과 날 수 있음.
 */

//void DFS(int i, int j){
//    //현재 노드 방문 표시
//    arr[i][j] = 0;
//    for (int k=0; k<4; k++){
//        if (i+dx[k]<0 || i+dx[k]>=N || j+dy[k]<0 || j+dy[k]>=M) continue;
//        if (arr[i+dx[k]][j+dy[k]]==1){
//            arr[i+dx[k]][j+dy[k]]=0;
//            cnt++;
//            DFS(i+dx[k], j+dy[k]);
//        }
//        if ((i+dx[k])==N-1 && (j+dy[k])==M-1)
//            cand.emplace_back(cnt);
//    }
//}

//ref:https://lily-lee.postype.com/post/2642825
