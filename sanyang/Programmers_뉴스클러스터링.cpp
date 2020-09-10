//[programmers.co.kr] - 코딩테스트 연습 - 2018 KAKAO BLIND RECRUITMENT - 뉴스 클러스터링
// https://programmers.co.kr/learn/courses/30/lessons/17677

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0, intersec = 0, uni = 0;
    vector<string> s1, s2, words;

    //A->a
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    //split -> if both are alphabets -> s1, s2
    for (int i = 0; i < str1.size() - 1; i++) {
        string tmp = str1.substr(i, 2);
        if (tmp[0] >= 'a' && tmp[0] <= 'z' && tmp[1] >= 'a' && tmp[1] <= 'z')
            s1.push_back(tmp);
    }

    for (int i = 0; i < str2.size() - 1; i++) {
        string tmp = str2.substr(i, 2);
        if (tmp[0] >= 'a' && tmp[0] <= 'z' && tmp[1] >= 'a' && tmp[1] <= 'z')
            s2.push_back(tmp);
    }

    if (s1.empty() && s2.empty()) return 65536;

    uni = s1.size() + s2.size();

    //count #intersection
    if (s1.size() > s2.size()) {
        for (int i = 0; i < s2.size(); i++) {
            auto itr = find(s1.begin(), s1.end(), s2[i]);
            if (itr != s1.end()) {
                intersec++;
                s1.erase(itr);
            }
        }
    }
    else {
        for (int i = 0; i < s1.size(); i++) {
            auto itr = find(s2.begin(), s2.end(), s1[i]);
            if (itr != s2.end()) {
                intersec++;
                s2.erase(itr);
            }
        }
    }

    uni -= intersec;
    if (uni == 0) return 65536;
    double tmp = (double)intersec / (double)uni;
    answer = tmp * 65536;

    return answer;
}

//ref: https://eunchanee.tistory.com/75
