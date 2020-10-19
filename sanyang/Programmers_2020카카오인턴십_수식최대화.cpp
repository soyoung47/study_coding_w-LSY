//Programmers_2020카카오인턴십_수식최대화

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector<long long> num;
    vector<char> exp, location;
    string n="";
    
    for(int i=0; i<expression.size(); i++){
        if(expression[i]=='+' || expression[i]=='-' || expression[i]=='*'){
            num.emplace_back(stoi(n));
            n="";
            if(find(exp.begin(), exp.end(), expression[i]) == exp.end())
                exp.emplace_back(expression[i]);
            location.emplace_back(expression[i]);
        }
        else n+=expression[i];
    }
    num.emplace_back(stoi(n));
    sort(exp.begin(), exp.end());
    
    do
    {
        vector<long long> tmpNum = num;
        vector<char> tmpLoc = location;
        
        for(int i=0; i<exp.size(); i++){
            for(int j=0; j<tmpLoc.size(); j++){
                if(exp[i]==tmpLoc[j]){
                    if(tmpLoc[j]=='+') tmpNum[j]+=tmpNum[j+1];
                    else if(tmpLoc[j]=='-') tmpNum[j]-=tmpNum[j+1];
                    else if(tmpLoc[j]=='*') tmpNum[j]*=tmpNum[j+1];
                    tmpNum.erase(tmpNum.begin()+j+1);
                    tmpLoc.erase(tmpLoc.begin()+j);
                    j--;
                }
            }
        }
        if(answer < abs(tmpNum[0])) answer = abs(tmpNum[0]);
    } while (next_permutation(exp.begin(), exp.end()));
    return answer;
}

//ref: https://eunchanee.tistory.com/88
