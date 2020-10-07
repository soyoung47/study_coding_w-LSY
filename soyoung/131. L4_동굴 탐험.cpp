//https://programmers.co.kr/learn/courses/30/lessons/67260

#include <vector>
using namespace std;

vector<int> edge[200001];
int prior[200001], hang[200001];
bool visit[200001];

void dfs(int v)
{
    if (visit[v])    return;

    //방 번호 v 전에 방문해야 하는 방(prior[v])을 방문 안했으면, hang(대기)에 넣기
    if (!visit[prior[v]])
    {
        hang[prior[v]] = v;
        return;
    }

    visit[v] = true;
    dfs(hang[v]);   //대기하는 것이 있다면 dfs 진행
    for (int i = 0; i < edge[v].size(); i++)
        dfs(edge[v][i]);
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {

    //양방향 그래프
    for (int i = 0; i < path.size(); i++)
    {
        edge[path[i][0]].push_back(path[i][1]);
        edge[path[i][1]].push_back(path[i][0]);
    }

    //A→B(prior[B] = A): 방 번호 B 전에 방문해야 하는 방 번호 A 저장
    for (int i = 0; i < order.size(); i++)
        prior[order[i][1]] = order[i][0];

    if (prior[0])    return false;

    visit[0] = true;
    for (int i = 0; i < edge[0].size(); i++)
        dfs(edge[0][i]);

    for (int i = 0; i < n; i++)
    {
        if (!visit[i])  return false;
    }

    return true;
}

//Ref:::https://beginthread.tistory.com/161