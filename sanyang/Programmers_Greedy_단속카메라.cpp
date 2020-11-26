#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    //오름차순 정렬 (진입지점 기준)
    sort(routes.begin(), routes.end());
    //처음 진입한 차의 나간지점
    int tmp = routes[0][1];
    
    for (auto a : routes) {
        //다음 차가 첫 차가 나간 후 진입하는경우
        if (tmp < a[0]) {
            //카메라 대수 추가
            answer++;
            //다음 차 나간지점 업데이트
            tmp = a[1];
        }
        //다음 차가 먼저 나가는경우 -> 다음 차 나가는지점 업데이트
        if (tmp >= a[1]) tmp = a[1];
    }
    return answer;
}

//ref: https://mungto.tistory.com/49
