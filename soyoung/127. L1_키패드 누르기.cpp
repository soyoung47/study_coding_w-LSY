#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<int> numbers, string hand) {
	string answer = "";

	map<int, pair<int, int>> key;

	int k = 0;
	for (int a = 0; a < 3; a++)
	{
		for (int b = 0; b < 3; b++)
		{
			k++;
			key[k] = make_pair(a, b);
		}
	}

	key[-1] = make_pair(3, 0);	//*
	key[0] = make_pair(3, 1);
	key[-2] = make_pair(3, 2);	//#

	pair<int, int> cur[2];
	cur[0] = make_pair(3, 0);	//왼손
	cur[1] = make_pair(3, 2);	//오른손

	for (int v = 0; v < numbers.size(); v++)
	{
		if (numbers[v] % 3 == 1)
		{
			answer += "L";
			cur[0] = key[numbers[v]];
		}
		else if ((numbers[v] % 3 == 0) && numbers[v] != 0)
		{
			answer += "R";
			cur[1] = key[numbers[v]];
		}
		else
		{
			//거리계산
			int dist_L = abs(cur[0].first - key[numbers[v]].first) + abs(cur[0].second - key[numbers[v]].second);
			int dist_R = abs(cur[1].first - key[numbers[v]].first) + abs(cur[1].second - key[numbers[v]].second);

			if (dist_L == dist_R)
			{
				if (hand == "right")
				{
					answer += "R";
					cur[1] = key[numbers[v]];
				}
				else
				{
					answer += "L";
					cur[0] = key[numbers[v]];
				}
			}
			else if (dist_L > dist_R)
			{
				answer += "R";
				cur[1] = key[numbers[v]];
			}
			else
			{
				answer += "L";
				cur[0] = key[numbers[v]];
			}
		}
	}

	return answer;
}