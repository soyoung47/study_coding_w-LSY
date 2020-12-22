/*
 수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

 예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.
 */

#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N, tmp;
    vector<int> v;
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        scanf("%d", &tmp);
        //v가 비어있거나, 마지막 값보다 현재 값이 크면 -> v에 현재 값 추가
        if (v.empty() || v.back() < tmp) v.push_back(tmp);
        else {
            //v가 비어있지 않고, 마지막 값이 현재 값보다 작거나 같으면
            //v에서 현재 값의 lower bound 위치 구해 현재 값으로 대체
            auto iter = lower_bound(v.begin(), v.end(), tmp);
            *iter = tmp;
        }
    }
    printf("%d", int(v.size()));
    return 0;
}

//ref: https://ferrante.tistory.com/54
