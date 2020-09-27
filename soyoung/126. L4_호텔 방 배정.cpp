//https://programmers.co.kr/learn/courses/30/lessons/64063

#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

long long ans;  //������ �� ��ȣ
unordered_map<long long, long long> m;  //m[������ �� ��ȣ ���] = �θ� ��� ���ȣ
queue<long long> q; //������ �湮�� �� ��ȣ ���

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
        while (!q.empty())  //������ �湮�� �� ��ȣ ����� �θ� ��带 ans������ ����
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