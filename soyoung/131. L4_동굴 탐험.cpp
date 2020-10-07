//https://programmers.co.kr/learn/courses/30/lessons/67260

#include <vector>
using namespace std;

vector<int> edge[200001];
int prior[200001], hang[200001];
bool visit[200001];

void dfs(int v)
{
    if (visit[v])    return;

    if (!visit[prior[v]])
    {
        hang[prior[v]] = v;
        return;
    }

    visit[v] = true;
    dfs(hang[v]);
    for (int i = 0; i < edge[v].size(); i++)
        dfs(edge[v][i]);
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {

    for (int i = 0; i < path.size(); i++)
    {
        edge[path[i][0]].push_back(path[i][1]);
        edge[path[i][1]].push_back(path[i][0]);
    }

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