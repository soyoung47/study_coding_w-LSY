//https://programmers.co.kr/learn/courses/30/lessons/43163

#include <string>
#include <vector>
#include <queue>
using namespace std;

bool compare(string a, string b)
{
    int cnt = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])    cnt++;
        if (cnt > 1) return false;
    }

    return true;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    //words에 target 단어가 없는 경우
    bool check = false;
    for (string w : words)
    {
        if (w == target)
        {
            check = true;
            break;
        }
    }
    if (!check)  return 0;

    //bfs
    vector<bool> visit(words.size(), false);
    queue<pair<int,int>> q;

    //begin과 한글자만 다른 단어 찾아 큐에 넣기
    for (int i = 0; i < words.size(); i++)
    {
        if (compare(begin, words[i]))
        {
            q.push({ i, 1 });
            visit[i] = true;
        }
    }

    while (!q.empty())
    {
        string str = words[q.front().first];
        int cnt = q.front().second;
        q.pop();

        if (str == target)  return cnt;

        for (int i = 0; i < words.size(); i++)
        {
            if (visit[i])    continue;
            if (compare(str, words[i]))
            {
                visit[i] = true;
                q.push({ i, cnt + 1 });
            }
        }
    }

    return answer;
}