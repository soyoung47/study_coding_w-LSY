#include<iostream>
#include<vector>
#include<string>
#include<memory.h>
using namespace std;

int p, q;
int master_cnt[10][3];
int my_cnt[10][3];	//�����Ϳ� ���� ������ ��ȣ ����(��,��,���ȣ);
bool check[21][21][21];	//���ɼ��ִ� R,C,S ���� üũ
int dot[10];	//master�� .�� ����
vector<int> ans;
vector<string> master;
vector<string> my;	//�����Ϳ� ���� �ڵ�

void my_calc(int ind)	//�鿩���� ���� ���
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
					
					//���� �������� ������ -1
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
void count_style_my() //my�ڵ��� ��ȣ ���� count
{
	//my�ڵ��� ��ȣ ���� count
	for (int a = 0; a < q; a++)	//���ٸ���
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
		//�������� ��ȣ �������� ����
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
void count_style_master()	//master�ڵ��� ���� ��ȣ ���� count
{
	//master�ڵ��� ���� ��ȣ ���� count
	for (int a = 0; a < p; a++)	//���ٸ���
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
		//�������� ��ȣ �������� ����
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