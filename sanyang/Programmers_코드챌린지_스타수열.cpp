#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int Max(int A, int B){return A>B? A:B;}

int solution(std::vector<int> a) {
    int answer = -1;
    //#each nums
    vector<int> Cnt(a.size()+1, 0);
    //cnt nums
    for (int i=0; i<a.size(); i++) Cnt[a[i]]++;
    for (int i=0; i<Cnt.size(); i++){
        //해당 숫자 존재x
        if (Cnt[i]==0) continue;
        //이전 최대카운트 숫자보다 작은경우(어차피 최대 불가)
        if (Cnt[i]<=answer) continue;
        int Result = 0;

        for (int j=0; j<a.size()-1; j++){
            //중복확인
            if (a[j]!=i && a[j+1]!=i) continue;
            if (a[j]==a[j+1]) continue;
            Result++;
            j++;
        }
        //가장 긴 길이
        answer = Max(answer,Result);
    }
    return answer*2;
}


//ref: https://yabmoons.tistory.com/610
