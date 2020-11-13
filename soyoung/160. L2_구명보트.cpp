//https://programmers.co.kr/learn/courses/30/lessons/42885

#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    //사람들의 몸무게 오름차순
    sort(people.begin(), people.end());

    int i = 0, j = people.size() - 1;
    while (i <= j)
    {
        if (people[i] + people[j] <= limit) i++;
        j--;
        answer++;
    }

    return answer;
}