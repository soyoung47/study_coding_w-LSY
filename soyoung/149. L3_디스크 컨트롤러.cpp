//https://programmers.co.kr/learn/courses/30/lessons/42627

#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int size = jobs.size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;   //(��û�Ǵ� ����, (�۾��ҿ�ð�, index))

    for (int i = 0; i < size; i++)
        pq.push({ jobs[i][0], { jobs[i][1], i } });

    int start, end, ind, ntime;
    while (!pq.empty())
    {
        start = pq.top().first; //�۾��� ���۵Ǵ� ����
        end = pq.top().second.first;    //�۾��� �ҿ�ð�
        ind = pq.top().second.second;
        pq.pop();

        //��û���� ������� �ɸ� �ð�
        answer += start - jobs[ind][0] + end;

        if (pq.empty())  break;

        ntime = start + end;    //�۾��Ϸ����
        while (ntime > pq.top().first)
        {
            pq.push({ ntime, pq.top().second });
            pq.pop();
        }
    }

    return answer / size;
}