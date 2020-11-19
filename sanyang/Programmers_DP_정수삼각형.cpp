#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    //층수만큼 반복
    for (int i=1; i<triangle.size(); i++){
        //층의 숫자 수만큼 반복
        for (int j=0; j<triangle[i].size(); j++){
            //맨 앞, 맨 뒤 숫자가 아닌경우
            if (j!=0 && j<triangle[i-1].size())
                //좌우 숫자중 큰 수 선택
                triangle[i][j] += max(triangle[i-1][j], triangle[i-1][j-1]);
            //맨 앞 숫자인 경우
            else if(j==0)
                triangle[i][j] += triangle[i-1][j];
            //맨 뒤 숫자인 경우
            else
                triangle[i][j] += triangle[i-1][j-1];
            //나온 합 중 가장 큰 수 선택
            answer = max(answer, triangle[i][j]);
        }
    }
    return answer;
}

//https://hwan-shell.tistory.com/221
