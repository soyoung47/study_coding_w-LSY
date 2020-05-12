#include<iostream>
#include<stack>
using namespace std;

int arr[6] = {0};
void changeArr(int num)
{
	int min=10, max=-1;

	for(int i=0; i<num; i++)
	{

	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T, N, cnt, change, min, max, min_i, max_i, i;

	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cnt=0, min=10, max=-1;
		stack <int>tmp;
		cin>>N>>change;

		while(N>=10)
		{
			tmp.push(N%10);
			N/=10;
		}
		tmp.push(N);

		cnt = tmp.size();

		for(int k; k<cnt; k++)
		{	
			arr[k] = tmp.top();
			tmp.pop();
		}





	}
	return 0;
}