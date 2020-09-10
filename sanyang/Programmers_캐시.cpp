//[programmers.co.kr] - 코딩테스트 연습 - 2018 KAKAO BLIND RECRUITMENT - 캐시
//https://programmers.co.kr/learn/courses/30/lessons/17680

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// LRU: (works like queue)
// FIFO
// if Cache==full, first data out, new data in
// newly used data comes last (update)

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;

    if (cacheSize == 0) return cities.size() * 5;

    for (int i = 0; i < cities.size(); i++) {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        auto itr = find(cache.begin(), cache.end(), cities[i]);

        //cache miss
        if (itr == cache.end()) {
            if (cache.size() == cacheSize) cache.erase(cache.begin());
            answer += 5;
        }
        else { //cache hit
            answer++;
            cache.erase(itr);
        }
        cache.push_back(cities[i]);
    }
    return answer;
}

//ref: https://eunchanee.tistory.com/77
