//[programmers.co.kr] - 코딩테스트 연습 - 2018 KAKAO BLIND RECRUITMENT - 
//https://programmers.co.kr/learn/courses/30/lessons/17684

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> m; //char, idx
    int idx;
    string tmp = "";
    
    //1. 길이가 1인 모든 단어를 포함하는 사전 초기화
    for (idx = 1; idx <= 26; idx++) {
        tmp += 'A' + idx - 1; //A, B, C, ...
        m.emplace(tmp, idx); //vector++
        tmp = "";
    }
    
    //2. 한글자씩 추가하며 매치 확인
    for (int i=0; i<msg.size(); i++){
        string tmp = "";
        tmp += msg[i];
        int j=i;
        int cnt=0;
        
        //3. 있으면: 가장 긴 문자열 tmp 찾기
        while (m.find(tmp) != m.end()){
            cnt++;
            j++;
            tmp += msg[j];
        }
        
        //4. 사전에 새로운 문자열을 넣고, tmp는 비우고, answer에 이전 색인 출력(KA넣고 K색인 출력)
        i += cnt-1;
        m.emplace(tmp, idx++);
        tmp.pop_back();
        answer.emplace_back(m[tmp]);
    }
    
    return answer;
}

//ref: https://hwan-shell.tistory.com/156
