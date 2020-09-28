//[programmers.co.kr] - 코딩테스트 연습 - 2019 카카오 개발자 겨울 인턴십 - 크레인 인형뽑기 게임
//https://programmers.co.kr/learn/courses/30/lessons/64061

#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int size = board.size(); //NxN
    stack<int> s;

    for (auto move : moves) {
        for (int i = 0; i < size; i++) {
            if (board[i][move - 1] != 0) {
                if (!s.empty() && s.top() == board[i][move - 1]) {
                    s.pop();
                    answer += 2;
                }
                else s.push(board[i][move - 1]);
                board[i][move - 1] = 0;
                break;
            }
        }
    }
    return answer;
}

int main() {
    vector<vector<int>> board = { {0,0,0,0,0} ,{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} };
    vector<int> moves = { 1,5,3,5,1,2,1,4 };
    solution(board, moves);
    return 0;
}
