#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights){
    int answer=0, curW=0;
    queue<int> cnt, brgOn;
    while(1){
        int size=brgOn.size();
        for (int i=0; i<size; i++){
            int len=brgOn.front();
            brgOn.pop();
            if(len<=1){
                curW-=cnt.front();
                cnt.pop();
                continue;
            }
            brgOn.emplace(len-1);
        }
        if(truck_weights.size()>0 &&curW+truck_weights.at(0)<=weight){
            cnt.emplace(truck_weights.at(0));
            curW+=truck_weights.at(0);
            brgOn.emplace(bridge_length);
            truck_weights.erase(truck_weights.begin());
        }
        answer++;
        if(truck_weights.size()==0 && cnt.size()==0) break;
    }
    return answer;
}

//https://mungto.tistory.com/4
