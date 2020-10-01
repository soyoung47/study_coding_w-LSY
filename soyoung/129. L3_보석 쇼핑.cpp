//https://programmers.co.kr/learn/courses/30/lessons/67258

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    unordered_map<string, int> m;
    int size = gems.size();
    int left = 0;    //��������
    int n_kind; //���� ���� ����
    int range = 100000; //���� ����
    
    //���� ���� ���� �ľ�
    for (int i = 0; i < size; i++)
        m[gems[i]]++;

    n_kind = m.size();
    m.clear();
    
    //��� ������ ���� �����ϴ� ���� ª�� ���� ã��
    for (int right = 0; right < size; right++)
    {
        //���� ���� �� �����Ҷ����� right++
        m[gems[right]]++;

        if (m.size() == n_kind)
        {
            //���� �����ϰ�, left++
            while (m.size() == n_kind)
            {
                m[gems[left]]--;
                if (m[gems[left]] == 0)
                    m.erase(gems[left]);
                left++;
            }
            //���� ª�� �������� Ȯ��
            if (right - left - 1 < range)
            {
                range = right - left - 1;
                answer = { left, right + 1 };
            }
        }
    }

    return answer;
}

//Ref:::https://tech.kakao.com/2020/07/01/2020-internship-test/, https://blog.naver.com/oyh951416/222025940771