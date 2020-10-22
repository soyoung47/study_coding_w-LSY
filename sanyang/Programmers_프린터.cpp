#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer=0, cnt=0;
    queue<pair<int, int>> q;
    priority_queue<int> pr_q;
    for (int i=0; i<priorities.size(); i++){
        q.emplace(i, priorities[i]);
        pr_q.emplace(priorities[i]);
    }
    while(!q.empty()){
        int idx=q.front().first;
        int val=q.front().second;
        q.pop();
        if(pr_q.top()==val){
            pr_q.pop();
            cnt++;
            if(idx==location){
                answer=cnt;
                break;
            }
        }
        else q.emplace(idx,val);
    }

    return answer;
}

//https://mungto.tistory.com/198
