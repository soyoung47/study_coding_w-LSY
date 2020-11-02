#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

bool *primeArr;

// 에라토스테네스의 체
void Eratos(int num)
{
    //소수판별 배열 할당
    primeArr = new bool[num+1];
    
    //0과 1을 false로 바꿔줘야 예제#2를 통과할 수 있음
    primeArr[0] = false;
    primeArr[1] = false;
    
    //초기화
    for(int i=2; i<=num; i++)
        primeArr[i] = true;
    
    for(int i=2; i*i<=num; i++) {
        //처음 수가 소수인 경우
        if(primeArr[i])
            //배수를 false로 바꿔주기(소수의 배수는 소수X)
            for(int j=i*i; j<=num; j+=i)
                primeArr[j] = false;
    }
    
}

//숫자가 주어진 문자들로 구성 가능한지 판별
bool isIncluded(int num, string str)
{
    //숫자->문자열 변환
    string strNum = to_string(num);
    for(int i=0; i<strNum.size(); i++) {
        int flag = false;
        for(int j=0; j<str.size(); j++) {
            //문자 일치하는 경우
            if(strNum.at(i) == str.at(j)) {
                flag = true;
                //해당 문자를 공백으로 대체 (재사용 불가)
                str.at(j) = ' ';
                break;
            }
        }
        if(!flag) //한번이라도 일치하는 문자가 없는 경우 false 리턴
            return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    
    //내림차순 정렬
    sort(numbers.begin(), numbers.end(), greater<int>());
    //str to int
    int maxNum = stoi(numbers);
    
    //소수판별 배열 생성
    Eratos(maxNum);
    //가장 큰수까지 반복
    for(int i=0; i<=maxNum; i++) {
        //소수인지 && 가진 문자로 만들어지는 숫자인지
        if(primeArr[i] && isIncluded(i, numbers)) {
            answer++;
        }
    }
    return answer;
}

//https://jisun-rea.tistory.com/entry/c-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%99%84%EC%A0%84%ED%83%90%EC%83%89-%EC%86%8C%EC%88%98-%EC%B0%BE%EA%B8%B0
