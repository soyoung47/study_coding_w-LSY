#include<iostream>

using namespace std;
char box[8][8];
int n;

int find()
{
	int cnt=0;

	if(n>1)
	{
		for(int a=0; a<8; a++)
		{
			for(int b=0; b<8-n+1; b++)
			{
				bool flag = true;
				for(int k=0; k<n/2; k++)
				{
					if(box[a][b+k] != box[a][b+n-1-k])
					{	
						flag = false;	break;
					}
				}
				if(flag==true)	cnt++;

				flag = true;
				for(int l=0; l<n/2; l++)
				{
					if(box[b+l][a] != box[b+n-1-l][a])
					{	
						flag = false;	break;
					}
				}
				if(flag==true)	cnt++;
			}
		}
	}
	else	cnt=8*8;

	return cnt;
}

int main(int argc, char** argv)
{
	int test_case;
	int T=10;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>n;
		
		for(int i=0; i<8; i++)
		{
			for(int j=0; j<8; j++)
				cin>>box[i][j];
		}

		int ans = find();			

		cout<<"#"<<test_case<<" "<<ans<<"\n";
	}
	return 0;
}