#include <vector>
#include <algorithm>
using namespace std;

void bfs(int current, vector<vector<bool>>& graph, vector<int>& distance, vector<int> queue) {
    vector<int> m_queue;
    while (!queue.empty()) {
        //노드연결 수만큼 반복
        for (size_t i = 1; i < graph.size(); i++) {
            //노드 연결이 있고 && 거리값이 아직 없으면
            if (graph[queue[0]][i] && !distance[i]) {
                //임시 큐에 넣고 거리 업데이트
                m_queue.emplace_back(i);
                distance[i] = current;
            }
        }
        queue.erase(queue.begin());
    }
    //임시 큐에 값 있으면 재귀
    if (!m_queue.empty())    bfs(current + 1, graph, distance, m_queue);
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    //노드 연결 그래프
    vector<vector<bool>> graph(n, vector<bool>(n, false));
    //1번 노드에서 연결된 각 거리
    vector<int> distance(n, 0);
    //연결 있으면 그래프에 표시
    for (auto e : edge) {
        graph[e[0] - 1][e[1] - 1] = true;
        graph[e[1] - 1][e[0] - 1] = true;
    }
    //너비우선탐색
    bfs(1, graph, distance, { 0 });
    //가장 먼 거리
    int max = *max_element(distance.begin(), distance.end());
    //가장 먼 거리에 해당되는 노드수 카운트
    for (auto d : distance) {
        if (d == max)    answer++;
    }
    return answer;
}

//ref: https://mungto.tistory.com/57
