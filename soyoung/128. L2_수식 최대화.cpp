//https://programmers.co.kr/learn/courses/30/lessons/67257

#include <string>
#include <vector>
using namespace std;

//������ �켱 ����
string op_order[6] = { "+-*", "+*-", "-+*", "-*+", "*-+", "*+-" };

//������ �켱������ ���� ���
long long cal(string order, vector<long long> num, vector<char> op)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < op.size(); j++)
        {
            if (order[i] != op[j])   continue;
            
            if (op[j] == '+')    num[j] += num[j + 1];
            else if (op[j] == '-')    num[j] -= num[j + 1];
            else if (op[j] == '*')  num[j] *= num[j + 1];

            num.erase(num.begin() + j + 1);
            op.erase(op.begin() + j);
            j--;
        }
    }

    return num[0];
}

long long solution(string expression) {
    long long answer = 0;
    vector<long long> num;
    vector<char> op;
        
    //����, ������ �� vector ����
    string str = "";
    for (int i = 0; i < expression.size(); i++)
    {
        if (isdigit(expression[i]))
        {
            str += expression[i];
            if(i == expression.size() -1)
                num.push_back(stoi(str));
        }            
        else
        {
            op.push_back(expression[i]);
            num.push_back(stoll(str));
            str = "";
        }
    }

    //������ �켱������ ���� ���
    for (int i = 0; i < 6; i++)
    {
        long long ans = abs(cal(op_order[i], num, op));
        answer = answer > ans ? answer : ans;
    }   

    return answer;
}