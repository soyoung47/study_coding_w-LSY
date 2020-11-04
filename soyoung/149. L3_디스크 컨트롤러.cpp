//https://programmers.co.kr/learn/courses/30/lessons/42627

#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int size = jobs.size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;   //(요청되는 시점, (작업소요시간, index))

    for (int i = 0; i < size; i++)
        pq.push({ jobs[i][0], { jobs[i][1], i } });

    int start, end, ind, ntime;
    while (!pq.empty())
    {
        start = pq.top().first; //작업이 시작되는 시점
        end = pq.top().second.first;    //작업의 소요시간
        ind = pq.top().second.second;
        pq.pop();

        //요청에서 종료까지 걸린 시간
        answer += start - jobs[ind][0] + end;

        if (pq.empty())  break;

        ntime = start + end;    //작업완료시점
        while (ntime > pq.top().first)
        {
            pq.push({ ntime, pq.top().second });
            pq.pop();
        }
    }

    return answer / size;
}