//https://programmers.co.kr/learn/courses/30/lessons/64064

#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int N, M;
vector<int> v[10];
bool visit[10];
unordered_set<string> s;

void dfs(int ind)
{
    if (ind == M)
    {
        string str = "";
        for (int j = 0; j < N; j++)
        {
            if (visit[j])
                str += to_string(j);
        }
        s.insert(str);
        return;
    }

    for (int i = 0; i < v[ind].size(); i++)
    {
        int cur = v[ind][i];
        if (visit[cur])    continue;
        visit[cur] = true;

        dfs(ind+1);
        visit[cur] = false;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    N = user_id.size(), M = banned_id.size();
    
    //banned_id에 해당되는 user_id 개수 찾기
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (user_id[j].size() != banned_id[i].size())   continue;
            bool same = true;
            for (int p = 0; p < user_id[j].size(); p++)
            {
                if (banned_id[i][p] == '*')  continue;
                if (banned_id[i][p] != user_id[j][p])
                {
                    same = false;
                    break;
                }
            }
            if (same)   v[i].push_back(j);
        }
    }

    //제재 아이디 목록 경우의 수
    dfs(0);

    return s.size();
}

//Ref:::https://chosh95.tistory.com/342