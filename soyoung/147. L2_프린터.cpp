//https://programmers.co.kr/learn/courses/30/lessons/42587

#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int N = priorities.size();
    map<int, int, greater<int>> m;
    queue<pair<int, int>> q;    //중요도, index

    //중요도 체크, 대기목록 저장
    for (int i = 0; i < N; i++)
    {
        m[priorities[i]]++;
        q.emplace(priorities[i], i);
    }

    while (!q.empty())
    {
        pair<int, int> j = q.front();
        q.pop();

        int prior = j.first;
        int ind = j.second;

        //j보다 중요도 높은 문서가 대기목록에 있으면 j를 가장 마지막으로 이동, 없다면 j 인쇄
        if (m.begin()->first > prior)
            q.emplace(j);
        else
        {
            m[prior]--;
            if (m[prior] == 0)   m.erase(prior);
            answer++;
            if (ind == location) break;
        }
    }

    return answer;
}