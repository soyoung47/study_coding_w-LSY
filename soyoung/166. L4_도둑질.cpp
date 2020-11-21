//https://programmers.co.kr/learn/courses/30/lessons/42897

#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> money) {
    int N = money.size();
    vector<int> v1(N, money[0]);   //첫번째 집부터
    vector<int> v2(N, money[1]);   //두번째 집부터

    v2[0] = 0;

    for (int i = 2; i < N; i++)
    {
        if (i < N - 1)  //첫번째 집 방문 한 경우 마지막 집은 방문하면 안됨.
            v1[i] = max(v1[i - 2] + money[i], v1[i - 1]);
        v2[i] = max(v2[i - 2] + money[i], v2[i - 1]);
    }

    return max(v1[N - 2], v2[N - 1]);
}