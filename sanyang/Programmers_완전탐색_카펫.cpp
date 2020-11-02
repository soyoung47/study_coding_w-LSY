#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    //전체 타일수
    int sum = brown + yellow;
    //3부터 하나하나 늘려가며 조건 탐색 (멈추는 조건이 없어도 가능)
    for (int height = 3; ; height++) {
        //높이로 나눠 떨어지는지 확인
        if (!(sum % height)) {
            int weight = sum / height;
            //사이드 빼고 갯수 맞는지 계산
            if (((height - 2) * (weight - 2)) == yellow) {
                answer.push_back(weight);
                answer.push_back(height);
                break;
            }
        }
    }
    return answer;
}

//https://mungto.tistory.com/43
