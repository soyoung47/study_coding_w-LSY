//Programmers_해시_완주하지못한선수

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> map;
    for(auto name:participant){
        map[name]++;
    }
    for(auto name:completion){
        map[name]--;
    }
    for(auto p:map){
        if (p.second>0) return p.first;
    }
}

//ref: https://jhnyang.tistory.com/120
