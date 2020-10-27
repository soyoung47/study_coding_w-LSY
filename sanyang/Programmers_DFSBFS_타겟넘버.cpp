//https://programmers.co.kr/learn/courses/30/lessons/43165

#include <vector>
using namespace std;

//처음부터 마지막까지 + - 번갈아가며 dfs로 모든 경우의 수 구하기
void dfs(vector<int>& numbers, int& answer, int target, int count = 0, int sum = 0){
    //끝까지 순회
    if (count == numbers.size() - 1) {
        //마지막원소 더하거나 빼서 타겟과 동일하면 ++
        if (target == sum + numbers[count])        answer++;
        if (target == sum - numbers[count])        answer++;
        return;
    }
    //끝까지 안갔으면 +-해서 재탐색
    dfs(numbers, answer, target, count + 1, sum + numbers[count]);
    dfs(numbers, answer, target, count + 1, sum - numbers[count]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, answer, target);
    return answer;
}


//https://mungto.tistory.com/51
