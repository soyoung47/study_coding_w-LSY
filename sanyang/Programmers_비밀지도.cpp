//[programmers.co.kr] - 코딩테스트 연습 - 2018 KAKAO BLIND RECRUITMENT - 비밀지도
//https://programmers.co.kr/learn/courses/30/lessons/17681

#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    int tmp;
    string s1, s2;
    for (int i = 0; i < n; i++) {
        tmp = arr1[i] | arr2[i];
        answer[i].assign(n, ' ');
        for (int j = 0; j < n; j++) {
            if (tmp % 2 == 1) answer[i][n-j-1] = '#';
            tmp /= 2;
        }
    }
    return answer;
}

//https://chaibin0.tistory.com/entry/%EB%B9%84%EB%B0%80%EC%A7%80%EB%8F%84
