//https://programmers.co.kr/learn/courses/30/lessons/49189

#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int solution(int n, vector<vector<int>> edge) {

    //간선 저장
    vector<vector<int>> map(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < edge.size(); i++)
    {
        map[edge[i][0]][edge[i][1]] = 1;
        map[edge[i][1]][edge[i][0]] = 1;
    }

    vector<bool> visit(n + 1, false);
    vector<int> dist(n + 1, 0);
    queue<int> q;

    visit[1] = true;    
    q.push(1);  //1번 노드로부터

    while (!q.empty())
    {
        int start = q.front();
        q.pop();

        for (int end = 1; end <= n; end++)
        {
            if (map[start][end] == 1 && (!visit[end] || dist[end] > dist[start] + 1))
            {
                dist[end] = dist[start] + 1;
                visit[end] = true;
                q.push(end);
            }
        }
    }

    //최대 거리를 가지는 노드의 개수
    unordered_map<int, int> m;
    int max = 0;
    for (int d : dist)
    {
        m[d]++;
        max = max > d ? max : d;
    }

    return m[max];
}

//vist(bool) 대신 dist(int)를 초기값 -1로 설정해서 사용 가능
//https://blog.naver.com/lhaayyy/221890252574