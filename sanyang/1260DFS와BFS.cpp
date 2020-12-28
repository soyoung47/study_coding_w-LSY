/*
 그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.
 */

#include <stdio.h>
#include <queue>
using namespace std;
int N=0, M=0, V=0;
bool Visit[1001]={0};
bool Conn[1001][1001]={{0}};

void DFS(int V){
    //현재 노드 방문 표시
    Visit[V] = 1;
    printf("%d ", V);
    for (int i=1; i<=N; i++){
        //이미 방문했거나, 기준점과 현재 노드간 연결이 없는 경우 패스
        if (Visit[i] == 1 || Conn[V][i] == 0) continue;
        //아직 방문안했고, 기준점과 현재 노드간 연결이 있는 경우 재귀
        else DFS(i);
    }
}

void BFS(int V){
    queue<int> q;
    //DFS하면서 모두 1로 표시된 상태이므로 0으로 방문표시
    Visit[V] = 0;
    q.emplace(V);
    //큐가 빌 때까지 반복
    while (!q.empty()){
        //큐 맨 앞 원소로 V update, pop
        V = q.front();
        printf("%d ", V);
        q.pop();
        for (int i=1; i<=N; i++){
            //이미 방문했거나, 기준점과 현재 노드간 연결이 없는 경우 패스
            if ((Visit[i] == 0) || Conn[V][i] == 0) continue;
            //아직 방문안했고, 기준점과 현재 노드간 연결이 있는 경우 큐에 추가
            else q.push(i);
            //방문 표시
            Visit[i] = 0;
        }
    }
}

int main(){
    scanf("%d %d %d", &N, &M, &V);
    int tmp1=0, tmp2=0;
    for (int i=0; i<M; i++){
        scanf("%d %d", &tmp1, &tmp2);
        Conn[tmp1][tmp2] = Conn[tmp2][tmp1] = 1;
    }
    DFS(V);
    printf("\n");
    BFS(V);
    return 0;
}

//ref: https://jun-itworld.tistory.com/18
