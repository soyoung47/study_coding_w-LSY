//https://programmers.co.kr/learn/courses/30/lessons/49190

#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> arrows) {
    int answer = 0;
    int size = arrows.size();

    //변 3개 이상 = 방
    if (size < 3)    return answer;

    //이동 방향
    int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
    int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

    //이동 및 방의 개수 파악
    map<pair<int, int>, int> point; //통과한 좌표(int,int), 각 좌표의 통과 횟수
    map<pair<pair<int, int>, pair<int, int>>, int> line; //선분(좌표1, 좌표2), 선분의 유무
    pair<int, int> p = { 0,0 }; //첫 시작점 좌표
    point[p] = 1;

    for (int move : arrows)
    {   
        //                          * - * - *
        //  * - *                     ＼ ／
        //    X      와 같은 경우   *   *   *    로 생각하여 중간 교차점의 좌표도 체크할 수 있도록 2번씩 진행
        //  * - *                     ／  ＼
        //                          * - * - *
        for (int i = 0; i < 2; i++)
        {
            //이동
            pair<int, int> np = { p.first + dx[move],  p.second + dy[move] };

            //이미 통과한 선분이라면 pass
            if (line.count({ p, np }) > 0)
            {
                p = np;
                continue;
            }

            //이미 통과한 선분이 아니라면,

            //1. 통과 좌표 저장 + 횟수 추가, 선분 저장
            point[np]++;
            line[{ p, np }]++;
            line[{ np, p }]++;

            //2. 통과 횟수 == 2 : 방 1개, 횟수 초기화
            if (point[np] == 2)
            {
                answer++;
                point[np] = 1;
            }

            p = np;
        }        
    }

    return answer;
}