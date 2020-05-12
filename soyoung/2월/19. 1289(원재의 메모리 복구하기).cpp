#include<iostream>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		string memory;
		char ch='0';
		int cnt =0;
		
		cin>>memory;

		for(int k=0; k<memory.size(); k++)
		{
			if(memory[k] != ch)
			{
				if(ch=='0')	ch='1';
				else ch='0';
				cnt++;
			}
		}

		cout<<"#"<<test_case<<" "<<cnt<<"\n";
	}
	return 0;
}