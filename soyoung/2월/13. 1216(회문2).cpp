#include<iostream>

using namespace std;
char box[100][100];

int findMax()
{
	for(int n=100; n>0; n--)
	{
		for(int a=0; a<100; a++)
		{
			for(int b=0; b<100-n+1; b++)
			{
				bool flag = true;
				for(int k=0; k<n/2; k++)
				{
					if(box[a][b+k] != box[a][b+n-1-k])	
					{
						flag=false;
						break;
					}
				}
				if(flag==true)	return n;

				flag=true;
				for(int l=0; l<n/2; l++)
				{
					if(box[b+l][a] != box[b+n-1-l][a])	
					{
						flag=false;
						break;
					}
				}
				if(flag==true)	return n;
			}
		}
	}
}


int main(int argc, char** argv)
{
	int test_case;
	int T=10;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>test_case;
		
		for(int i=0; i<100; i++)
		{
			for(int j=0; j<100; j++)
				cin>>box[i][j];
		}

		int max = findMax();

		cout<<"#"<<test_case<<" "<<max<<"\n";
	}
	return 0;
}