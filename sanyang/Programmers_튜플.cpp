//[programmers.co.kr] - 코딩테스트 연습 - 2019 카카오 개발자 겨울 인턴십 - 튜플
//https://programmers.co.kr/learn/courses/30/lessons/64065

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//sort: ascending by length
bool asc(vector<int> a, vector<int> b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    bool chk[100001] = { false, }, open = 0;
    //num을 가지고있는 v
    vector<vector<int>> v;
    //튜플 str->int로 바꿔담을 num
    vector<int> num;
    string tmp = "";

    //맨 앞, 맨 뒤 괄호 제외
    for (int i = 1; i < s.size() - 1; i++) {
        //튜플 시작
        if (open == 0 && s[i] == '{') open = 1;
        //튜플 내용이 숫자->tmp에 추가
        else if (open == 1 && (s[i] >= '0' && s[i] <= '9')) tmp.push_back(s[i]);
        //,가 나오면 tmp를 int로 바꿔 num에 넣어줌
        else if (open == 1 && s[i] == ',') {
            int t = stoi(tmp);
            num.push_back(t);
            tmp = "";
        }
        //v벡터에 num넣어주고 튜플 종료
        //다음 튜플을 위해 변수 초기화
        else if (open == 1 && s[i] == '}') {
            int t = stoi(tmp);
            num.push_back(t);
            v.push_back(num);
            open = 0;
            tmp = "";
            num.clear();
        }
    }

    //길이가 짧은것부터 정렬
    sort(v.begin(), v.end(), asc);

    //chk 0: 중복x -> answer에 넣고 chk표시
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (chk[v[i][j]] == 0) {
                chk[v[i][j]] = 1;
                answer.push_back(v[i][j]);
            }
        }
    }
    return answer;
}

//ref: https://eunchanee.tistory.com/71
