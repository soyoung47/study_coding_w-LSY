//Programmers_정렬_K번째수

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(auto co:commands){
        vector<int> tmp;
        for (int i=0; i<co[1]-co[0]+1; i++){
            tmp.emplace_back(array[co[0]-1+i]);
        }
        sort(tmp.begin(), tmp.end());
        answer.emplace_back(tmp[co[2]-1]);
    }
    return answer;
}
