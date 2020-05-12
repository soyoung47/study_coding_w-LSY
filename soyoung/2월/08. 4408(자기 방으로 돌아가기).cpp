#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	
	int N, cnt, now, move;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>N;
		int cor[200]={0}, cnt=0;
		for(int k=0; k<N; k++)
		{
			cin>>now>>move;
			if(now > move)
			{
				int tmp = now;
				now = move;
				move = tmp;
			}

			if(now%2==0)
				now = now/2 -1;
			else
				now /= 2;

			if(move%2==0)
				move = move/2-1;
			else
				move/=2;

			for(int i=now; i<=move; i++)
				cor[i]++;
		}

		for(int j=0; j<200; j++)
		{
			if(cor[j] > cnt)
				cnt = cor[j];
		}

		cout<<"#"<<test_case<<" "<<cnt<<"\n";

	}
	return 0;
}