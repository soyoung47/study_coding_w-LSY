#include <string>
#include <vector>
using namespace std;

//int�� ���� ���� ��ȯ
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

    //���ڿ� �ڸ��� ���� �������� ���� ���ڿ� ���� üũ
    for (int i = 1; i <= N / 2; i++)
    {
        string str = s.substr(0, i);
        int cnt = 0;    //���� ���ڿ� ����
        int same = 1;   //���� ���ڿ� ����
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