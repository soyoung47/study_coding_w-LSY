#include<iostream>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	string test_case_num, num;
	int N;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>test_case_num;
		cin>>N;

		int number[10]= {0};

		for(int i=0; i<N; i++)
		{
			cin>>num;
			if(num=="ZRO")
				number[0]++;
			else if(num=="ONE")
				number[1]++;
			else if(num=="TWO")
				number[2]++;
			else if(num=="THR")
				number[3]++;
			else if(num=="FOR")
				number[4]++;
			else if(num=="FIV")
				number[5]++;
			else if(num=="SIX")
				number[6]++;
			else if(num=="SVN")
				number[7]++;
			else if(num=="EGT")
				number[8]++;
			else if(num=="NIN")
				number[9]++;
		}

		cout<<test_case_num<<"\n";
		for(int i=0; i<number[0]; i++)
			cout<<"ZRO ";
		for(int i=0; i<number[1]; i++)
			cout<<"ONE ";
		for(int i=0; i<number[2]; i++)
			cout<<"TWO ";
		for(int i=0; i<number[3]; i++)
			cout<<"THR ";
		for(int i=0; i<number[4]; i++)
			cout<<"FOR ";
		for(int i=0; i<number[5]; i++)
			cout<<"FIV ";
		for(int i=0; i<number[6]; i++)
			cout<<"SIX ";
		for(int i=0; i<number[7]; i++)
			cout<<"SVN ";
		for(int i=0; i<number[8]; i++)
			cout<<"EGT ";
		for(int i=0; i<number[9]; i++)
			cout<<"NIN ";

		cout<<"\n";
	}
	return 0;
}