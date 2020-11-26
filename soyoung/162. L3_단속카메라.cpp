//https://programmers.co.kr/learn/courses/30/lessons/42884

#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;

    //진입 시점 기준으로 오름차순 정렬
    sort(routes.begin(), routes.end());

    int end = routes[0][1];
    for (int i = 1; i < routes.size(); i++)
    {
        if (end > routes[i][1])
            end = routes[i][1];
        else if (end < routes[i][0])
        {
            answer++;
            end = routes[i][1];
        }
    }

    return answer;
}

//REF:::https://blog.naver.com/tkddn0928/221812487781