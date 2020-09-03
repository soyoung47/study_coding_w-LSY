#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<double, int> a, pair<double, int> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> late;

    int total = stages.size();
    vector<int> noClear(N+2, 0);  //분모
    for (int i = 0; i < total; i++)
    {
        noClear[stages[i]] += 1;
    }

    vector<int> arrive(N+1, total);  //분자
    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        sum += noClear[i-1];
        arrive[i] -= sum;
    }
    
    for (int i = 1; i <= N; i++)
    {
        double fail = 0.0;
        if (noClear[i] == 0 || arrive[i] == 0)   fail = 0.0;
        else
            fail = (double)noClear[i] / (double)arrive[i];

        late.push_back(make_pair(fail, i));
    }

    //실패율 높은 순으로 내림차순, 같다면 작은 stage 번호가 먼저
    sort(late.begin(), late.end(), comp);

    for (int i = 0; i < late.size(); i++)
    {
        answer.push_back(late[i].second);
    }

    return answer;
}