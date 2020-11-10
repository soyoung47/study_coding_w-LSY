//https://programmers.co.kr/learn/courses/30/lessons/42860?language=cpp

#include <string>
#include <algorithm>
using namespace std;

int solution(string name) {
    int answer = 0, i = 0;
    int len = name.size();
    string str(len, 'A');   //�ʱ� ���ڿ�

    while (1)
    {
        //�ּ� �̵� Ƚ�� (��/�Ʒ�:���ĺ� ã��)
        str[i] = name[i];
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);

        if (str == name) break;

        //Ŀ�� �̵� (��/�� �� ����� ������ �̵�)
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