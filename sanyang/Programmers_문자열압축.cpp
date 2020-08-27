//[programmers.co.kr] - 코딩테스트 연습 - 2020 KAKAO BLIND RECRUITMENT - 문자열 압축
//https://programmers.co.kr/learn/courses/30/lessons/60057

#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = s.size();
    int cnt;
    if (s.size()<=1) return s.size();
    for (int i = 1; i <= s.size() / 2; i++) // size
    {
        cnt = 1;
        string tmpS1 = s.substr(0, i);
        string tmpS2, tmpS3; 
        for (int j = i; j < s.size(); j+=i) //n-th block
        {
            tmpS2 = s.substr(j, i);
            if (!(tmpS1.compare(tmpS2))) cnt++;
            else
            {
                if (cnt == 1)
                {
                    tmpS3 += tmpS1;
                    tmpS1 = tmpS2;
                }
                else
                {
                    tmpS3 += to_string(cnt) + tmpS1; //# + block
                    tmpS1 = tmpS2;
                    cnt = 1;
                }
            }
            if (i + j >= s.size())
            {
                if (cnt != 1)
                {
                    tmpS3 += to_string(cnt) + tmpS1;
                    break;
                }
                else
                {
                    tmpS3 += s.substr(j);
                    break;
                }
            }
        }
        answer = (answer > tmpS3.size()) ? tmpS3.size() : answer;
    }
    return answer;
}

//ref: https://hwan-shell.tistory.com/118
