//#3378. SW스타일리쉬 들여쓰기
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#define endl "\n"
#define MAX 10 //#line of P, Q
using namespace std;
int P, Q;
int P_Arr[MAX][3];
int Q_Arr[MAX][3];
int Dots[MAX]; //How many dots?
bool Prob[21][21][21]; //All Combinations
string P_Str[MAX], Q_Str[MAX];
vector<int> Ans;

void Init()
{
	memset(Dots, 0, sizeof(Dots));
	memset(P_Arr, 0, sizeof(P_Arr));
	memset(Q_Arr, 0, sizeof(Q_Arr));

	for (int i = 0; i < MAX; i++)
	{
		P_Str[i].clear();
		Q_Str[i].clear();
	}

	Ans.clear();

	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			for (int k = 0; k < 21; k++) Prob[i][j][k] = true;
		}
	}

	//000-02121, 000-21021, 000-21210
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 21; j++) Prob[0][i][j] = Prob[i][0][j] = Prob[i][j][0] = false;
	}
}

void Input()
{
	cin >> P >> Q;
	for (int i = 0; i < P; i++)
	{
		string Input;
		cin >> Input;
		P_Str[i] = Input;
	}
	for (int i = 0; i < Q; i++)
	{
		string Input;
		cin >> Input;
		Q_Str[i] = Input;
	}
}

void Count(char C) //Count Dots & Brackets
{
	if (C == 'P')
	{
		for (int i = 0; i < P; i++)
		{
			bool Middle_Dot = false;
			for (int j = 0; j < P_Str[i].length(); j++)
			{
				if (P_Str[i][j] == '.')
				{
					if (Middle_Dot == false) Dots[i]++;
				}
				else
				{
					Middle_Dot = true;
					if (P_Str[i][j] == '(') P_Arr[i][0]++;
					else if (P_Str[i][j] == ')') P_Arr[i][0]--;
					else if (P_Str[i][j] == '{') P_Arr[i][1]++;
					else if (P_Str[i][j] == '}') P_Arr[i][1]--;
					else if (P_Str[i][j] == '[') P_Arr[i][2]++;
					else if (P_Str[i][j] == ']') P_Arr[i][2]--;
				}
			}
		}
	}
	else if (C == 'Q')
	{
		for (int i = 0; i < Q; i++)
		{
			for (int j = 0; j < Q_Str[i].length(); j++)
			{
				if (Q_Str[i][j] == '(') Q_Arr[i][0]++;
				else if (Q_Str[i][j] == ')') Q_Arr[i][0]--;
				else if (Q_Str[i][j] == '{') Q_Arr[i][1]++;
				else if (Q_Str[i][j] == '}') Q_Arr[i][1]--;
				else if (Q_Str[i][j] == '[') Q_Arr[i][2]++;
				else if (Q_Str[i][j] == ']') Q_Arr[i][2]--;
			}
		}
	}
}

void Check_Value(int S, int M, int L, int Idx)
{
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			for (int k = 0; k < 21; k++)
			{
				if (Prob[i][j][k] == false) continue;
				if ((i * S + j * M + k * L) != Dots[Idx]) Prob[i][j][k] = false;
			}
		}
	}
}

void Find_Answer(int S, int M, int L)
{
	int Count = 0, Value = 0;
	int Temp_Result = -1;
	
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			for (int k = 0; k < 21; k++)
			{
				if (Prob[i][j][k] == true)
				{
					Value = S * i + M * j + L * k;
					Count++;
					if (Count == 1) Temp_Result = Value;
					else if (Value != Temp_Result) Temp_Result = -1;
				}
			}
		}
	}
	Ans.push_back(Temp_Result);
}

void Solution()
{
	Count('P');
	for (int i = 1; i < P; i++)
	{
		int Small = 0, Middle = 0, Large = 0;
		for (int j = 0; j < i; j++)
		{
			Small += P_Arr[j][0];
			Middle += P_Arr[j][1];
			Large += P_Arr[j][2];
		}
		Check_Value(Small, Middle, Large, i);
	}

	Ans.push_back(0);
	Count('Q');
	for (int i = 1; i < Q; i++)
	{
		int Small = 0, Middle = 0, Large = 0;
		for (int j = 0; j < i; j++)
		{
			Small += Q_Arr[j][0];
			Middle += Q_Arr[j][1];
			Large += Q_Arr[j][2];
		}
		Find_Answer(Small, Middle, Large);
	}
}

void Solve()
{
	int Tc; cin >> Tc;
	for (int T = 1; T <= Tc; T++)
	{
		Init();
		Input();
		Solution();
		cout << "#" << T << " ";
		for (int i = 0; i < Ans.size(); i++)
		{
			cout << Ans[i] << " ";
		}
		cout << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("Input.txt", "r", stdin);
	Solve();
	return 0;
}

//ref: https://yabmoons.tistory.com/209
