#include <stdio.h>
#include <queue>
using namespace std;
#define MAX 100001
int N, K, ans;
int v[MAX]={0,};
queue<int> q;

void BFS(){
    while(!q.empty()){
        int p = q.front();
        q.pop();
        //정답인경우
        if (p==K){
            ans = v[p]-1;
            printf("%d", ans);
            break;
        }
        //3가지 이동 (범위확인 && 방문확인)
        if (p-1>=0 && v[p-1]==0){
            v[p-1]=v[p]+1;
            q.emplace(p-1);
        }
        if (p+1<=MAX && v[p+1]==0){
            v[p+1]=v[p]+1;
            q.emplace(p+1);
        }
        if (p*2<=MAX && v[p*2]==0){
            v[p*2]=v[p]+1;
            q.emplace(p*2);
        }
    }
}

int main(){
    scanf("%d %d", &N, &K);
    q.emplace(N);
    v[N]=1;
    BFS();
    return 0;
}

//ref: https://hsp1116.tistory.com/20
