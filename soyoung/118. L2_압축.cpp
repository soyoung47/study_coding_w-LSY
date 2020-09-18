//https://programmers.co.kr/learn/courses/30/lessons/17684

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> m;

    //1. ���� �ʱ�ȭ
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

        //2. �������� ���� �Է°� ��ġ�ϴ� ���� �� ���ڿ� w ã��
        int i = 0, cnt = 1;
        while (cnt <= msg.size())
        {
            if (!m.count(str))   break;

            w = str;
            cnt++;
            str = msg.substr(i, cnt);
        }

        //3. w�� �ش��ϴ� ������ ���� ��ȣ ���, �Է¿��� w����
        answer.push_back(m[w]);
        msg = msg.substr(i + cnt - 1);

        //4. ó������ ���� ���� ����(c) ���� �ִٸ� w+c�� �ش��ϴ� �ܾ� ���� ���
        if (msg.empty())    break;
        m[w + msg[0]] = ind;

        ind++;
    }    
    
    return answer;
}