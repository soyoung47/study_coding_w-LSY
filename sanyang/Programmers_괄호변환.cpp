//[programmers.co.kr] - 코딩테스트 연습 - 2020 KAKAO BLIND RECRUITMENT - 괄호 변환
//https://programmers.co.kr/learn/courses/30/lessons/60063

#include <string>
#include <vector>
using namespace std;
#include <stack>

string solution(string p)
{
	if (p.empty()) return p;
	// p != empty
	//check whether it's all paired
	string u = "", v = "", tmp = "";
	int numL = 0, numR = 0;
	// w = u + v
	for (auto iter : p)
	{
		if (u == "")
		{
			(iter == ')') ? numR++ : numL++;
			tmp += iter;

			if (numR == numL) u = tmp;
		}
		else v += iter;
	}

	//check balance
	stack<int> s;
	bool chk = 1;
	for (auto iter : u)
	{	
		if (iter == '(') s.push(1);
		else
		{
			if (s.empty())
			{
				chk = 0;
				break;
			}
			else s.pop();
		}
	}

	if (!s.empty()) chk = 0;
	if (chk == 0)
	{
		u.erase(u.begin());
		u.pop_back();
		for (auto &iter : u)
		{
			iter = (iter == '(') ? ')' : '(';
		}
		return '(' + solution(v) + ')' + u;
	}
	return u + solution(v);
}
