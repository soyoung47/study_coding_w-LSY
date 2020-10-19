//https://programmers.co.kr/learn/courses/30/lessons/42583

#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, sum = 0, i = 0;
    int size = truck_weights.size();
    queue<int> q;

    while(1)
    {
        answer++;

        int t_w = truck_weights[i];

        if (q.size() == bridge_length)
        {
            sum -= q.front();
            q.pop();
        }

        if (sum + t_w <= weight)
        {
            if (i == size - 1)
            {
                answer += bridge_length;
                break;
            }

            q.push(t_w);
            sum += t_w;
            i++;
        }
        else
            q.push(0);
    }

    return answer;
}