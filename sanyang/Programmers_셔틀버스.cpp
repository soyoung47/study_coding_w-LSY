//[programmers.co.kr] - 코딩테스트 연습 - 2018 KAKAO BLIND RECRUITMENT - 셔틀버스
//https://programmers.co.kr/learn/courses/30/lessons/17678

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//9시부터 n회 t분 간격, m명의 탑승객
string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int start_t = 540, wait_t = 0, wait_h = 0, wait_m = 0; //540m = 9h
    int count = 0;
    bool keep = true;
    
    //내림차순 정렬
    sort(timetable.begin(), timetable.end(), greater<string>());
    
    //배차 횟수
    for(int i = 0; i < n; i++)
    {
        count = 0;
        
        //탑승객이 차기 전가지
        while(count < m)
        {
            if(!timetable.empty())
            {
                wait_h = stoi(timetable.back().substr(0, 2));
                wait_m = stoi(timetable.back().substr(3, 2));
                //분으로 변경
                wait_t = (60 * wait_h) + wait_m;
                
                if(wait_t <= start_t)
                {
                    //타야하는 버스
                    if(i == n - 1 && count == m - 1)
                    {
                        start_t = wait_t - 1;
                        keep = false;
                        break;
                    }
                    else
                    {
                        count++;
                        timetable.pop_back();
                    }
                }
                else
                {
                    //타야하는 버스
                    if(i == n - 1)
                    {
                        start_t = 540 + (n - 1) * t;
                        keep = false;
                        break;
                    }
                    start_t += t;
                    break;
                }
            }
            else //timetable.empty()
            {
                start_t = 540 + (n - 1) * t;
                keep = false;
                break;
            }
        }
        if(keep == false)
            break;
        
        if(count == m)
            start_t += t;
    }
    
    // int -> str
    if(start_t / 60 < 10)
        answer = "0" + to_string(start_t / 60);
    else
        answer = to_string(start_t / 60);
    
    answer += ":";
    
    if(start_t % 60 < 10)
        answer += "0" + to_string(start_t % 60);
    else
        answer += to_string(start_t % 60);
    
    return answer;
}

//ref: https://eunchanee.tistory.com/100
