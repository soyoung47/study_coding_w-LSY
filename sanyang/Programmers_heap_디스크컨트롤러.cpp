#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct cmp{
    bool operator()(vector<int> a, vector<int> b){
        return a.at(1)>b.at(1);
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0, j=0, time=0;
    //오름차순 정렬
    sort(jobs.begin(), jobs.end());
    //min heap
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    //마지막 일까지 반복
    while(j<jobs.size() || !pq.empty()){
        //대기열 남아있고 && 대기열이 현재시간보다 작음
        if(jobs.size()>j && time>=jobs[j][0]){
            pq.push(jobs[j++]);
            continue;
        }
        //큐가 비어있지 않으면
        if(!pq.empty()){
            //현재 작업 끝날때까지 딜레이
            time+=pq.top()[1];
            //작업시간+대기시간
            answer+=time-pq.top()[0];
            pq.pop();
        }
        //다음 작업 처리
        else time=jobs[j][0];
    }
    //평균 계산
    return answer / jobs.size();
}

//https://programmers.co.kr/learn/courses/30/lessons/42627
//https://mungto.tistory.com/15?category=734741
