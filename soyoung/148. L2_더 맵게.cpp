//https://programmers.co.kr/learn/courses/30/lessons/42626

#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int sc : scoville)  pq.push(sc);

    while (!pq.empty())
    {
        int one = pq.top();
        pq.pop();

        if (one >= K)    return answer;
        if (pq.empty())  return -1;

        int two = pq.top();
        pq.pop();

        int level = one + two * 2;
        pq.push(level);
        answer++;
    }
}