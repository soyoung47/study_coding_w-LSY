//Programmers_DFSBFS_여행경로

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<string>> answerlist;

void dfs(vector<vector<string>>& tickets, vector<pair<int, int>>& useCheck, string from, int count) {
    //남은 티켓 없는경우(모두 확인)
    if (count == tickets.size()) {
        vector<string> answer;
        vector<pair<int, int>> temp = useCheck;
        //정렬(abc순)
        sort(temp.begin(), temp.end());
        //순서대로 값 삽입
        for (auto a : temp)        answer.push_back(tickets[a.second][0]);
        //마지막 목적지
        answer.push_back(tickets[temp[temp.size() - 1].second][1]);
        answerlist.push_back(answer);
        return;
    }
    for (int i = 0; i < tickets.size(); i++) {
        //유효티켓, 같은 목적지
        if (useCheck[i].second == -1 && tickets[i][0] == from) {
            //사용 체크
            useCheck[i] = { count, i };
            //재귀 탐색
            dfs(tickets, useCheck, tickets[i][1], count + 1);
            //사용 종료
            useCheck[i] = { 0, -1 };
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    //티켓 사용여부 확인(이미 간 곳 다시 못감)
    vector<pair<int, int>> useCheck(tickets.size(), { 0 , -1 });
    dfs(tickets, useCheck, "ICN", 0);
    sort(answerlist.begin(), answerlist.end());
    return answerlist[0];
}

//https://mungto.tistory.com/54
