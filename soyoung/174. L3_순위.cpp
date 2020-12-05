//https://programmers.co.kr/learn/courses/30/lessons/49191

#include <vector>
#include <queue>
using namespace std;

int checkCount(int n, int i, vector<vector<int>> arr)
{
    int cnt = 0;

    vector<bool> visit(n + 1, false);
    queue<int> q;

    visit[i] = true;
    for (int a : arr[i])
        q.emplace(a);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (visit[cur])  continue;
        visit[cur] = true;
        cnt++;

        for (int next : arr[cur])
        {
            if (!visit[next])
                q.emplace(next);
        }
    }

    return cnt;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    //�� ������ �̱� ��� ������ �� ��� ���� ����
    vector<vector<int>> win(n + 1), lose(n + 1);

    for (vector<int> v : results)
    {
        int a = v[0], b = v[1];
        win[a].emplace_back(b);
        lose[b].emplace_back(a);
    }

    //�� ������ �̱� Ƚ���� �� Ƚ�� ����(BFS)
    for (int i = 1; i <= n; i++)
    {
        int n_win = 0, n_lose = 0;
        //�̱� Ƚ��
        if(!win[i].empty())
            n_win = checkCount(n, i, win);        

        //�� Ƚ��
        if (!lose[i].empty())
            n_lose = checkCount(n, i, lose);

        //�̱� Ƚ�� + �� Ƚ�� == n-1 �� ���, ���� Ȯ��
        if (n_win + n_lose == n - 1)
            answer++;
    }
    
    return answer;
}