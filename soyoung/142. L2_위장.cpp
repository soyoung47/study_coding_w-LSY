//https://programmers.co.kr/learn/courses/30/lessons/42578

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    int size = clothes.size();
    unordered_map<string, int> m;

    //의상 종류별 의상 개수 저장
    for (int i = 0; i < size; i++)
        m[clothes[i][1]]++;
    
    //서로 다른 옷의 조합의 수 구하기 : 종류별 개수(m[종류[ + 안입는 경우(1)
    for (auto iter = m.begin(); iter != m.end(); iter++)
        answer *= (iter->second + 1);

    return answer - 1;
}