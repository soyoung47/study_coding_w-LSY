//https://www.acmicpc.net/problem/9251
//5980KB, 4ms

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string str1, str2;
	int n1, n2;
	cin >> str1;
	cin >> str2;

	n1 = str1.length();
	n2 = str2.length();

	vector<vector<int>> lcs(n1 + 1, vector<int>(n2 + 1, 0));
	char ch1, ch2;
	for (int i = 1; i <= n1; i++)
	{
		ch1 = str1[i - 1];
		for (int j = 1; j <= n2; j++)
		{
			ch2 = str2[j - 1];

			if (ch1 == ch2)
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
		}
	}

	cout << lcs[n1][n2];
}

//Longest Common Subsequence problem - wikipedia
//https://en.wikipedia.org/wiki/Longest_common_subsequence_problem#:~:text=The%20longest%20common%20subsequence%20(LCS,(often%20just%20two%20sequences).