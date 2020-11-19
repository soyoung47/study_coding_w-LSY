#include <string>

using namespace std;

int solution(string name) {
    int answer = 0;
    int idx = 0;
    //name 길이만큼 A문자로 초기화
    string init(name.length(), 'A');
    while (1){
        init[idx] = name[idx];
        //A, Z 중 어느 문자에 가까운지 -> 카운트 증가
        name[idx] - 'A' > 'Z' + 1 - name[idx]?
        //answer 카운트 추가1: 문자 변형
        answer += 'Z' + 1 - name[idx] : answer += name[idx] - 'A';
        //정답 완성 -> 종료
        if (init==name) break;
        //다음 변경할 문자 선택(좌/우) 가까운쪽부터
        for (int mv=1; mv<name.length(); mv++){
            //%name.length(): circular
            //오른쪽 이동 (idx+mv: 123...)
            if (name[(idx+mv)%name.length()] != init[(idx+mv)%name.length()]){
                idx=(idx+mv)%name.length();
                //answer 카운트 추가2-1: 오른쪽 이동횟수
                answer+=mv;
                break;
            }
            //왼쪽 이동 (idx-mv: ...321)
            else if (name[(idx+name.length()-mv)%name.length()]
                     != init[(idx+name.length()-mv)%name.length()]){
                idx = (idx+name.length()-mv)%name.length();
                //answer 카운트 추가2-2: 왼쪽 이동횟수
                answer+=mv;
                break;
            }
        }
    }
    return answer;
}

//https://mungto.tistory.com/44
