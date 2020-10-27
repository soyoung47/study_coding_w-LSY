//https://programmers.co.kr/learn/courses/30/lessons/43162

#include <vector>
using namespace std;

//분리된 네트워크 갯수 찾기
bool dfs(vector<vector<int>>& computers, int n) {
    //이미 순회했으면 패스
    if (!computers[n][n])    return false;
    //연결 안된것으로 설정
    computers[n][n] = 0;
    //모든 노드 체크
    for (int i = 0; i < computers.size(); i++) {
        //연결 1이면 dfs 체크
        if (computers[n][i])    dfs(computers, i);
    }
    return true;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; i++) {
        //연결된 컴퓨터 있고 모두 순회하면 ++
        if (computers[i][i] && dfs(computers, i))        answer++;
    }
    return answer;
}

//https://mungto.tistory.com/52?category=734741
