#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

//string split 함수 (Ref:::https://twinw.tistory.com/220)
vector<string> split(string str, char delimiter)
{
    vector<string> arr;
    stringstream ss(str);
    string tmp;

    while (getline(ss, tmp, delimiter))
        arr.push_back(tmp);

    return arr;   
}

vector<string> solution(vector<string> record) {
    
    vector<string> answer;
    map<string, string> m; //userID, nickname
    vector<pair<bool, string>> chat; //isEnter, userID

    for (int i = 0; i < record.size(); i++)
    {
        vector<string> cmd = split(record[i], ' ');

        //채팅방 입장
        if (cmd[0] == "Enter")
        {
            m[cmd[1]] = cmd[2];
            chat.push_back(make_pair(true, cmd[1]));
        }
        //채팅방 퇴장
        else if (cmd[0] == "Leave")
        {
            chat.push_back(make_pair(false, cmd[1]));
        }
        //닉네임 변경
        else if (cmd[0] == "Change")
        {
            m[cmd[1]] = cmd[2];
        }
    }

    for (int i = 0; i < chat.size(); i++)
    {
        bool isEnter = chat[i].first;
        string userID = chat[i].second;

        string str;
        if (isEnter)
            str = "님이 들어왔습니다.";
        else
            str = "님이 나갔습니다.";

        answer.push_back(m[userID] + str);
    }

    return answer;
}