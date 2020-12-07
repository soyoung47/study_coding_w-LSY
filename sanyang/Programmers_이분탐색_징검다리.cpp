#include <vector>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int cnt = 0;
    rocks.emplace_back(0);
    sort(rocks.begin(), rocks.end());
    int low = rocks[0];
    int high = distance;
    int mid;
    int val = 0;
    while (low != high){
        //중간값 계산
        mid = (low+high+1) / 2;
        cnt = 0;
        //바위갯수만큼 반복
        for (int i = 0; i < rocks.size() - 1; i++){
            //바위사이 거리 계산
            val = rocks[i + 1] - rocks[i];
            중간값보다 바위 간 거리 작으면 바위 지우기
            while (cnt < n && val < mid && i < rocks.size() - 2){
                i++;
                val += rocks[i + 1] - rocks[i];
                cnt++;
            }
            //바위사이 거리 합이 중간값보다 작으면 바위제거
            if (val < mid){
                cnt = n + 1;
                break;
            }
        }
        //바위 너무 많이 제거한경우 최대값 갱신
        if (cnt > n){
            high = mid - 1;
        }
        //바위 더 제거할 수 있는경우 최저값 갱신
        else{
            low = mid;
        }
    }

    return low;
}

//ref: https://programmers.co.kr/learn/courses/30/lessons/43236/solution_groups?language=cpp
