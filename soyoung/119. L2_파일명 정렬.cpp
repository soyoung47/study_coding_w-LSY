//https://programmers.co.kr/learn/courses/30/lessons/17686

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<string, int> m;
vector<vector<string>> v;

bool comp(string a, string b)
{
    int i = m[a], j = m[b];

    string ha = v[i][0], hb = v[j][0];
    transform(ha.begin(), ha.end(), ha.begin(), ::tolower);
    transform(hb.begin(), hb.end(), hb.begin(), ::tolower);

    int na = stoi(v[i][1]), nb = stoi(v[j][1]);

    if (ha == hb)   return na < nb;
    return ha < hb;
}

vector<string> solution(vector<string> files) {
    vector<string> answer = files;
    int size = files.size();

    //각 파일명 HEAD, NUMBER, TAIL로 분리해 v에 저장
    for (int i = 0; i < size; i++)
    {
        vector<string> f;
        string str = files[i];

        //index 저장
        m[str] = i;

        //HEAD: 숫자가 아닌 문자
        int j = 0; string head = "";
        while (!isdigit(str[j]))
        {
            head += str[j];
            j++;
        }
        f.push_back(head);
        str = str.substr(j);

        //NUMBER: 숫자로만 이루어진 문자열(1~5)
        j = 0; string num = "";
        while (j < str.size() && j < 5 && isdigit(str[j]))
        {
            num += str[j];
            j++;
        }
        f.push_back(num);

        v.push_back(f);
    }

    stable_sort(answer.begin(), answer.end(), comp);

    return answer;
}