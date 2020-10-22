//https://programmers.co.kr/learn/courses/30/lessons/43164

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
bool check = false;
void dfs(string airport, vector<string>& tmp, vector<string>& answer, vector<bool>& use, vector<vector<string>>& tickets)
{
    if (tmp.size() == N) 
    { 
        tmp.push_back(airport);
        answer = tmp;
        check = true;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (check)   break;
        if (use[i] || tickets[i][0] != airport)   continue;
        tmp.push_back(airport);
        use[i] = true;

        dfs(tickets[i][1], tmp, answer, use, tickets);
        tmp.pop_back();
        use[i] = false;
    }   
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer, tmp;
    N = tickets.size();
    
    vector<bool> use(N, false); //항공권 사용여부

    sort(tickets.begin(), tickets.end());

    dfs("ICN", tmp, answer, use, tickets);

    return answer;
}