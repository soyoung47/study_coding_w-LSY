//[programmers.co.kr] - 코딩테스트 연습 - 2020 KAKAO BLIND RECRUITMENT - 실패율
//https://programmers.co.kr/learn/courses/30/lessons/42889

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(const pair<double, int>& a, const pair<double, int>& b)
{
	//return idx from biggest perc to smallest perc
	//if same, first idx comes first
	if (a.first == b.first) return a.second < b.second;
	else return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages)
{
	vector<int> answer;
	vector<pair<double, int>> failsPerc; //perc of failure, idx

	for (int i = 1; i <= N; i++)
	{
		int stgNum = 0, passNum = 0;
		for (int j = 0; j < stages.size(); j++)
		{
			if (stages[j] >= i) //pass steps
			{
				passNum++;
				if (stages[j] == i) stgNum++;
			}
		}
		if (passNum == 0) //pass X
		{
			////perc = 0
			failsPerc.push_back(pair <double, int> {0, i});
			continue;
		}
		double  failPerc = (double)stgNum / (double)passNum;
		failsPerc.push_back(pair<double, int> {failPerc, i});
	}
	sort(failsPerc.begin(), failsPerc.end(), compare);

	for (int i = 0; i < failsPerc.size(); i++)
		answer.push_back(failsPerc[i].second);

	return answer;
}

//ref: https://jayrightthere.tistory.com/entry/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%8B%A4%ED%8C%A8%EC%9C%A8
