#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> chk(n,1);
    //0,1,2
    for(auto l:lost) chk[l-1]--;
    for(auto r:reserve) chk[r-1]++;
    for(int i=0; i<chk.size(); i++){
        //체육복 없는 경우(0)
        if (!chk[i]){
            //맨 뒤가 아니고, 뒷사람이 2벌있는경우
            if (i!=chk.size()-1 && chk[i+1]==2){
                //뒷사람 체육복을 앞학생에게
                chk[i+1]--;
                chk[i]++;
            }
            //맨 앞이 아니고, 앞사람이 2벌있는경우
            else if (i && chk[i-1]==2){
                //앞사람 체육복을 뒤학생에게
                chk[i-1]--;
                chk[i]++;
            }
        }
    }
    //전체 돌면서 한벌 이상 있는경우 카운트
    for(auto c:chk) if (c!=0) answer++;
    return answer;
}

//ref: https://prgms.tistory.com/33
//https://programmers.co.kr/learn/courses/30/lessons/42862
