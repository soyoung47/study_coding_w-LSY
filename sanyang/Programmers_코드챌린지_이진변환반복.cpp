#include <string>
#include <vector>
#include <bitset>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2,0); // {#transform, #removed0}
    int cntZero = 0, len = s.size();
    while(s!="1"){
        answer[0]++;
        cntZero=0;
        for (int i=0; i<s.size(); i++){
            if (s[i]=='0'){
                cntZero++;
            }
        }
        int newSize = s.size()-cntZero;

        answer[1]+=cntZero;

        //update s
        s.clear();
        //int(num) to bin
        while (newSize>0){
            s+=((newSize%2)+'0');
            newSize/=2;
        }
        //reverse
        string tmp="";
        for (int i=s.length()-1; i>=0; i--) tmp+=s[i];
        s=tmp;
    }
    return answer;
}

