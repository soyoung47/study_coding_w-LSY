////[programmers.co.kr] - 코딩테스트 연습 - 2018 KAKAO BLIND RECRUITMENT - 방금그곡
//https://programmers.co.kr/learn/courses/30/lessons/17683

#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

//멜로디 문자열에서 # 제거
string change(string &in, map<string, char> &s)
{
    string out = "";
    
    for(int i = 0; i < in.size(); i++)
    {
        if(in[i + 1] == '#')
        {
            out += s[in.substr(i, 2)];
            i++;
        }
        else    out += in[i];
    }
    return out;
}
string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int sHour = 0, eHour = 0, sMin = 0, eMin = 0, time = 0, sTime = 0;
    string melody = "", title = "";
    map<string, char> s;
    
    s["C#"] = 'c';
    s["D#"] = 'd';
    s["F#"] = 'f';
    s["G#"] = 'g';
    s["A#"] = 'a';
    
    melody = change(m, s);
    
    for(int i = 0; i < musicinfos.size(); i++)
    {
        string tmp = "", music = "";
        //h->m
        sHour = stoi(musicinfos[i].substr(0, 2)) * 60;
        sMin = stoi(musicinfos[i].substr(3, 2));
        eHour = stoi(musicinfos[i].substr(6, 2)) * 60;
        eMin = stoi(musicinfos[i].substr(9, 2));
        time = (eHour + eMin) - (sHour + sMin);
        
        //Divide title and Melody from musicinfos
        //tmp == melody
        for(int j = 12; musicinfos[i].size(); j++)
        {
            //,전까지 타이틀
            if(musicinfos[i][j] == ',')
            {
                title = musicinfos[i].substr(12, j - 12);
                tmp = musicinfos[i].substr(j + 1);
                break;
            }
        }
        
        music = change(tmp, s);

        if(music.size() < time)
        {
            tmp = music;
            //반복 시간만큼 문자열 연장
            for(int j = 1; j < time / tmp.size(); j++)
                music += tmp;
            for(int j = 0; j < time % tmp.size(); j++)
                music += tmp[j];
        }
        else
            music = music.substr(0, time);
        
        if(music.find(melody) != string::npos)
        {
            if(sTime < time)
            {
                answer = title;
                sTime = time;
            }
        }
    }
    return answer;
}

//ref: https://eunchanee.tistory.com/79
