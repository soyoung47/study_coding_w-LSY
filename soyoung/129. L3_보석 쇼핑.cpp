//https://programmers.co.kr/learn/courses/30/lessons/67258

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    unordered_map<string, int> m;
    int size = gems.size();
    int left = 0;    //투포인터
    int n_kind; //보석 종류 개수
    int range = 100000; //구간 길이
    
    //보석 종류 개수 파악
    for (int i = 0; i < size; i++)
        m[gems[i]]++;

    n_kind = m.size();
    m.clear();
    
    //모든 종류의 보석 포함하는 가장 짧은 구간 찾기
    for (int right = 0; right < size; right++)
    {
        //보석 종류 다 포함할때까지 right++
        m[gems[right]]++;

        if (m.size() == n_kind)
        {
            //보석 제거하고, left++
            while (m.size() == n_kind)
            {
                m[gems[left]]--;
                if (m[gems[left]] == 0)
                    m.erase(gems[left]);
                left++;
            }
            //가장 짧은 구간인지 확인
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