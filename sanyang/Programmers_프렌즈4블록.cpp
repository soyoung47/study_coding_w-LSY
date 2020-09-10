//[programmers.co.kr] - 코딩테스트 연습 - 2019 KAKAO BLIND RECRUITMENT - 프렌즈4블록
//https://programmers.co.kr/learn/courses/30/lessons/

#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool stop = 0;
    while (stop == 0) {
        vector<vector<bool>> visit(m, vector<bool>(n)); // m*n
        stop = 1;
        //check 4 blocks
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (board[i][j] == 0) continue;
                if ((board[i][j] == board[i][j + 1]) && (board[i][j] == board[i + 1][j])
                    && (board[i][j] == board[i + 1][j + 1])) {
                    visit[i][j] = 1;
                    visit[i][j + 1] = 1;
                    visit[i + 1][j] = 1;
                    visit[i + 1][j + 1] = 1;
                    stop = 0;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visit[i][j] == 1) {
                    answer++;
                    for (int k = i - 1; k >= 0; k--) {
                        board[k + 1][j] = board[k][j];
                        board[k][j] = 0;
                    }
                }
            }
        }
    }

    return answer;
}

//ref: https://chaibin0.tistory.com/entry/%ED%94%84%EB%A0%8C%EC%A6%884%EB%B8%94%EB%A1%9D
