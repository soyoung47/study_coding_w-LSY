//[programmers.co.kr] - 코딩테스트 연습 - 2018 KAKAO BLIND RECRUITMENT - 파일명정렬
//https://programmers.co.kr/learn/courses/30/lessons/17686

#include <string>
#include <vector>
#include <algorithm> //stable_sort
#include <math.h> //pow
using namespace std;

//head, Numb, Tail
typedef struct fname {
    string head;
    int num;
    int idx;
}fname;

bool comp(fname a, fname b){
    transform(a.head.begin(), a.head.end(), a.head.begin(), ::tolower);
    transform(b.head.begin(), b.head.end(), b.head.begin(), ::tolower);
    
    if (a.head == b.head) return a.num < b.num;
    
    return a.head < b.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<fname> names;
    fname tmp;
    int res;
    
    for (int i=0; i<files.size(); i++){
        for (int j=0; j<files[i].size(); j++){
            if (files[i][j] >= '0' && files[i][j] <= '9'){
                //숫자 앞까지 head값 저장
                tmp.head = files[i].substr(0,j);
                
                vector<int> nums;
                for(int k=j; k<files[i].size(); k++){
                    //숫자 값 저장 (int vector)
                    if (files[i][k] >= '0' && files[i][k] <= '9') nums.push_back(files[i][k]-'0');
                    else break;
                }
                
                res = 0;
                //숫자 값 계산
                for (int k=int(nums.size()-1); k>=0; k--){
                    res += nums[k]*pow(10,nums.size()-1-k);
                }
                tmp.num = res;
                tmp.idx = i;
                names.push_back(tmp);
                break;
            }
        }
    }
    
    //안정정렬을 위한 stable_sort()
    stable_sort(names.begin(), names.end(), comp);
    
    for (int i=0; i<names.size(); i++) answer.push_back(files[names[i].idx]);
        
    return answer;
}

//ref: https://kswims.tistory.com/167
