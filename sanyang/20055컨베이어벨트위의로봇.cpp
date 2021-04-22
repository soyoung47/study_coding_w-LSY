#include <stdio.h>
#include <queue>
using namespace std;
int belt[202];
bool visit[202]; //check existance of robot
queue<int> robot;

int main(){
    int N, K;
    int cnt = 0, ans = 0;
    //2N: len of belt, K: stop condition
    scanf("%d %d", &N, &K);
    for (int i=1; i<=2*N; i++){
        scanf("%d", &belt[i]);
    }
    int start=1, end = N;
    while(cnt<K){
        ans++;
        
        //move belt
        start--; end--;
        if (start<1) start = 2*N;
        if (end<1) end = 2*N;
        
        //move robot
        int robotN = robot.size();
        for (int i=0; i<robotN; i++){
            int cur = robot.front();
            visit[cur] = 0;
            robot.pop();
            if (cur == end) continue;
            int next = cur+1;
            if (next > 2*N) next = 1;
            //in range && empty belt
            if (belt[next] >= 1 && visit[next] == 0){
                belt[next]--;
                if (belt[next] == 0) cnt++;
                if (next == end) continue;
                visit[next] == 1;
                robot.emplace(next);
             }
            else {
                visit[cur] == 1;
                robot.emplace(cur);
            }
        }
        if (visit[start] == 0 && belt[start] >= 1){
            visit[start] = 1;
            belt[start]--;
            robot.emplace(start);
            if (belt[start] == 0) cnt++;
        }
    }
    printf("%d", ans);
    return 0;
}
