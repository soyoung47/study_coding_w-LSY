#include <string>
#include <vector>
#include <string>
#include <set>
using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> ms;
    for(auto o:operations){
        //첫번째 글자(operation), 두번째 글자(숫자) 추출
        string a = o.substr(0,1);
        int num = atoi(o.substr(2).c_str()); //c_str() 주의
        //insert면 숫자 삽입
        if (a == "I") ms.insert(num);
        //delete이고, 비어있지 않으면
        else if (!ms.empty()){
            //최댓값 삭제(맨 뒤 바로 앞에 값 삭제)
            if (num == 1) ms.erase(--ms.end());
            //최솟값 삭제(맨 앞 값)
            else ms.erase(ms.begin());
        }
    }
    //명령어 처리 후 비어있으면 0,0 반환
    if (ms.empty()) return {0,0};
    //비어있지 않으면 최댓값, 최솟값 반환
    else return {*--ms.end(), *ms.begin()};
}

//https://programmers.co.kr/learn/courses/30/lessons/42628
//multiset: deque와 달리 들어오는 값 실시간 정렬 (중복 허용)
//ref: https://mungto.tistory.com/17
//erase() params: iterator position, val, first-last
//begin(), end(): return iterator
