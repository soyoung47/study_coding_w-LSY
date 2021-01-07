#include <stdio.h>
#include <queue>
#include <tuple>
#define MAX 100
using namespace std;
int M, N, H;
int arr[MAX][MAX][MAX];
bool v[MAX][MAX][MAX];
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
queue<tuple<int,int,int>> q;

void BFS(){
    while (!q.empty()){
        int x, y, z;
        //tuple 한꺼번에 가져오기: tie()
        tie(x,y,z) = q.front();
        q.pop();
        for (int k=0; k<6; k++){
            //6가지 방향 좌표 확인
            int nx = x + dx[k];
            int ny = y + dy[k];
            int nz = z + dz[k];
            //유효 범위 확인
            if (nx>=0 && nx<N && ny>=0 && ny<M && nz>=0 && nz<H){
                //안익은 토마토면서 방문한적이 없으면 익게되므로 q추가, 방문체크, 일수+1
                if (arr[nx][ny][nz]==0 && !v[nx][ny][nz]){
                    q.emplace(nx,ny,nz);
                    v[nx][ny][nz]=1;
                    arr[nx][ny][nz] = arr[x][y][z]+1;
                }
            }
        }
    }
}

int main(){
    scanf("%d %d %d", &M, &N, &H); //H-M-N
    bool allOnes = 0;
    //입력데이터 인덱스 주의
    for (int k=0; k<H; k++){
        for (int i=0; i<N; i++){
            for (int j=0; j<M; j++){
                //1:익음 0:안익음 -1:없음
                scanf("%d", &arr[i][j][k]);
                //안익은게 하나라도 있는지 체크(다익었으면 0출력)
                if (arr[i][j][k]==0) allOnes=1;
                //익은 토마토면 -> 인접 토마토 확인해야하므로 큐에 넣고 방문체크
                if (arr[i][j][k]==1){
                    q.emplace(i,j,k);
                    v[i][j][k]=1;
                }
            }
        }
    }
    //안익은게 하나라도 있다 -> 0출력 후 프로그램 종료
    if (!allOnes){
        printf("0");
        return 0;
    }
    //익은 토마토를 대상으로 BFS
    BFS();
    int ans = 0;
    for (int k=0; k<H; k++){
        for (int i=0; i<N; i++){
            for (int j=0; j<M; j++){
                //0인 토마토가 남아있으면 -> 모두 익지 못하는 상황 -> -1출력 후 종료
                if (arr[i][j][k]==0){
                    printf("-1");
                    return 0;
                }
                //가장 큰 값이 다 익기 위해 걸리는 일수
                if (ans<arr[i][j][k]) ans = arr[i][j][k];
            }
        }
    }
    printf("%d", ans-1);
    return 0;
}


//ref: https://intaehwang.tistory.com/27
