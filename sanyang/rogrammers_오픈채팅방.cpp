//[programmers.co.kr] - 코딩테스트 연습 - 2019 KAKAO BLIND RECRUITMENT - 오픈채팅방
//https://programmers.co.kr/learn/courses/30/lessons/42888

#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> id_map; //uid, name
    string command, uid, name;

    for (auto line : record)
    {
        stringstream ss(line);
        ss >> command;

        if (command[0] == 'E' || command[0] == 'C') //first character
        {
            ss >> uid;
            ss >> name;
            id_map[uid] = name;
        }
    }

    for (string line : record)
    {
        stringstream ss(line);
        ss >> command;
        ss >> uid;

        if (command[0] == 'E') answer.push_back(id_map[uid] + "님이 들어왔습니다.");
        else if (command[0] == 'L') answer.push_back(id_map[uid] + "님이 나갔습니다.");
    }

    return answer;
}

//ref: https://softworking.tistory.com/279

// https://modoocode.com/224 (unordered map)
// https://word.tistory.com/24 (stringstream) split string by null
