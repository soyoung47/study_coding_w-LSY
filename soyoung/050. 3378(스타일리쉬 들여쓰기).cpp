#include<iostream>
#include<vector>
#include<string>
#include<memory.h>
using namespace std;

int p, q;
int master_cnt[10][3];
int my_cnt[10][3];	//마스터와 나의 각줄의 괄호 개수(소,중,대괄호);
bool check[21][21][21];	//가능성있는 R,C,S 조합 체크
int dot[10];	//master의 .점 개수
vector<int> ans;
vector<string> master;
vector<string> my;	//마스터와 나의 코드

void my_calc(int ind)	//들여쓰기 개수 계산
{
	int temp = 0;
	int answer = -1;
	int cnt = 0; 
	for (int r = 1; r < 21; r++)
	{
		for (int c = 1; c < 21; c++)
		{
			for (int s = 1; s < 21; s++)
			{
				if (check[r][c][s])
				{
					cnt++;
					answer = r * my_cnt[ind-1][0] + c * my_cnt[ind-1][1] + s * my_cnt[ind-1][2];
					
					//답이 유일하지 않으면 -1
					if (cnt == 1)
						temp = answer;
					else
					{
						if (answer != temp)
							answer = -1;
					}
				}
			}
		}
	}
	ans.push_back(answer);
}
void count_style_my() //my코드의 괄호 개수 count
{
	//my코드의 괄호 개수 count
	for (int a = 0; a < q; a++)	//각줄마다
	{
		for (int b = 0; b < my[a].size(); b++)
		{
			if (my[a][b] == '(')	my_cnt[a][0]++;
			else if (my[a][b] == ')')	my_cnt[a][0]--;
			else if (my[a][b] == '{')	my_cnt[a][1]++;
			else if (my[a][b] == '}')	my_cnt[a][1]--;
			else if (my[a][b] == '[')	my_cnt[a][2]++;
			else if (my[a][b] == ']')	my_cnt[a][2]--;
		}
		//이전줄의 괄호 개수까지 누적
		if (a != 0)
		{
			my_calc(a);
			my_cnt[a][0] += my_cnt[a - 1][0];
			my_cnt[a][1] += my_cnt[a - 1][1];
			my_cnt[a][2] += my_cnt[a - 1][2];
		}
	}
}
void check_stylish(int ind)
{
	for (int r = 1; r < 21; r++)
	{
		for (int c = 1; c < 21; c++)
		{
			for (int s = 1; s < 21; s++)
			{
				if (r * master_cnt[ind-1][0] + c * master_cnt[ind-1][1] + s * master_cnt[ind-1][2] != dot[ind])
					check[r][c][s] = false;
			}
		}
	}
}
void count_style_master()	//master코드의 점과 괄호 개수 count
{
	//master코드의 점과 괄호 개수 count
	for (int a = 0; a < p; a++)	//각줄마다
	{
		bool middleDot = false;
		for (int b = 0; b < master[a].size(); b++)
		{
			if (!middleDot && master[a][b] == '.')
				dot[a]++;
			else
			{
				middleDot = true;
				if (master[a][b] == '(')	master_cnt[a][0]++;
				else if (master[a][b] == ')')	master_cnt[a][0]--;
				else if (master[a][b] == '{')	master_cnt[a][1]++;
				else if (master[a][b] == '}')	master_cnt[a][1]--;
				else if (master[a][b] == '[')	master_cnt[a][2]++;
				else if (master[a][b] == ']')	master_cnt[a][2]--;
			}
		}
		//이전줄의 괄호 개수까지 누적
		if (a != 0)
		{
			check_stylish(a);
			master_cnt[a][0] += master_cnt[a - 1][0];
			master_cnt[a][1] += master_cnt[a - 1][1];
			master_cnt[a][2] += master_cnt[a - 1][2];
		}		
	}
}
void Init()
{
	memset(master_cnt, 0, sizeof(master_cnt));
	memset(my_cnt, 0, sizeof(my_cnt));
	memset(check, true, sizeof(check));
	memset(dot, 0, sizeof(dot));
	master.clear();
	my.clear();
	ans.clear();
	ans.push_back(0);
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		Init();

		cin >> p >> q;

		string str;
		for (int i = 0; i < p; i++)
		{
			cin >> str;
			master.push_back(str);
		}

		for (int j = 0; j < q; j++)
		{
			cin >> str;
			my.push_back(str);
		}

		count_style_master();
		count_style_my();

		cout << "#" << test_case<<" ";
		for (int k = 0; k < ans.size(); k++)
			cout << ans[k] << " ";
		cout << "\n";
	}
	return 0;
}