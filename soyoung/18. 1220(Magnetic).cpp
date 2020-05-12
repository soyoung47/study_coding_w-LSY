#include<iostream>

using namespace std;

int box[100][100];

int deadlockNum()
{
	int cnt = 0;
	for(int j=0; j<100; j++)
	{
		int deadlock = 0;
		for(int i=0; i<100; i++)
		{
			if(box[i][j]==1 && deadlock==0)	deadlock++;
			else if(box[i][j]==2 && deadlock==1)
			{
				deadlock = 0;
				cnt++;
			}
		}
	}
	return cnt;
}
int main(int argc, char** argv)
{
	int test_case;
	int T=10, table;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>table;
		int numT = 0;
		for(int i=0; i<100; i++)
		{
			for(int j=0; j<100; j++)
				cin>>box[i][j];
		}

		int ans = deadlockNum();

		cout<<"#"<<test_case<<" "<<ans<<"\n";
	}
	return 0;
}