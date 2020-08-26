#include <string>
#include <vector>
#include <stack>
using namespace std;

string solution(string p) {

    //1�ܰ�: �Է��� ���ڿ��̸� ���ڿ� ��ȯ
    if (p == "")   return "";

    //2�ܰ�: u,v�� �и�
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

    //3�ܰ�: u�� "�ùٸ� ��ȣ ���ڿ�"�ΰ�
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

    //3�ܰ�: u�� "�ùٸ� ��ȣ ���ڿ�"�̸�, v�� ���� 1�ܰ� ���� �ٽ� �����ϰ� ������ ����� ���ڿ� u�� �̾� ���� �� ��ȯ
    if (isCorrect)   return u + solution(v);
    //4�ܰ�: u�� "�ùٸ� ��ȣ ���ڿ�"�� �ƴϸ�,
    else
    {
        // "(" + v�� ���� 1�ܰ� ���� ����� ������ ��� ���ڿ� + ")"
        string str = "(" + solution(v) + ")";

        //u�� ù��°�� ������ ���� ����, ������ ���ڿ��� ��ȣ ���� ����� �ڿ� ���̰� ��ȯ
        string new_u = "";
        for (int i = 1; i < u.size() - 1; i++)
        {
            if (u[i] == '(') new_u += ")";
            else new_u += "(";
        }

        return str + new_u;
    }
}