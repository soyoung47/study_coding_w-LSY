#include <iostream>
using namespace std;

int main()
{
	char room[101][101] = {'\0'};
	int n=0;
	int cnt_x=0, cnt_y=0;
	bool check = false;

	cin>>n;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cin>>room[i][j];
	}

	//가로
	for(int x=0; x<n; x++)
	{
		check = false;
		for(int y=0; y<n-1; y++)
		{
			if(check && room[x][y+1]=='x')
			{
				check = false;
				continue;
			}
			if(!check && room[x][y]=='.' && room[x][y+1]=='.')
			{
				cnt_x++;
				check = true;
			}
		}
	}
	
	//세로
	for(int x=0; x<n; x++)
	{
		check = false;
		for(int y=0; y<n-1; y++)
		{
			if(check && room[y+1][x]=='x')
			{
				check = false;
				continue;
			}
			if(!check && room[y][x]=='.' && room[y+1][x]=='.')
			{
				cnt_y++;
				check = true;
			}
		}
	}

	cout<<cnt_x<<" "<<cnt_y;

	return 0;
}