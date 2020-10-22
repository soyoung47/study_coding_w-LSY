//https://programmers.co.kr/learn/courses/30/lessons/43162

#include <vector>
using namespace std;

void dfs(int ind, int n, vector<bool>& visit, vector<vector<int>>& computers)
{
    visit[ind] = true;

    for (int i = 0; i < n; i++)
    {
        if (visit[i])    continue;
        if (computers[ind][i])
            dfs(i, n, visit, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visit(n, false);

    for (int i = 0; i < n; i++)
    {
        if (visit[i])    continue;
        dfs(i, n, visit, computers);
        answer++;
    }

    return answer;
}