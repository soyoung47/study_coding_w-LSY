#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int N;
unordered_set<int> cache[10];

unordered_set<int> solve(int n) {
    if (!cache[n].empty()) return cache[n];
    int num = 0;
    //5, 55, 555, ...
    for (int i = 0; i < n; i++) num = 10 * num + N;
    unordered_set<int> res;
    res.insert(num);
    //숫자열의 모든 부분집합을 사칙연산하여 res에 중복없이 추가
    for (int i = 1; i < n; i++) {
        //ex)5555 if i=5 j=555, if i=55 j=55, if i=555 j=5
        int j = n - i;
        auto s1 = solve(i);
        auto s2 = solve(j);
        for (int n1 : s1) {
            for (int n2 : s2) {
                res.insert(n1 + n2);
                res.insert(n1 - n2);
                res.insert(n1 * n2);
                if (n2 != 0) res.insert(n1 / n2);
            }
        }
    }
    //모든 연산가능한 수 cache에 넣음
    return cache[n] = res;
}

int solution(int N, int number) {
    for (int i = 1; i <= 8; i++) {
        solve(i);
        //얻어진 캐시를 작은수부터 정답이 나올 수 있는지 체크
        //적게 사용하여 정답이 나오면 먼저 리턴됨
        if (cache[i].find(number) != cache[i].end()) return i;
    }
    //정답이 안나오는 경우 -1 리턴
    return -1;
}
