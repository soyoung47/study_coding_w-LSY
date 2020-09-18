//https://programmers.co.kr/learn/courses/30/lessons/17684

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> m;

    //1. 사전 초기화
    string ch = "A";
    for (int i = 1; i <=26; i++)
    {
        m[ch] = i;
        ch = ch[0] + 1;
    }

    int ind = 27;
    string str = "", w = "";
    while (1)
    {
        str = msg[0];

        //2. 사전에서 현재 입력과 일치하는 가장 긴 문자열 w 찾기
        int i = 0, cnt = 1;
        while (cnt <= msg.size())
        {
            if (!m.count(str))   break;

            w = str;
            cnt++;
            str = msg.substr(i, cnt);
        }

        //3. w에 해당하는 사전의 색인 번호 출력, 입력에서 w제거
        answer.push_back(m[w]);
        msg = msg.substr(i + cnt - 1);

        //4. 처리되지 않은 다음 글자(c) 남아 있다면 w+c에 해당하는 단어 사전 등록
        if (msg.empty())    break;
        m[w + msg[0]] = ind;

        ind++;
    }    
    
    return answer;
}