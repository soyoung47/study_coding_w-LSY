//[programmers.co.kr] - 코딩테스트 연습 - 2018 KAKAO BLIND RECRUITMENT - 다트게임
//https://programmers.co.kr/learn/courses/30/lessons/17682

#include <string>
#include <vector>
#include <cmath> //pow(base, exponent)
using namespace std;

int solution(string dartResult) {
    int answer = 0, idx = 0;
    vector<int> scores;
    for (int i = 0; i < dartResult.size(); i++) {
        if (dartResult[i] == 'S') {}
        else if (dartResult[i] == 'D')  scores[idx - 1] = pow(scores[idx - 1], 2);
        else if (dartResult[i] == 'T') scores[idx - 1] = pow(scores[idx - 1], 3);
        else if (dartResult[i] == '*') {
            scores[idx - 1] = scores[idx - 1] * 2;
            if (idx > 1) scores[idx - 2] = scores[idx - 2] * 2;
        }
        else if (dartResult[i] == '#') scores[idx - 1] = scores[idx - 1] * -1;
        else { //isdigit()
            if (dartResult[i + 1] == '0') // 10
            {
                scores.push_back(10);
                i++;
            }
            else scores.push_back(dartResult[i] - '0');
            idx++;
        }
    }
    for (int i = 0; i < scores.size(); i++) answer += scores[i];
    return answer;
}

//https://greenapple16.tistory.com/76
