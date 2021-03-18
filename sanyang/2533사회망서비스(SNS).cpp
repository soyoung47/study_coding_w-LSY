/*
 goal: 모든 개인이 새로운 아이디어를 수용하기 위해 필요한 최소 얼리어답터의 수 구하기
 현재 노드가 얼리어답터o -> 인접한 다음 노드는 얼리어답터o or 얼리어답터x
 현재 노드가 얼리어답터x -> 인접한 다음 노드는 얼리어답터o
 75572KB, 920ms
 */
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring> //memset
using namespace std;
vector<vector<int>> adj;
//dp[n][0]: n번 정점이 얼리어답터가 아닐때 최소 얼리어답터 수
//dp[n][1]: n번 정점이 얼리어답터일 때의 최소 얼리어답터 수
int dp[1000001][2];

//dpF(현재 노드, 이전 노드, 선택 여부)
int dpFunc(int cur, int pre, int state){
    int &cache = dp[cur][state];
    if (cache != -1) return cache;
    int ans = 0;
    //현재 노드가 얼리어답터가 아닌 경우
    if (state == 0){
        int len = adj[cur].size();
        for (int i=0; i<len; i++){
            int next=adj[cur][i];
            if (next==pre) continue;
            //인접한 노드는 얼리어답터
            ans += dpFunc(next, cur, 1);
        }
        return cache=ans;
    }
    //현재 노드가 얼리어답터인 경우 (state == 1)
    else {
        int len=adj[cur].size();
        int ret1=0, ret2=0;
        for (int i=0; i<len; i++){
            int next=adj[cur][i];
            if (next==pre) continue;
            ret1 = dpFunc(next, cur, 0);
            ret2 = dpFunc(next, cur, 1);
            //인접한 노드는 얼리어답터여도 되고 아니어도 된다
            ans += min(ret1, ret2);
        }
        return cache=ans+1;
    }
}

int main(){
    int N = 0;
    scanf("%d", &N); //정점 개수
    adj.resize(N+1);
    memset(dp, -1, sizeof(dp));
    
    for (int i=0; i<N-1; i++){
        int from, to;
        scanf("%d %d", &from, &to);
        //connect vertex
        adj[from].emplace_back(to);
        adj[to].emplace_back(from);
    }
    printf("%d", min(dpFunc(1,0,0), dpFunc(1,0,1)));
    return 0;
}

//https://kibbomi.tistory.com/73
