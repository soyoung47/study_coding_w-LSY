//https://programmers.co.kr/learn/courses/30/lessons/42578

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    int size = clothes.size();
    unordered_map<string, int> m;

    //�ǻ� ������ �ǻ� ���� ����
    for (int i = 0; i < size; i++)
        m[clothes[i][1]]++;
    
    //���� �ٸ� ���� ������ �� ���ϱ� : ������ ����(m[����[ + ���Դ� ���(1)
    for (auto iter = m.begin(); iter != m.end(); iter++)
        answer *= (iter->second + 1);

    return answer - 1;
}