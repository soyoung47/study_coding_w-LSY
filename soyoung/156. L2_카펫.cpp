//https://programmers.co.kr/learn/courses/30/lessons/42842

#include <vector>
#include <math.h>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    for (int h = 1; h <= sqrt(yellow); h++)
    {
        if (yellow % h != 0)  continue;
        
        int w = yellow / h;
        if (w * 2 + h * 2 + 4 == brown)
        {
            answer = { w + 2, h + 2 };
            break;
        }
    }

    return answer;
} 