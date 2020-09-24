//[programmers.co.kr] - 코딩테스트 연습 - 2018 KAKAO BLIND RECRUITMENT - 추석트래픽
//https://programmers.co.kr/learn/courses/30/lessons/17676

#include <string>
#include <vector>
using namespace std;

int solution(vector<string> lines) {
    //초당 최대 처리양 = 1초(1000미리초) 동안의 최대 요청 수
    //로그 문자열 2016-09-15 03:10:33.020 0.011s은
    //2016년 9월 15일 오전 3시 10분 **33.010초**부터
    //2016년 9월 15일 오전 3시 10분 **33.020초**까지 **0.011초** 동안 처리된 요청을 의미
    int answer = 0;
    vector<int> start_t, end_t;
    
    //입력값 ms로 변경
    for(int i = 0; i < lines.size(); i++)
    {
        string h, m, s, ms;
        int ih, im, is, process;
        
        lines[i].pop_back(); //s 제거
        h = lines[i].substr(11, 2);
        m = lines[i].substr(14, 2);
        s = lines[i].substr(17, 2);
        ms = lines[i].substr(20, 3);
        process = stof(lines[i].substr(24, 5)) * 1000;
        
        //ms로 변경
        ih = stoi(h) * 3600 * 1000;
        im = stoi(m) * 60 * 1000;
        is = stoi(s) * 1000 + stoi(ms);
        
        start_t.emplace_back(ih + im + is - process + 1);
        end_t.emplace_back(ih + im + is);
    }
    
    //line 돌면서 카운트 확인, 최대카운트 리턴
    for(int i = 0; i < lines.size(); i++)
    {
        int end_time = end_t[i] + 1000;
        int count = 0;
        
        for(int j = i; j < lines.size(); j++)
        {
            if(start_t[j] < end_time)
                count++;
        }
        
        if(answer < count)
            answer = count;
    }
    return answer;
}


//ref: https://eunchanee.tistory.com/98?category=1114733


