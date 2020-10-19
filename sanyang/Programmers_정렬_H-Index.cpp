//Programmers_정렬_H-Index

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    //descending sort
    sort(citations.begin(), citations.end(), greater<int>());
    if (!citations[0]) return 0;
    for(int i=0; i<citations.size(); i++){
        if(citations[i]>i) answer++;
        else break;
    }
    return answer++;
}

//ref: https://mungto.tistory.com/27
