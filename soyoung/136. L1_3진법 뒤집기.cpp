//https://programmers.co.kr/learn/courses/30/lessons/68935

#include <stack>
#include <math.h>
using namespace std;

int solution(int n) {
    int answer = 0;

    stack<int> s;
    while (n != 0)
    {
        s.push(n % 3);
        n /= 3;
    }

    int i = 0;
    while (!s.empty())
    {
        answer += pow(3, i) * s.top();
        s.pop();
        i++;
    }

    return answer;
}
