#include<iostream>
#include<string>
#include<set>
using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	int T;
	string name;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N = 0, min = 55, max = 0;
		set<string> s[51];
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			cin >> name;

			int size = name.size();
			s[size].insert(name);

			if (min > size)	min = size;
			if (max < size)	max = size;
		}

		cout << "#" << test_case << "\n";

		for (int k = min; k <= max; k++)
		{
			if (s[k].empty())
				continue;

			for (auto j = s[k].begin(); j != s[k].end(); j++)
				cout << *j << "\n";
		}
	}
	return 0;
}