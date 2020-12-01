//https://programmers.co.kr/learn/courses/30/lessons/43236

/***Solution 2***/
#include <algorithm>
#include <vector>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {

    sort(rocks.begin(), rocks.end());

    int size = rocks.size();
    vector<int> dist(size + 1, 0);  //바위들 간의 거리
    
    int last = 0;
    for (int i=0; i<size; i++)
    {
        dist[i] = rocks[i] - last;
        last = rocks[i];
    }
    dist[size] = distance - last;

    int start = 1, end = distance, mid;
    while (start < end)
    {
        mid = (start + end + 1) / 2;

        int cnt = 0, prev = 0;
        for (int d : dist)
        {
            if (mid > d + prev)
            {
                cnt++;
                prev += d;
            }
            else
                prev = 0;
        }

        if (cnt <= n)   start = mid;
        else    end = mid - 1;
    }

    return start;
}

//REF:::https://mind-devlog.tistory.com/47



/***Solution 1***/
#include <algorithm>
#include <vector>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int size = rocks.size();
    sort(rocks.begin(), rocks.end());

    int start = 1, end = distance, mid;

    while (start <= end)
    {
        mid = (start + end) / 2;

        int cnt = 0, ind = -1;  //제거한 바위 개수, 이전에 선택된(제거되지 않은) 바위 index
        for (int i = 0; i <= size; ++i)
        {
            /*  처음 제거하는 바위이면 (거리 = 제거하려는 바위 위치).
                처음 제거하는 바위가 아니면 (거리 = 제거하려는 바위 위치 - 이전에 제거한 바위 위치).
                이때 제거하려는 바위 위치가 마지막이면 (거리 = 도착점 - 마지막 바위 위치)
            */
            int dist = ind == -1 ? rocks[i] : (i == size ? distance - rocks.back() : rocks[i] - rocks[ind]);

            //거리가 mid 보다 작으면 제거하고, 아니면 제거하지 않는다.
            if (dist < mid)  cnt++;
            else    ind = i;    //다음에 선택된 바위와의 거리 계산을 위해 index값 저장
        }

        if (cnt <= n)
        {
            start = mid + 1;
            answer = answer > mid ? answer : mid;
        }
        else    end = mid - 1;
    }

    return answer;
}

//REF:::https://dokrsky.tistory.com/81