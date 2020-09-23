#include <string>
#include <vector>
#include <stack>
using namespace std;

stack<int> basket;
int cnt;
void goBasket(int doll)
{
    if(basket.empty())
        basket.push(doll);
    else
    {
        if(basket.top()==doll)
        {
            basket.pop();
            cnt++;
        }
        else
            basket.push(doll);
    }
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    cnt = 0;
    int n = board.size();
    int m = moves.size();
    
    stack<int> s[31]; //board stack
    
    for(int y=0; y<n; y++)
    {
        for(int x=n-1; x>=0; x--)
        {
            if(board[x][y]!=0)
                s[y].push(board[x][y]);
        }
    }
    
    for(int i=0; i<m; i++)
    {
        int ord = moves[i]-1;
        if(!s[ord].empty())
        {
            int top = s[ord].top();
            goBasket(top);
            s[ord].pop();
        }
    }
    
    answer = cnt * 2;
    
    return answer;
}
