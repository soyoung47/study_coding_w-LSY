/*
 https://www.acmicpc.net/problem/1920

 N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성
 모든 정수범위: -2^31 ~ 2^31
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    vector<int> nums, targets;
    //int nums[100001], targets[100001];
    int tmpN, min, max, avg;
    //#N
    cin >> N;
    //A[1], A[2], ..., A[N]
    for (int i=0; i<N; i++){
        cin >> tmpN;
        nums.emplace_back(tmpN);
    }
    //#M
    cin >> M;
    //targets
    for (int i=0; i<M; i++){
        cin >> tmpN;
        targets.emplace_back(tmpN);
    }

    //데이터 정렬
    sort(nums.begin(), nums.end());
    //binary search

    for (auto t: targets){
        int answer = -1;
        min = 0;
        max = N-1;
        while(min<=max){
            avg = (min+max+1)/2;
            if (t==nums[avg]){
                answer = 1;
                break;
            }
            else if (t<nums[avg])   max = avg-1;
            else if (t>nums[avg])   min = avg+1;
        }
        if (answer == -1) answer = 0;
        cout << answer << '\n';
    }
}
