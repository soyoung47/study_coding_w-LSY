#include <string>
#include <vector>
using namespace std;

//int형 숫자 길이 반환
int intLength(int a)
{
    if (a == 1)    return 0;

    int len = 1;

    while (a /= 10)
    {
        len++;
        a /= 10;
    }

    return len;
}

int solution(string s) {
    int answer = 1000;

    int N = s.length();

    if (N == 1)  return 1;

    //문자열 자르는 단위 개수마다 압축 문자열 길이 체크
    for (int i = 1; i <= N / 2; i++)
    {
        string str = s.substr(0, i);
        int cnt = 0;    //압축 문자열 길이
        int same = 1;   //같은 문자열 개수
        for (int j = i; j < N - (N % i); j += i)
        {
            string sub = s.substr(j, i);

            if (str != sub)
            {
                cnt += i + intLength(same);
                str = sub;
                same = 1;
            }
            else
            {
                same++;
            }
        }

        cnt += i + intLength(same) + N % i;

        answer = (answer < cnt) ? answer : cnt;
    }

    return answer;
}