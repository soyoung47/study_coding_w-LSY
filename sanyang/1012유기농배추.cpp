#include <stdio.h>
using namespace std;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int land[50][50] = {0};
int v[50][50] = {0};
int M=0, N=0, K=0;

void DFS(int y, int x){
    for (int k=0; k<4; k++){
        int nx=x+dx[k];
        int ny=y+dy[k];
        if (nx<0 || nx>=M || ny<0 || ny>=N) continue;
        if (land[ny][nx]==1 && v[ny][nx]==0){
            v[ny][nx]++;
            DFS(ny, nx);
        }
    }
}

int main(){
    int T = 0, cnt = 0;
    int X = 0, Y = 0;
    scanf("%d", &T);
    for (int tc=0; tc<T; tc++){
        cnt=0;
        scanf("%d %d %d", &M, &N, &K);
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                land[i][j]=0;
                v[i][j]=0;
            }
        }
        for (int i=0; i<K; i++){
            scanf("%d %d", &X, &Y);
            land[Y][X] = 1;
        }
        for (int i=0; i<N; i++){
            for (int j=0; j<M; j++){
                if (land[i][j]==1 && v[i][j]==0){
                    v[i][j]++;
                    cnt++;
                    DFS(i, j);
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}

 /*
 - 예제가 맞았는데도 계속 틀려서 map(land), v(visit)을 초기화해줘서 해결
 - test case가 여러개일 때에는 꼭 초기화에 신경쓰자
 */
