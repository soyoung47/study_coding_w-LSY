#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    //최소시간, 최대시간의 평균시간동안 얼마나 많은 심사 처리하는지
    long long answer = 0, minTime, maxTime, avgTime, human = 0;
    sort(times.begin(), times.end());
    minTime = (long long) times[0];
    //최대시간: 오래걸리는 처리시간 * 명수
    maxTime = (long long)times[times.size()-1] * (long long)n;
    while (minTime <= maxTime) {
        //평균시간 계산
        avgTime = ((maxTime + minTime) / 2);
        //현재 평균시간으로 최대 처리인원수 계산
        for (auto t : times)        human += avgTime / t;
        //처리인원수가 주어진 수보다 크거나 같으면
        //더 빨리 처리할 수 있으므로 최대시간 갱신
        if (n <= human) {
            //현재시간 갱신
            answer = avgTime;
            //최대시간 기준을 평균값보다 1작게 재설정
            maxTime = avgTime - 1;
        }
        //처리인원수가 주어진 수보다 작으면
        //인원을 다 처리못했으므로 최소시간 갱신
        else    minTime = avgTime + 1;
        //처리인원수 초기화
        human = 0;
    }
    return answer;
}

//ref: https://mungto.tistory.com/56
