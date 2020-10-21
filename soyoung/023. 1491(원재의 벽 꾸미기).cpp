#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		long long n, a, b, r, c, min=10000000000;
		cin>>n>>a>>b;

		for(int r=1; r<=n; r++)
		{
			for(int c=1; r*c<=n; c++)
			{
				if(r>=c)
				{
					long long num = a*abs(r-c) + b*abs(n-r*c);
					if(num<min)	min = num;
				}
			}
		}
		
		cout<<"#"<<test_case<<" "<<min<<"\n";
	}
	return 0;
}