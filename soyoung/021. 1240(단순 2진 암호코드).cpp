#include<iostream>
#include<string>
using namespace std;

int pw[8] = {0};
int checkCode(string str)
{
	if(str=="0001101")	return 0;
	else if(str=="0011001")	return 1;
	else if(str=="0010011")	return 2;
	else if(str=="0111101")	return 3;
	else if(str=="0100011")	return 4;
	else if(str=="0110001")	return 5;
	else if(str=="0101111")	return 6;
	else if(str=="0111011")	return 7;
	else if(str=="0110111")	return 8;
	else	return 9;
}
int checkOK()
{
	int a=0, b=0, c=0;
	for(int i=0; i<7; i++)
	{
		if(i%2 == 0)
			a += pw[i];
		else
			b += pw[i];
	}
	c = pw[7];

	if((3*a+b+c)%10==0)	return a+b+c;
	else return 0;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int ans, x, y, n, m, z;

		scanf("%d%d ", &n, &m);
		char arr[50][100] = {"\0"};
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				scanf("%c ", &arr[i][j]);
				if(arr[i][j]=='1'){	x=i;	y=j;}
			}
		}
		
		//코드 나눠서 숫자 확인하기
		for(int k=7; k>-1; k--)
		{
			string pwCode = "";
			for(int l=6; l>-1; l--)
				pwCode.push_back(arr[x][y-7*k-l]);
			pw[7-k] = checkCode(pwCode);
		}

		ans = checkOK();
		cout<<"#"<<test_case<<" "<<ans<<"\n";
	}
	return 0;
}