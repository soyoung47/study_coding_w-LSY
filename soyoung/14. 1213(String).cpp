#include<iostream>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T=10, cnt=0;
	string find, sen, tmp;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>test_case;
		cin>>find;
		cin>>sen;

		cnt=0;
		for(int i=0; i<sen.size()-find.size()+1; i++)
		{
			if(sen[i] == find[0])
			{
				tmp = sen.substr(i,find.size());
				if(tmp==find)
				{	cnt++;	i += find.size()-1;	}
			}
		}
		
		cout<<"#"<<test_case<<" "<<cnt<<"\n";
	}
	return 0;
}