//Programmers_2020카카오인턴십_키패드누르기

#include <string>
#include <vector>
#include <cmath>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int lHand = 10, rHand = 12, lDist = 0, rDist = 0;

    for(int i=0; i<numbers.size(); i++){
        if(numbers[i]==1 || numbers[i]==4 || numbers[i]==7){
            answer += "L";
            lHand = numbers[i];
        }
        else if(numbers[i]==3 || numbers[i]==6 || numbers[i]==9){
            answer += "R";
            rHand = numbers[i];
        }
        else{
            //2580
            if(numbers[i]==0) numbers[i]=11;
            //현재 손가락 위치와 숫자와의 거리
            int tmpL = abs(lHand - numbers[i]);
            int tmpR = abs(rHand - numbers[i]);
            //거리 계산
            lDist = (tmpL/3)+(tmpL%3);
            rDist = (tmpR/3)+(tmpR%3);

            if(lDist==rDist){
                if(hand == "right"){
                    answer += "R";
                    rHand = numbers[i];
                }
                else{
                    answer += "L";
                    lHand = numbers[i];
                }
            }
            else if(lDist<rDist){
                answer += "L";
                lHand = numbers[i];
            }
            else{
                answer += "R";
                rHand = numbers[i];
            }
        }
    }
    return answer;
}

//ref: https://eunchanee.tistory.com/89
