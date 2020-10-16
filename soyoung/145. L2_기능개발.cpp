//https://programmers.co.kr/learn/courses/30/lessons/42586

#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int size = progresses.size();
    queue<int> q;

    for (int i = 0; i < size; i++)
    {
        int day = (100 - progresses[i]) / speeds[i];
        if ((100 - progresses[i]) % speeds[i] != 0)  day += 1;

        if (!q.empty() && q.front() < day)
        {
            answer.push_back(q.size());
            while (!q.empty()) q.pop();
        }
        q.push(day);
    }

    if(!q.empty())
        answer.push_back(q.size());

    return answer;
}