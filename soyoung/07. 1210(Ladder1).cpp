#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T=10;

	int ans, ex,ey;
	int lad[100][102] = {0};
	int dx[3] = {0,0,-1};
	int dy[3] = {1,-1,0};

	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>test_case;
		for(int i=0; i<100; i++)
		{
			for(int j=1; j<101; j++)
			{
				cin>>lad[i][j];
				if(lad[i][j]==2)
				{
					ex = i;
					ey = j;
				}
			}
		}

		//좌우 확인하고 없으면 위로, 있으면 그 방향으로
		while(ex!=0)
		{
			if(lad[ex+dx[0]][ey+dy[0]] == 1)
			{
				lad[ex][ey] = 2;
				ex += dx[0];
				ey += dy[0];
			}
			else if(lad[ex+dx[1]][ey+dy[1]] == 1)
			{
				lad[ex][ey] = 2;
				ex += dx[1];
				ey += dy[1];
			}
			else
			{
				lad[ex][ey] = 2;
				ex += dx[2];
				ey += dy[2];
			}
		}

		ans = ey-1;

		cout<<"#"<<test_case<<" "<<ans<<"\n";
	}
	return 0;
}