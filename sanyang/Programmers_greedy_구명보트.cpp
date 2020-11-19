#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    //오름차순 정렬(123...)
    sort(people.begin(), people.end());
    int idx = 0;
    //남아있는 사람이 있는동안
    while (people.size()>idx){
        //맨앞+맨뒤 무게가 리밋 초과 안한경우 -> 같이 한번 움직임
        if (people[idx]+people.back() <= limit){
            answer++;
            idx++;
            people.pop_back();
        }
        //초과한경우 -> 무거운사람 한번 움직임
        else {
            answer++;
            people.pop_back();
        }
    }
    return answer;
}
