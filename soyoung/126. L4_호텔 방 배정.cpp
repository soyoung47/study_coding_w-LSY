//https://programmers.co.kr/learn/courses/30/lessons/64063

#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

long long ans;  //배정된 방 번호
unordered_map<long long, long long> m;  //m[배정된 방 번호 노드] = 부모 노드 방번호
queue<long long> q; //이전에 방문한 방 번호 노드

void check_in(long long num)
{
    if (m.count(num) != 0)
    {
        q.push(num);
        check_in(m[num]);        
    }
    else
    {
        m[num] = num + 1;
        ans = num;
    }
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    
    for (int i = 0; i < room_number.size(); i++)
    {
        check_in(room_number[i]);
        while (!q.empty())  //이전에 방문한 방 번호 노드의 부모 노드를 ans값으로 변경
        {
            long long before = q.front();
            q.pop();
            m[before] = ans;
        }
        answer.push_back(ans);
    }

    return answer;
}

//Ref:::https://tech.kakao.com/2020/04/01/2019-internship-test/