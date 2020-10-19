//Programmers_코드챌린지_3진법뒤집기

//3진법 변환
//앞뒤 반전
//10진법 변환

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(int n){
    int answer = 0;
    vector<int> v;

    while(n){
        v.emplace_back(n%3);
        n/=3;
    }
    reverse(v.begin(), v.end());
    for(int i=0; i<v.size(); i++) answer += pow(3,i)*v[i];

    return answer;
}

int main(){
    int n = 45;
    solution(n);
    return 0;
}

//ref: https://eunchanee.tistory.com/143
