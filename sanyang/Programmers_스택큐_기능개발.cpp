#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> cur;
    for(auto p:progresses) cur.push(p);
    while(!cur.empty()){
        for(int i=0; i<cur.size(); i++){
            int p=cur.front();
            cur.pop();
            cur.emplace(p+speeds.at(i));
        }
        int cnt=0;
        while(1){
            if(cur.size()>0 && cur.front()>=100){
                cur.pop();
                speeds.erase(speeds.begin());
                cnt++;
                continue;
            }
            break;
        }
        if(cnt>0) answer.emplace_back(cnt);
    }
    return answer;
}

//https://mungto.tistory.com/197
