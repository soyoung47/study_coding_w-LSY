#include<iostream>
#include<memory.h>
#include<utility>
using namespace std;

int map[16][16];
bool visited[16][16];
pair<int,int> start;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int ans;

void go(pair<int,int> p)
{
	int x = p.first;
	int y = p.second;

	if(map[x][y]==3)
	{	
		ans=1;
		return;
	}

	visited[x][y] = true;

	for(int k=0; k<4; k++)
	{
		int new_x = x+dx[k];
		int new_y = y+dy[k];

		if(new_x>=0 && new_x<16 && new_y>=0 && new_y<16)
		{
			if(!visited[new_x][new_y])
				go(make_pair(new_x,new_y));
		}
	}
	
	return;
}
int main(int argc, char** argv)
{
	int test_case;
	int T=10;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int N=0;
		cin>>N;

		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));
		
		for(int i=0; i<16; i++)
		{
			for(int j=0; j<16; j++)
			{
				scanf("%1d", &map[i][j]);
				if(map[i][j]==1)	visited[i][j] = true;
				if(map[i][j]==2)	start = make_pair(i,j);
			}
		}

		ans=0;
		go(start);

		cout<<"#"<<N<<" "<<ans<<"\n";
	}
	return 0;
}