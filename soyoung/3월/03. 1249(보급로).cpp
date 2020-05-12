#include<iostream>
#include<memory.h>
#include<queue>
#include<utility>
using namespace std;

int map[100][100];
int D[100][100];
int dx[4] = {0,-1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int N, MIN;

void restore()
{
	queue<pair<int, int>> q;
	
	D[0][0] = 0;
	q.push(make_pair(0,0));	
	
	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for(int k=0; k<4; k++)
		{
			int a = x + dx[k];
			int b = y + dy[k];

			if(a>=0 && a<N && b>=0 && b<N)
			{
				if(D[a][b] < D[x][y] + map[a][b])
				{
					D[a][b] = D[x][y] + map[a][b];
					q.push(make_pair(a,b));
				}
			}
		}
	}
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		N=0, MIN=987654321;
		cin>>N;

		memset(map, 0, sizeof(map));
		memset(D,9999, sizeof(D));

		for(int a=0; a<N; a++)
		{
			for(int b=0; b<N; b++)
			{
				int deep=0;
				scanf("%1d", &deep);
				map[a][b] = deep;
			}
		}
		
		restore();

		MIN = D[N-1][N-1];

		cout<<"#"<<test_case<<" "<<MIN<<"\n";
	}
	return 0;
}