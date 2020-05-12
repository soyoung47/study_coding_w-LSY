#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

bool check[302][302];
char arr[302][302];
int cnt, N, noBomb;
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

void checkBomb(int x, int y, bool first)
{
	if(x>0 && y>0 && x<=N && y<=N)
	{
		if(!check[x][y])
		{
			int bomb=0;
			for(int k=0; k<8; k++)
			{
				if(arr[x+dx[k]][y+dy[k]]=='*')
					bomb++;
			}

			if(bomb==0)
			{
				if(first)
					cnt++;
				
				check[x][y]=true;

				for(int k=0; k<8; k++)
					checkBomb(x+dx[k],y+dy[k], false);
			}
			else if(!first)
			{
				check[x][y]=true;
			}
		}
	}
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("input.txt", "r", stdin);
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		noBomb=0, cnt=0, N=0;
		scanf("%d ", &N);

		memset(check, true, sizeof(check));
		memset(arr, '.', sizeof(arr));

		for(int i=1; i<=N; i++)
		{
			for(int j=1; j<=N; j++)
			{
				scanf("%c ", &arr[i][j]);
				if(arr[i][j]=='.')
				{	
					check[i][j] = false;
				}
			}
		}

		for(int a=1; a<=N; a++)
		{
			for(int b=1; b<=N; b++)
				checkBomb(a, b, true);
		}

		for(int a=1; a<=N; a++)
		{
			for(int b=1; b<=N; b++)
			{
				if(!check[a][b])	noBomb++;
			}
		}

		cout<<"#"<<test_case<<" "<<cnt+noBomb<<"\n";
	}
	return 0;
}