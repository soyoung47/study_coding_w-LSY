//https://programmers.co.kr/learn/courses/30/lessons/43165

#include <vector>
using namespace std;

void dfs(int& answer, vector<int>& numbers, int target, int ind = 0, int sum = 0)
{
    if (ind == numbers.size())
    {
        if (sum == target)    answer++;
        return;
    }

    dfs(answer, numbers, target, ind + 1, sum + numbers[ind]);
    dfs(answer, numbers, target, ind + 1, sum - numbers[ind]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(answer, numbers, target);
    return answer;
}