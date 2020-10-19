//Programmers_코드챌린지_코드압축후개수세기

#include <string>
#include <vector>
using namespace std;

vector<vector<int>> map;

void DFS(int x, int y, int size, vector<int> &answer){
    bool zero = 1, one = 1;
    for (int i=x; i<x+size; i++){
        for (int j=y; j<y+size; j++){
            if (map[i][j]==0) one = 0;
            if (map[i][j]==1) zero = 0;
        }
    }
    if (zero==1){
        answer[0]++;
        return;
    }
    if(one==1){
        answer[1]++;
        return;
    }
    DFS(x,y,size/2,answer);
    DFS(x,y+size/2,size/2,answer);
    DFS(x+size/2,y,size/2,answer);
    DFS(x+size/2,y+size/2,size/2,answer);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2,0);
    map = arr;
    DFS(0,0,arr.size(), answer);
    return answer;
}

//ref: https://yabmoons.tistory.com/596
