//https://programmers.co.kr/learn/courses/30/lessons/49189

#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int solution(int n, vector<vector<int>> edge) {

    //���� ����
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
    q.push(1);  //1�� ���κ���

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

    //�ִ� �Ÿ��� ������ ����� ����
    unordered_map<int, int> m;
    int max = 0;
    for (int d : dist)
    {
        m[d]++;
        max = max > d ? max : d;
    }

    return m[max];
}

//vist(bool) ��� dist(int)�� �ʱⰪ -1�� �����ؼ� ��� ����
//https://blog.naver.com/lhaayyy/221890252574