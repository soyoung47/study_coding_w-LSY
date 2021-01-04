#include <stdio.h>
#include <queue>
using namespace std;
int M, N;
int arr[1000][1000];
int visit[1000][1000];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
queue<pair<int, int>> q;

void BFS(){
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx>=0 && nx<N && ny>=0 && ny<M){
                if (arr[nx][ny]==0 && visit[nx][ny]==-1){
                    visit[nx][ny] = visit[x][y]+1;
                    q.emplace(nx,ny);
                }
            }
        }
    }
}

int main(){
    scanf("%d %d", &M, &N);
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            scanf("%d", &arr[i][j]);
            visit[i][j]=-1;
            if (arr[i][j]==1){
                q.emplace(i,j);
                visit[i][j]=0;
            }
        }
    }
    BFS();
    int ans = 0;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            ans = max(ans, visit[i][j]);
        }
    }
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if (arr[i][j]==0 && visit[i][j]==-1) ans=-1;
        }
    }
    printf("%d\n", ans);
    return 0;
}

//https://murra.tistory.com/60
