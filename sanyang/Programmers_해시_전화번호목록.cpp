//Programmers_해시_전화번호목록

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = 1;
    unordered_map<string, int> map;
    for(auto p:phone_book){
        map[p]=1;
    }
    for(auto p:phone_book){
        //전체 문자열 확인->1있으면 false
        for(int i=1; i<p.size();i++){
            if(map[p.substr(0,i)]==1) answer = false;
        }
    }
    return answer;
}

int main(){
    vector<string> phone_book = {"119", "97674223", "1195524421"};
    solution(phone_book);
    return 0;
}


//ref: https://eocoding.tistory.com/m/8
//TRIE: https://hwan-shell.tistory.com/145
