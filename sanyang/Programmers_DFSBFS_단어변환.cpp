//https://programmers.co.kr/learn/courses/30/lessons/43163

#include <string>
#include <vector>
using namespace std;
int answer{ 100 };

void dfs(string begin, string target, vector<string> words, vector<bool>& useCheck, int cnt = 0) {
    for (int i = 0; i < words.size(); i++) {
        int count{ 0 };
        //한글자씩 비교 -> 글자 다르면 cnt++
        for (int j = 0; j < words[i].length(); j++)
            if (!useCheck[i] && begin[j] != words[i][j])    count++;
        if (count == 1) {
            //target이랑 같고, 현재깊이+1: update
            if (target == words[i] && answer > cnt + 1) {
                answer = cnt + 1;
                return;
            }
            //이미 사용
            useCheck[i] = true;
            dfs(words[i], target, words, useCheck, cnt + 1);
            //사용 해제
            useCheck[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    vector<bool> useCheck(words.size(), false);
    dfs(begin, target, words, useCheck);
    if (answer == 100)   return 0;
    return answer;
}

//https://mungto.tistory.com/53?category=734741
