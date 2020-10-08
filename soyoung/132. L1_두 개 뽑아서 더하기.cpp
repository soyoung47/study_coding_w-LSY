//https://programmers.co.kr/learn/courses/30/lessons/68644

#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> s;

    int size = numbers.size();
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            s.insert(numbers[i] + numbers[j]);
        }
    }

    for (auto it = s.begin(); it != s.end(); it++)
    {
        answer.push_back(*it);
    }

    return answer;
}