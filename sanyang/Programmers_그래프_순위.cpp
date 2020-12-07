#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    //각 경기의 승패 표시하는 그래프
    vector<vector<bool>> graph(n+1, vector<bool>(n+1, false));
    //승리한 경우 true로 업데이트
    for (auto r : results)  graph[r[0]][r[1]] = true;
    for (auto i = 1; i <= n; i++) {
        for (auto j = 1; j <= n; j++) {
            for (auto k = 1; k <= n; k++) {
                //a->b && b->c: a->c 업데이트
                if (graph[j][i] && graph[i][k]) {
                    graph[j][k] = true;
                }
            }
        }
    }
    //선수 수만큼 반복
    for (auto i = 1; i <= n; i++) {
        int count = 0;
        for (auto j = 1; j <= n; j++) {
            //ij사이 경기가 있으면 카운트 증가
            if (graph[i][j] || graph[j][i]) count++;
        }
        //카운트수가 선수 수-1이면 순위매길 수 있으므로 증가
        if (count == n - 1) answer++;
    }
    return answer;
}

//ref: https://mungto.tistory.com/58
