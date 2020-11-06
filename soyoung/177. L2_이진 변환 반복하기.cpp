//https://programmers.co.kr/learn/courses/30/lessons/70129

#include <string>
#include <vector>
using namespace std;

vector<int> solution(string s) {

    int cnt = 0, zero = 0;
    while (s != "1")
    {
        cnt++;

        //x�� 0 ����
        string x = "";
        for (char num : s)
        {
            if (num == '1')  x += num;
            else zero++;
        }

        //x�� ���� c�� ������ȯ
        int c = x.size();
        s = "";
        while (c)
        {
            s = to_string(c % 2) + s;
            c /= 2;
        }
    }

    return { cnt, zero };
}