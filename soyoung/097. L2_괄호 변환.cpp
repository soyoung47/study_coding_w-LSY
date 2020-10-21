#include <string>
#include <vector>
#include <stack>
using namespace std;

string solution(string p) {

    //1단계: 입력이 빈문자열이면 빈문자열 반환
    if (p == "")   return "";

    //2단계: u,v로 분리
    string u = "", v = "";
    int balance = 0;
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] == '(')
            balance += 1;
        else
            balance -= 1;

        if (balance == 0)
        {
            int ind = i + 1;
            u = p.substr(0, ind);
            v = p.substr(ind);
            break;
        }
    }

    //3단계: u가 "올바른 괄호 문자열"인가
    stack<int> st;
    bool isCorrect = true;;
    for (int i = 0; i < u.size(); i++)
    {
        if (u[i] == '(') st.push(u[i]);
        else
        {
            if (st.empty())
            {
                isCorrect = false;
                break;
            }
            st.pop();
        }
    }

    //3단계: u가 "올바른 괄호 문자열"이면, v에 대해 1단계 부터 다시 수행하고 수행한 결과를 문자열 u에 이어 붙인 후 반환
    if (isCorrect)   return u + solution(v);
    //4단계: u가 "올바른 괄호 문자열"이 아니면,
    else
    {
        // "(" + v에 대해 1단계 부터 재귀적 수행한 결과 문자열 + ")"
        string str = "(" + solution(v) + ")";

        //u의 첫번째와 마지막 문자 제거, 나머지 문자열의 괄호 방향 뒤집어서 뒤에 붙이고 반환
        string new_u = "";
        for (int i = 1; i < u.size() - 1; i++)
        {
            if (u[i] == '(') new_u += ")";
            else new_u += "(";
        }

        return str + new_u;
    }
}