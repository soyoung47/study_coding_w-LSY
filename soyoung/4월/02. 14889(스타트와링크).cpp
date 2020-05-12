#include<iostream>
#include<memory.h>
#include<vector>
using namespace std;

int S[21][21];
bool check[21];
vector<int> teamA, teamB;
int N, Askill, Bskill, ans;

void team(int index, int cnt)
{
	if(cnt==N/2)
	{
		for(int c=1; c<=N; c++)
		{
			if(check[c])	teamA.push_back(c);
			else	teamB.push_back(c);
		}

		//능력치 계산
		for(int a=0; a<teamA.size(); a++)
		{
			for(int b=0; b<teamA.size(); b++)
			{
				Askill += S[teamA[a]][teamA[b]];
				Bskill += S[teamB[a]][teamB[b]];
			}
		}

		int gab = abs(Askill - Bskill);

		if(ans > gab)
			ans = gab;

		teamA.clear();
		teamB.clear();
		Askill=0;
		Bskill=0;
		
		return;
	}

	for(int p=index; p<=N; p++)
	{
		if(check[p])	continue;
		check[p] = true;
		
		team(p, cnt+1);
		check[p] = false;
	}
}
int main()
{
	cin>>N;

	Askill=0, Bskill=0, ans=9999999;
	memset(S, 0, sizeof(S));
	memset(check, false, sizeof(check));
	teamA.clear();
	teamB.clear();

	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
			cin>>S[i][j];
	}

	team(1,0);

	cout<<ans;

	return 0; 
}