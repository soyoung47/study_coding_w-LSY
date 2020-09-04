#include <string>
#include <vector>
#include <map>
#include <memory.h>
#include <algorithm>
using namespace std;

int col, row;
bool visit[8];
vector<string> key;

void dfs(int ind, int cnt, int n)
{
    if (cnt == n)
    {
        string str = "";
        for (int i = 0; i < col; i++)
        {
            if (visit[i])
                str += to_string(i);
        }
        key.push_back(str);
        return;
    }
    
    for (int i = ind; i < col; i++)
    {
        if (visit[i])    continue;
        visit[i] = true;

        dfs(i, cnt + 1, n);
        visit[i] = false;
    }
}

bool unique(vector<vector<string>>& relation, string cmd)
{
    map<string, int> m;
    for (int i = 0; i < row; i++)
    {
        string str = "";
        for (int j = 0; j < cmd.size(); j++)
        {
            str += relation[i][cmd[j] - '0'] + "/";
        }
        m[str]++;
        if (m[str] > 1)     return false;
    }
    return true;
}

int solution(vector<vector<string>> relation) {

    int answer = 0;

    col = relation[0].size();   //속성의 개수
    row = relation.size();      //튜플의 개수

    //속성들의 모든 부분 집합 구하기(조합)
    for (int i = 1; i <= col; i++)
    {
        memset(visit, false, sizeof(bool));
        dfs(0, 0, i);
    }
    
    //유일성 조건을 만족하는 속성 집합 찾기
    for (int i = 0; i < key.size(); i++)
    {
        //유일성 조건을 만족하는 경우, key값이 포함된 속성 부분집합 제외
        if (unique(relation, key[i]))
        {
            string uniKEY = key[i];
            for (int j = i; j < key.size(); j++)
            {
                if (includes(key[j].begin(), key[j].end(), uniKEY.begin(), uniKEY.end()))
                {
                    key.erase(key.begin() + j);
                    j--;
                }
            }
            i--;
            answer++;
        }
    }

    return answer;
}

//Ref:::https://tech.kakao.com/2018/09/21/kakao-blind-recruitment-for2019-round-1/, https://blog.naver.com/daum7766/221708449857, https://programmers.co.kr/questions/12385