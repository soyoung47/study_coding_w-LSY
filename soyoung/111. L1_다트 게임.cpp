#include <string>
#include <math.h>
#include <vector>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> dart;
    string nstr = "";

    for (int i = 0; i < dartResult.size(); i++)
    {
        char ch = dartResult[i];
        if (ch >= '0' && ch <= '9')
        {
            nstr += ch;
        }
        else
        {
            int num = atoi(nstr.c_str());
            
            if (ch == 'S')
                dart.push_back(num);
            else if (ch == 'D')
                dart.push_back(pow(num, 2));
            else if (ch == 'T')
                dart.push_back(pow(num, 3));
            else if (ch == '*')
            {
                dart[dart.size()-1] *= 2;
                if (dart.size() > 1)
                    dart[dart.size() - 2] *= 2;
            }
            else if (ch == '#')
                dart[dart.size() - 1] *= -1;

            nstr = "";
        }
    }

    answer = dart[0] + dart[1] + dart[2];
    return answer;
}

//Ref:::https://velog.io/@wooyoung_tom/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-2018-KAKAO-BLIND-RECRUITMENT-%EB%8B%A4%ED%8A%B8-%EA%B2%8C%EC%9E%84