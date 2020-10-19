//Programmers_정렬_가장큰수

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool standard(string A, string B){
    if (A+B > B+A) return 1;
    return 0;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> arr;
    for (int i=0; i<numbers.size(); i++){
        arr.emplace_back(to_string(numbers[i]));
    }
    sort(arr.begin(), arr.end(), standard);
    for (int i=0; i<arr.size(); i++){
        answer += arr[i];
    }
    //empty
    if(answer[0]=='0') answer = "0";
    return answer;
}

int main(){
    vector<int> numbers = {3,30,34,5,9};
    solution(numbers);
    return 0;
}

//ref: https://yabmoons.tistory.com/330
