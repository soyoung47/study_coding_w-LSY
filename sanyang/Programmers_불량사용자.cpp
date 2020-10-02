//코딩테스트 연습-2019 카카오 개발자 겨울 인턴십-불량 사용자
//https://programmers.co.kr/learn/courses/30/lessons/64064

#include <string>
#include <vector>
#include <set>
using namespace std;
set<int> s;
int len;
bool chk[8];

void dfs(vector<string>& u_id, vector<string>& b_id, int i, int num) {
    if (i == len) {
        s.emplace(num);
        return;
    }

    for (int j = 0; j < u_id.size(); j++) {
        int z;
        if (u_id[j].size() != b_id[i].size()) continue;
        if (chk[j] == 1) continue;
        for (z = 0; z < u_id[j].size(); z++) {
            if (b_id[i][z] == '*') continue;
            if (u_id[j][z] != b_id[i][z]) break;
        }
        if (z == u_id[j].size()) {
            chk[j] = 1;
            //bitmask | 사용으로 중복 제거
            dfs(u_id, b_id, i + 1, num | (1 << j));
            chk[j] = 0;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    len = banned_id.size();
    dfs(user_id, banned_id, 0, 0);
    answer = s.size();
    return answer;
}

//ref: https://hwan-shell.tistory.com/158
//풀이 다양: 백트래킹, set, bfs, bitmask 등
