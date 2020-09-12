#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while (true)
    {
        vector<vector<bool>> check(m, vector<bool>(n, false));
        bool reset = false;
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                char c = board[i][j];
                if (c != '0' && c == board[i + 1][j] && c == board[i][j + 1] && c == board[i + 1][j + 1])
                {
                    check[i][j] = check[i + 1][j] = check[i][j + 1] = check[i + 1][j + 1] = true;
                    reset = true;
                }                    
            }
        }

        if (!reset)   break;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (check[i][j])
                {
                    answer++;
                    board[i][j] = '0';
                }
            }
        }

        for (int j = 0; j < n; j++)
        {
            queue<char> ch;
            for (int i = m - 1; i >= 0; i--)
            {
                if (board[i][j] != '0')
                    ch.push(board[i][j]);
            }

            for (int i = m - 1; i >= 0; i--)
            {
                if (!ch.empty())
                {
                    board[i][j] = ch.front();
                    ch.pop();
                }
                else
                    board[i][j] = '0';

            }
        }
    }

    return answer;
}

int main()
{
    int a = solution(4, 5, { "CCBDE", "AAADE", "AAABF", "CCBBF" });
}