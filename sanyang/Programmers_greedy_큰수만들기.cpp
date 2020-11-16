#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    //전체 길이만큼 체크
    for(int i=0, idx=-1; i<number.length()-k; i++){
        char max=0;
        //남는 숫자 중 가장 큰 수 확인
        for (int j=idx+1; j<=k+i; j++){
            if (max < number[j]){
                idx = j;
                max = number[j];
            }
        }
        //str 추가
        answer+=max;
    }
    return answer;
}

//ref: https://mungto.tistory.com/45
//https://programmers.co.kr/learn/courses/30/lessons/42883
