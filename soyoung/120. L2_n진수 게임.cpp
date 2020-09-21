#include <string>
#include <vector>
using namespace std;

string int2str(int num)
{
    if (num < 10)    return to_string(num);

    if (num == 10)   return "A";
    if (num == 11)   return "B";
    if (num == 12)   return "C";
    if (num == 13)   return "D";
    if (num == 14)   return "E";
    if (num == 15)   return "F";
}

string game(int n, int count)
{
    string str = "0";
    int num = 0;

    while (str.size() < count)
    {
        num++;
        if (num < n)
            str += int2str(num);
        else
        {
            string tmpstr = "";
            int tmp = num;
            while (tmp)
            {
                tmpstr = int2str(tmp % n) + tmpstr;
                tmp /= n;
            }
            str += tmpstr;
        }
    }

    return str;
}

string solution(int n, int t, int m, int p) {
    string answer = "";

    //m * t 길이만큼 나열된 숫자 구하기
    string result = game(n, m * t);

    //튜브의 순서에 말해야 하는 숫자 t만큼 출력
    for (int i = p - 1; i < m * t; i += m)
        answer += result[i];
    
    return answer;
}