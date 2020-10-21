#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T=10;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>test_case;

		int pw[8]={0};
		for(int i=0; i<8; i++)
			cin>>pw[i];

		//ªÁ¿Ã≈¨
		int cnt=1;
		int temp = 0;
		while(true)
		{
			temp = pw[0] - cnt;

			for(int j=0; j<7; j++)
				pw[j] = pw[j+1];

			if(temp>0)
				pw[7] = temp;
			else
			{
				pw[7] = 0;
				break;
			}

			if(cnt<5)
				cnt++;
			else
				cnt=1;
		}

		cout<<"#"<<test_case<<" ";
		for(int k=0; k<8; k++)
			cout<<pw[k]<<" ";
		cout<<"\n";
	}
	return 0;
}