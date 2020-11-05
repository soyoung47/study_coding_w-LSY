#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    //min heap (scoville 각각 넣어주지않아도 정렬)
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    //2개이상 남았고 최소값이 K보다 작은동안 (아직 덜매움)
    while (pq.size()>=2 && pq.top()<K){
        //최소값 두개 섞어서 값 삽입
        int food1 = pq.top();
        pq.pop();
        int food2 = pq.top();
        pq.pop();
        pq.push(food1 + 2*food2);
        answer++;
    }
    if (pq.top()<K) return -1;
    return answer;
}

//https://programmers.co.kr/learn/courses/30/lessons/42626
//heap(최대, 최소값 빠르게 찾기 위한 완전이진트리)
//max heap(큰값부터 정렬), min heap(작은값부터 정렬)
//https://mungto.tistory.com/8
