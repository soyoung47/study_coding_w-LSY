//Programmers_해시_위장

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> map;
    for(int i=0; i<clothes.size(); i++){
        //각 카테고리에 몇개씩 있는지 카운트
        if(!map[clothes[i][1]]){
            map[clothes[i][1]]=1;
        }
        else map[clothes[i][1]]++;
    }
    for(auto m:map){
        //입지 않는 경우+1
        answer *= (m.second+1);
    }
    //모두 안입은경우-1
    return answer-1;
}

int main(){
    vector<vector<string>> clothes = {{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}};
    solution(clothes);
    return 0;
}

//ref: https://wannabe-gosu.tistory.com/36
