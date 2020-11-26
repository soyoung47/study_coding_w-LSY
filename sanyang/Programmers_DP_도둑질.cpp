#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> money) {
    //m1:첫번째 집부터 훔치는 경우, m2:두번째 집부터 훔치는 경우
    vector<int> m1, m2;
    int msize = money.size();
    m1.resize(msize, money[0]);
    m2.resize(msize, money[1]);
    m2[0] = 0;
    
    //현재 도둑질하려는 집의 돈 + (현재-2) 집의 돈 vs (현재-1) 집의 돈 중 큰 값 저장
    for (int i = 2; i <= msize - 2; i++) {
        m1[i] = max(m1[i - 2] + money[i], m1[i - 1]);
    }
    for (int i = 2; i <= msize - 1; i++) {
        m2[i] = max(m2[i - 2] + money[i], m2[i - 1]);
    }
    return max(m1[msize - 2], m2[msize - 1]);
}

//ref: https://greenapple16.tistory.com/53
