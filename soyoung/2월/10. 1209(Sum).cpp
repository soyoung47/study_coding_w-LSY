#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T=10, max=0, data=0;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>test_case;
		
		int sum[202] = {0};
		max=0, data=0;

		for(int j=0; j<100; j++)
		{
			for(int i=0; i<100; i++)
			{
				cin>>data;

				sum[i+1] += data;
				sum[j+101] += data;

				if(i==j)	sum[0] += data;
				if(i+j==100)	sum[201] += data;
			}
		}

		for(int k=0; k<202; k++)
		{
			if(sum[k] > max)
				max = sum[k];
		}
		
		cout<<"#"<<test_case<<" "<<max<<"\n";
	}
	return 0;
}