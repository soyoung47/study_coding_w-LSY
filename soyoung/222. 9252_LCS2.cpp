//https://www.acmicpc.net/problem/9252
//174976KB, 292ms

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string max(string a, string b)
{
	if (a.length() > b.length())
		return a;
	else
		return b;
}

int main()
{
	string str1, str2;
	int n1, n2;
	cin >> str1;
	cin >> str2;

	n1 = str1.length();
	n2 = str2.length();

	vector<vector<string>> ans(n1 + 1, vector<string>(n2 + 1, ""));
	char ch1, ch2;
	for (int i = 1; i <= n1; i++)
	{
		ch1 = str1[i - 1];
		
		for (int j = 1; j <= n2; j++)
		{
			ch2 = str2[j - 1];

			if (ch1 == ch2)
				ans[i][j] = ans[i - 1][j - 1] + ch2;
			else
				ans[i][j] = max(ans[i - 1][j], ans[i][j - 1]);
		}
	}

	cout << ans[n1][n2].length() << "\n";
	
	if (!ans[n1][n2].empty())
		cout << ans[n1][n2];
}