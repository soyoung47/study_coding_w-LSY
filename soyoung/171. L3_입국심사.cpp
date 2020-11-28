//https://programmers.co.kr/learn/courses/30/lessons/43238

#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {

    //시간 오름차순 정렬
    sort(times.begin(), times.end());

    long long min = 1;
    long long max = (long long)times.back() * n;
    long long answer = max;

    //소요되는 시간을 기준으로 이분 탐색
    while (min <= max)
    {
        long long mid = (min + max) / 2;
        long long cnt = 0;  //소요시간(mid) 동안 심사한 사람 수

        //소요시간(mid) 동안 심사할 수 있는 사람 수 체크
        for (int t : times)
            cnt += mid / t;

        //소요시간(mid) 동안 n명의 사람 심사하지 못한 경우
        if (cnt < n)    min = mid + 1;
        //소요시간(mid) 동안 n명의 사람 심사한 경우
        else
        {
            max = mid - 1;
            answer = answer < mid ? answer : mid;
        }
    }

    return answer;
}

//REF:::https://blog.naver.com/cocokelly1229/222078992832