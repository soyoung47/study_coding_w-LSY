//https://programmers.co.kr/learn/courses/30/lessons/42860?language=cpp

#include <string>
#include <algorithm>
using namespace std;

int solution(string name) {
    int answer = 0, i = 0;
    int len = name.size();
    string str(len, 'A');   //초기 문자열

    while (1)
    {
        //최소 이동 횟수 (위/아래:알파벳 찾기)
        str[i] = name[i];
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);

        if (str == name) break;

        //커서 이동 (오/왼 중 가까운 쪽으로 이동)
        for (int j = 1; j < len; j++)
        {
            int ind = (i + j) % len;
            int n_ind = (i + len - j) % len;
            if (name[ind] != str[ind])
            {
                i = ind;
                answer += j;
                break;
            }
            else if (name[n_ind] != str[n_ind])
            {
                i = n_ind;
                answer += j;
                break;
            }
        }
    }

    return answer;
}

//https://mungto.tistory.com/44